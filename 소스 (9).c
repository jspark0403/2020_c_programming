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

    printf("두 개의 정수를 입력하세요 :");
    scnaf("%d %d", &a, &b);
    printf("두 수중 더 큰 수는 %d입니다.\n", get_max(a, b));
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
    //f(&a, &b); // 주소가 넘어간다.
    //printf("%d %d\n", a, b);
    int A[5] = { 66,84,79,93,48 };
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (A[i] > A[j]);
    for (i = 0; i < 5; i++)
        printf("%d\t", A[i]);
}


