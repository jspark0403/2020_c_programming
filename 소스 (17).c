/*

#include<stdio.h>
struct student {
    int number;
    char name[20];
    double grade;
};

void main() {
    struct student s = { 2020,"jinseong",4.3 };
    struct student* p;

    p = &s;

    printf("%d %s %.1f\n", s.number, s.name, s.grade);
    printf("%d %s %.1f\n", (*p).number, (*p).name, (*p).grade);
    printf("%d %s %.1f\n", p->number, p->name, p->grade);

    //표기 방법만 다르다...

    
}

*/

#include<stdio.h>

void main() {
    auto a;
    a = 3.141592;
    printf("%d", a);
}