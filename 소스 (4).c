#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int max;
    int ptr;
    int* stk;
}IntStack;

int Initialize(IntStack* s, int max);
int Push(IntStack* s, int x);
int Pop(IntStack* s, int* x);
int Peek(const IntStack* s, int* x);
void Clear(IntStack* s);
int Capacity(const IntStack* s);
int Size(const IntStack* s);
int IsEmpty(const IntStack* s);
int IsFull(const IntStack* s);
int Search(const IntStack* s, int x);
void Print(const IntStack* s);
void Terminate(IntStack* s);

void main() {
    IntStack s;
    if (Initialize(&s, 64) == -1) {
        printf("스택 생성 실패\n");
        return 1;
    }

    while (1) {
        int menu, x;
        printf("현재 데이터 수 %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)Push (2) Pop (3)Peek (4)Print (5)Clear (6)Search (7)IsFull/IsEmpty (0)Terminate :");
        scanf("%d", &menu);

        if (menu == 0)
            break;
        switch (menu) {
        case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            printf("\n");
            if (Push(&s, x) == -1)
                printf("오류 : Push 실패\n\n");
            break;
        case 2:
            if (Pop(&s, &x) == -1)
                printf("오류 : Pop 실패\n");
            else
                printf("Peek data는 %d입니다\n\n", x);
            break;
        case 3:
            if (Peek(&s, &x) == -1)
                printf("오류 : Peek 실패\n\n");
            else
                printf("Peek data는 %d입니다\n\n", x);
            break;
        case 4:
            Print(&s);
            printf("\n");
            break;
        case 5:
            Clear(&s);
            printf("\n");
            break;
        case 6:
            printf("찾으려는 data를 입력하시오 :");
            scanf("%d", &x);
            Search(&s, x);
            break;
        case 7:
            //IsFull(&s);
            IsEmpty(&s);
            break;
        }
    }
    Terminate(&s);
}



int Initialize(IntStack* s, int max) {
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack* s, int x) {
    if (s->ptr >= s->max)
        return -1;
    else {
        s->stk[s->ptr] = x;
        s->ptr++;
        return 0;
    }
}

int Pop(IntStack* s, int* x) {
    if (s->ptr <= 0)
        return -1;

    s->ptr--;
    *x = s->stk[s->ptr];

    return 0;
}

int Peek(const IntStack* s, int* x) {
    if (s->ptr <= 0)
        return -1;

    *x = s->stk[s->ptr - 1];

    return 0;
}

void Clear(IntStack* s) {
    s->ptr = 0;
}

int Capacity(const IntStack* s) {
    return s->max;
}

int Size(const IntStack* s) {
    return s->ptr;
}

int IsEmpty(const IntStack* s) {
    if (s->ptr <= 0)
        return printf("스택이 비었습니다.\n\n");
    else
        return printf("스택에 데이터가 들어가 있습니다.\n\n");
}

int IsFull(const IntStack* s) {
    if (s->ptr >= s->max)
        return printf("스택이 가득찼습니다.\n\n");
    else
        return printf("스택의 빈자리가 있습니다.\n\n");
}

int Search(const IntStack* s, int x) {
    int i;
    for (i = s->ptr - 1; i >= 0; i--) {
        if (s->stk[i] == x)
            return printf("%d번 인덱스에 존재함\n\n", i);
    }
    return printf("존재하지 않음\n\n");
}

void Print(const IntStack* s) {
    int i;
    for (i = 0; i < s->ptr; i++) {
        printf("%d ", s->stk[i]);
    }
    printf("\n");
}

void Terminate(IntStack* s) {
    if (s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}
