#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*void main() {
    int result;

    result = square(5);
    printf("%d\n", result);

}

    int square(int n) {
        
        return (n * n);
    }
*/



/*
void main() {
    int a,b;

    printf("�� ���� ������ �Է��ϼ��� :");
    scnaf("%d %d", &a, &b);
    printf("�� ���� �� ū ���� %d�Դϴ�.\n", get_max(a, b));
}
int get_max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}
*/


void f(int* a, int* b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void main() {
    //int a, b;
    //scanf("%d %d", &a, &b);
    //f(&a, &b); // �ּҰ� �Ѿ��.
    //printf("%d %d\n", a, b);
    int A[5] = { 66,84,79,93,48 };
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (A[i] > A[j]);
    for (i = 0; i < 5; i++)
        printf("%d\t", A[i]);
}


