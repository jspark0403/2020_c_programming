/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student
{
    int number;
    char name[20];
    float height;
};
int equal(struct student s1, struct student s2) {//struct student *p1,struct student,*p2
    if (s1.number == s2.number) //p1->number == p2->number
        return 1;
    else
        return 0;
}
void main() {
    struct student a = { 1,"hong",3.8 };
    struct student b = { 2,"kim",4.0 };
    if (equal(a, b) == 1)//&a,&b
        printf("같은 학생");
    else
        printf("다른 학생");
}*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct data {
    int class;
    int sub1;
    int sub2;
    int sub3;
}DATA;

int avg(DATA* p1) {
    return (p1->sub1 + p1->sub2 + p1->sub3) / 3;
}

int main() {
    DATA stud[6];
    int result;

    for (int i = 1; i <= 5; i++) {
        printf("%d번째 학생의 학번을 입력하세요 : ", i); scanf("%d", &stud[i].class);
        printf("국어점수 : "); scanf("%d", &stud[i].sub1);
        printf("영어점수 : "); scanf("%d", &stud[i].sub2);
        printf("수학점수 : "); scanf("%d", &stud[i].sub3);
        result = avg(&stud[i]);
        printf("%d학번 학생의 평균은 %d점입니다.\n\n", stud[i].class, result);
    }
    return 0;
}