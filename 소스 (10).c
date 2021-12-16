#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {
    srand(time(NULL));
    int i;

    for (i = 0; i < 6; i++)
        printf("%d\t", rand());

    return 0;
}