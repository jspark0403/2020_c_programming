/*
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
    int s, i;
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a0 = 0;;
    printf("학생 수 입력: ");
    scanf("%d", &s);
    int ar[s];
    for (i = 0; i < s; i++)
        scanf("%d", &ar[i]);
    for (i = 0; i < s; i++) {
        if (ar[i] >= 90)
            a9++;
        else if (ar[i] >= 80)
            a8++;
        else if (ar[i] >= 70)
            a7++;
        else if (ar[i] >= 60)
            a6++;
        else if (ar[i] >= 50)
            a5++;
        else if (ar[i] >= 40)
            a4++;
        else if (ar[i] >= 30)
            a3++;
        else if (ar[i] >= 20)
            a2++;
        else if (ar[i] >= 10)
            a1++;
        else
            a0++;
    }

    printf("-- 점수 분포도 --\n");
    printf("100 ~ 90 : %d\n", a9);
    printf("89 ~ 80 : %d\n", a8);
    printf("79 ~ 70 : %d\n", a7);
    printf("69 ~ 60 : %d\n", a6);
    printf("59 ~ 50 : %d\n", a5);
    printf("49 ~ 40 : %d\n", a4);
    printf("39 ~ 30 : %d\n", a3);
    printf("29 ~ 20 : %d\n", a2);
    printf("19 ~ 10 : %d\n", a1);
    printf("9 ~ 0 : %d\n", a0);


    return 0;
    }
    */

#include<stdio.h>
int main() {
    int *p;
    int a = 10;
    p = &a;
    printf("%d\n", ++*p);
    printf("%d", *p);
}