#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int a, b, c, d, e, f, a1, a2, a3;
    printf("��� 3���� ����, ���� ���̸� ������� �Է��ϼ���.\n");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    a1 = a * b;
    a2 = c * d;
    a3 = e * f;

    printf("���� ū ���̴� ");

    if (a1 >= a2 && a1 >= a3)
        printf("%d", a1);
    else if (a2 >= a1 && a2 >= a3)
        printf("%d", a2);
    else
        printf("%d", a3);

    printf(" �Դϴ�.");
}