#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS


/*

void sub(int b[], int n);
void main() {
    int a[3] = { 1,2,3 };

    sub(a, 3);
    printf("%d %d %d\n", a[0], a[1], a[2]);
}
void sub(int b[], int n) {
    b[0] = 4;
    b[1] = 5;
    b[2] = 6;
}

*/

int i;

int main() {
    int a[5];
    for (i = 0; i < 5; i++) {
        scanf_s("%d", &a[i]);
    }
    
    return 0;
}

void judge(int a[]) {
    for (i = 0; i < 5; i++) {
        if (a[i] >= 70)
            printf("i ");
    }
}