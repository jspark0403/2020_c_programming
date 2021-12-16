#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
void main() {
    int* x;
    x = calloc(1, sizeof(int));

    if (x == NULL)
        printf("메모리 할당 실패.\n");
    else {
        *x = 57;
        printf("*x = %d\n, *x");
        free(x);
    }
}
*/


/*
void main() {
    int i;
    int* a;
    int na;
    
    printf("요소 개수:");
    scanf("%d", &na);
    a = calloc(na, sizeof(int));
    
    if (a == NULL)
        printf("메모리 확보 실패\n");
    else
    {
        printf("%d개의 정수 입력:", na);
        for (i = 0; i < na; i++) {
            printf("a[%d]:", i);
            scanf("%d", &a[i]);
        }
        print("요소의 값 출력.\n");
        for (i = 0; i < na; i++)
            printf("a[%d]=%d\n", i, a[i]);
        free(a);
    }
}
*/

struct student {
    int number;
    char name[20];
    double grade;
};
void main() {
    struct student s = { 2020,"jinseong" };
}