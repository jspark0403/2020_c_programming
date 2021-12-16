#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100 // 최대 Queue의 사이즈를 100으로 규정

typedef struct BankCustomer { // 고객을 나타내기 위한 구조체
    int id;
    int tArrival;
    int tService;
} Customer;

typedef Customer Element; // customer의 타입을 Element로 규정한다.

Element data[MAX_QUEUE_SIZE];
int front, rear;

void error(char str[]) //const char
{
    printf("%s\n", str);
    exit(1);
}

void init_queue() {
    front = rear = 0;
}

int is_empty() {
    return front == rear;
}
int is_full() {
    return front == (rear + 1) % MAX_QUEUE_SIZE;
}

int size() {
    return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void enqueue(Element val)
{
    if (is_full())
        error("queue error");
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}

Element dequeue()
{
    if (is_empty())
        error("큐 공백 에러");
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}

Element peek()
{
    if (is_empty())
        error("큐 공백 에러");
    return data[(front + 1) % MAX_QUEUE_SIZE];
}

int nSimulation; // 시뮬레이션 시간
double probArrival; // 단위시간에 도착하는 평균 고객 수
int tMaxService; // 한 고객에 대한 최대 서비스 시간
int totalWaitTime; // 전체 대기 시간
int nCustomers; // 전체 고객의 수
int nServedCustomers; // 서비스를 받은 전체 고객 수

double rand0to1() {
    return rand() / (double)RAND_MAX; // RAND_MAX는 rand 함수로 반환될 수의 최대값. 
    // rand 발생. 범위는 최대 rand_max
}

void insert_customer(int arrivalTime) // 고객 입장 함수.
{
    Customer a;
    a.id = ++nCustomers; // 고객의 번호
    a.tArrival = arrivalTime; // 고객의 도착 시간
    a.tService = (int)(tMaxService * rand0to1()) + 1;  // 고객의 서비스 시간
    printf("고객 %d 방문 (서비스 시간 : %d분)\n", a.id, a.tService);
    enqueue(a);
}

void read_sim_params()
{
    printf("시뮬레이션 할 최대 시간 (예:10) = ");
    scanf("%d", &nSimulation);
    printf("단위시간에 도착하는 고객 수 (예:0.5) = ");
    scanf("%lf", &probArrival);
    printf("한 고객에 대한 최대 서비스 시간 (예:5) = ");
    scanf("%d", &tMaxService);
    printf("===============================================\n");
}

void run_simulation()
{
    Customer a;
    int clock = 0; // 초기 시간
    int serviceTime = -1; // 처음 서비스 시간

    init_queue(); // 큐 초기화
    nCustomers = totalWaitTime = nServedCustomers = 0;  // 모든 변수 초기화
    while (clock < nSimulation) { // 현재 시각이 전체 시물레이션 시간보다 적을 때
        clock++;
        printf("현재 시각 = %d\n", clock);

        if (rand0to1() > probArrival) // 정해놓은 단위시간보다 랜덤이 클 때
            insert_customer(clock);
        if (serviceTime > 0) // 서비스타임이 0보다 크게 되면 서비스 타임 감소
            serviceTime--;
        else {
            if (is_empty())
                continue;
            a = dequeue();
            nServedCustomers++;  // 서비스 받은 고객 수 증가
            totalWaitTime += clock - a.tArrival; // 전체 대기시간 += 현재 시각 - 대기시간
            printf("고객 %d 서비스 시작(대기시간:%d분)\n", a.id, clock - a.tArrival);
            serviceTime = a.tService - 1; // 서비스 시간은 = 서비스 시작 시간-1 
        }
    }
}

void print_result()
{
    printf("================================================================");
    printf(" 서비스 받은 고객수          = %d\n", nServedCustomers);
    printf(" 전체 대기 시간              = %d분\n", totalWaitTime);
    printf(" 서비스 고객 평균 대기시간    = %-5.2f분\n", (double)totalWaitTime / nServedCustomers);
    printf(" 현재 대기 고객 수            = %d\n", nCustomers - nServedCustomers);
}

#include<time.h>
void main()
{
    srand((unsigned int)time(NULL));
    read_sim_params();
    run_simulation();
    print_result();
}