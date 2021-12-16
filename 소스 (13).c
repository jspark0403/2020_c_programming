#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int f(int n) {
//    if (n == 1)
//        return 1;
//    else
//        return f(n - 1) * n;
//}
//void main() {
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", f(n));
//}

char star[20];
int f(int n) {
    if (n > 0) {
        f(n - 1);
        star[n] = '*';
        printf("%s\n", star + 1);
    }
}
void main() {
    int n;
    scanf("%d", &n);
    f(n);
}
