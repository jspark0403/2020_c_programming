#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
void main() {
    int* x;
    x = calloc(1, sizeof(int));

    if (x == NULL)
        printf("�޸� �Ҵ� ����.\n");
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
    
    printf("��� ����:");
    scanf("%d", &na);
    a = calloc(na, sizeof(int));
    
    if (a == NULL)
        printf("�޸� Ȯ�� ����\n");
    else
    {
        printf("%d���� ���� �Է�:", na);
        for (i = 0; i < na; i++) {
            printf("a[%d]:", i);
            scanf("%d", &a[i]);
        }
        print("����� �� ���.\n");
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