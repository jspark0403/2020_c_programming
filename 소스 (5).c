#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct {
    int max;
    int ptr;
    int* que;
    int front;
    int rear;
}IntQueue;

int Initialize(IntQueue* q, int max);
int Push(IntQueue* q, int x);
int Pop(IntQueue* q, int* x);
int Peek(const IntQueue* q, int* x);
void Clear(const IntQueue* q);
int Capacity(const IntQueue* q);
int Size(const IntQueue* q);
int IsEmpty(const IntQueue* q);
int IsFull(const IntQueue* q);
int Search(const IntQueue* q, int x);
void Print(const IntQueue* q);
void Terminate(IntQueue* q);


int main() {
    IntQueue que;

    if (Initialize(&que, 64) == -1) {
        printf("생성 실패");

        return 1;
    }
    while (1) {
        int menu, x;

        printf("현재 데이터 수 : %d / %d \n", Size(&que), Capacity(&que));
        printf("(1)Enqueue (2)Dequeue (3)Peek (4)Print (5)Search (0)Terminate : ");
        scanf("%d", &menu);

        if (menu == 0)
            break;
        switch (menu) {
        case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            if (Enqueue(&que, x) == -1)
                printf("인큐 실패");
            printf("\n");
            break;
        case 2:
            if (Dequeue(&que, &x) == -1)
                printf("디큐 실패");
            else
                printf("Dequeue한 Data는 %d입니다.\n\n", x);
            break;
        case 3:
            if (peek(&que, &x) == -1)
                printf("Peek 실패\n");
            else
                printf("Peek한 Data는 &d입니다.\n\n", x);
            break;
   
        case 4:
            Print(&que);
            break;

        case 5:
            printf("찾고자 하는 값을 입력하시오 :");
            scanf("%d", &x);
            Search(&que, x);
            }
        }
    Terminate(&que);
    }

int Initialize(IntQueue* q, int max) {
    q->ptr = q->front = q->rear = 0;

    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enqueue(IntQueue* q, int x) {//int Push(IntStack* s, int x)
    if (q->ptr >= q->max)
        return -1;
    else {
        q->ptr++;
        q->que[q->rear++] = x;

        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

int Dequeue(IntQueue* q, int* x) {
    if (q->ptr <= 0)
        return -1;
    else {
        q->ptr--;
        *x = q->que[q->front++];

        if (q->front == q->max)
            q->front = 0;

        return 0;
    }
}

int peek(const IntQueue* q, int* x) {
    if (q->ptr <= 0)
        return -1;
    *x = q->que[q->front];

    return 0;
}

void Clear(IntQueue* q) {
    q->ptr = q->front = q->rear = 0;
}

int Capacity(const IntQueue* q) {
    return q->max;
}

int Size(const IntQueue* q) {
    return q->ptr;
}

int IsEmpty(const IntQueue* q) {
    return q->ptr <= 0;
}

int IsFull(const IntQueue* q) {
    return q->ptr >= q->max;
}

int Search(const IntQueue* q, int x) {
    int i, idx;
    for (i = 0; i < q->ptr; i++) {
        if (q->que[idx = (i + q->front) % q->max] == x)
            return printf("%d번 인덱스에 존재함\n\n", idx);
    }
    return -1;
}

void Print(const IntQueue* q) {
    int i;
    for (i = 0; i < q->ptr; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    printf("\n");
}

void Terminate(IntQueue* q) {
    if (q->que != NULL)
        free(q->que);
    q->max = q->ptr = q->front = q->rear = 0;
}
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
// 집가고싶다
typedef struct
{
  int item;
  struct StackNode *link;
} StackNode;

typedef struct
{
  StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
  s->top = NULL;
}

int is_empty(LinkedStackType *s)
{
  return (s->top == NULL);
}

void push(LinkedStackType *s, int item)
{
  StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
  if (temp == NULL)
  {
    fprintf(stderr, "메모리 할당 에러\n");
    return;
  }
  else
  {
    temp->item = item;
    temp->link = s->top;
    s->top = temp;
  }
}

int pop(LinkedStackType *s)
{
  if (is_empty(s))
  {
    fprintf(stderr, "스택이 비어있음\n");
    exit(1);
  }

  else
  {
    StackNode *temp = s->top;
    int item = temp->item;
    s->top = s->top->link;
    free(temp);
    return item;
  }
}

int peek(LinkedStackType *s)
{
  if (is_empty(s))
  {
    fprintf(stderr, "스택이 비어있음\n");
    exit(1);
  }
  else
  {
    return s->top->item;
  }
}

int prec(char op)
{
  switch (op)
  {
  case '(':
  case ')':
    return 0;
  case '+':
  case '-':
    return 0;
  case '*':
  case '/':
    return 0;
  }
  return -1;
}

void infix_to_postfix(char exp[], char str[])
{
  int i = 0, k = 0;
  char ch, top_op;
  int len = strlen(exp);
  StackNode *s;

  init(&s);
  for (i = 0; i < len; i++)
  {
    ch = exp[i];
    switch (ch)
    {
    case '+':
    case '-':
    case '/':
    case ' *':
      while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
      {
        str[k++] = pop(&s);
      }
      push(&s, ch);
      break;
    case '(':
      push(&s, ch);
      break;
    case ')':
      top_op = pop(&s);
      while (top_op != '(')
      {
        str[k++] = top_op;
        top_op = pop(&s);
      }
      break;
    default:
      str[k++] = ch;
      break;
    }
  }
  while (!is_empty(&s))
  {
    str[k++] = pop(&s);
  }
}

int eval(char exp[])
{
  int op1, op2, value, i = 0;
  char ch;
  StackNode *s;

  init(&s);
  for (i = 0; exp[i] != '\n'; i++)
  {
    printf("\nDEV : %c \n", exp[i]);
    ch = exp[i];
    if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
    {
      value = ch - '0';
      push(&s, value);
    }
    else
    {
      op2 = pop(&s);
      op1 = pop(&s);
      switch (ch)
      {
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

int main()
{
  char *data;
  char str[100];
  int result;
  int i = 0;
  data = (char *)calloc(100, sizeof(int));
  printf("후위표현식으로 바꿀 중위식을 입력하세요 : ");
  gets(data);

  infix_to_postfix(data, str);

  printf("\n%s\n", str);
  for (i = 0; str[i] != '\0'; i++)
    printf("str[%d] = %c\n", i, str[i]);
  result = eval(str);
  printf("\n계산결과 : %d\n", result);
  return 0;
}