#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    int item;
    struct StackNode* link;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackType;

void init(LinkedStackType* s) {
    s->top = NULL;
}

int is_empty(LinkedStackType* s) {
    return (s->top == NULL);
}

void push(LinkedStackType* s, int item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
    if (temp == NULL) {
        fprintf(stderr, "메모리 할당 에러\n");
        return;
    }
    else {
        temp->item = item;
        temp->link = s->top;
        s->top = temp;
    }
}

int pop(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        int item = temp->item;
        s->top = s->top->link;
        free(temp);
        return item;
    }
}

int peek(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        return s->top->item;
    }
}

int prec(char op) {
    switch (op) {
    case '(': case ')':
        return 0;
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[], char str[]) {
    int i = 0, k = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackNode* s;

    init(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {

        case '+': case '-': case '*': case '/':
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                str[k++] = pop(&s);
                //printf("%c", pop(&s));
            }
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while (top_op != '(') {
                str[k++] = top_op;
                //printf("%c",top_op);
                top_op = pop(&s);
            }
            break;
        default:
            str[k++] = ch;
            //printf("%c",ch);
            break;
        }
    }
    while (!is_empty(&s))
    {
        str[k++] = pop(&s);
        //printf("%c",pop(&s));
    }
}

int eval(char exp[]) {
    int op1, op2, value, i = 0;
    char ch;
    StackNode* s;

    init(&s);
    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&s, value);
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char* data;
    char str[100] = { '\0' };
    int result;
    int i = 0;
    data = (char*)calloc(100, sizeof(int));
    printf("후위 표현식으로 바꿀 중위 표현식을 입력하세요 : ");
    gets(data);

    infix_to_postfix(data, str);

    printf("\n%s\n", str);
    for (i = 0; str[i] != '\0'; i++) {
        printf("str[%d] = %c\n", i, str[i]);
    }
    result = eval(str);
    printf("\n계산결과 : %d\n", result);

    return 0;

}