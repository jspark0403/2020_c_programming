#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int a, b, c, d, e, f, a1, a2, a3;
    printf("운동장 3개의 가로, 세로 길이를 순서대로 입력하세요.\n");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    
    a1 = a * b;
    a2 = c * d;
    a3 = e * f;

    printf("가장 큰 넓이는 ");

    if (a1 >= a2 && a1 >= a3)
        printf("%d", a1);
    else if (a2 >= a1 && a2 >= a3)
        printf("%d", a2);
    else
        printf("%d", a3);

    printf(" 입니다.");
}