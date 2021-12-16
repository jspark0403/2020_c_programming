#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100 // �ִ� Queue�� ����� 100���� ����

typedef struct BankCustomer { // ���� ��Ÿ���� ���� ����ü
    int id;
    int tArrival;
    int tService;
} Customer;

typedef Customer Element; // customer�� Ÿ���� Element�� �����Ѵ�.

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
        error("ť ���� ����");
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}

Element peek()
{
    if (is_empty())
        error("ť ���� ����");
    return data[(front + 1) % MAX_QUEUE_SIZE];
}

int nSimulation; // �ùķ��̼� �ð�
double probArrival; // �����ð��� �����ϴ� ��� �� ��
int tMaxService; // �� ���� ���� �ִ� ���� �ð�
int totalWaitTime; // ��ü ��� �ð�
int nCustomers; // ��ü ���� ��
int nServedCustomers; // ���񽺸� ���� ��ü �� ��

double rand0to1() {
    return rand() / (double)RAND_MAX; // RAND_MAX�� rand �Լ��� ��ȯ�� ���� �ִ밪. 
    // rand �߻�. ������ �ִ� rand_max
}

void insert_customer(int arrivalTime) // �� ���� �Լ�.
{
    Customer a;
    a.id = ++nCustomers; // ���� ��ȣ
    a.tArrival = arrivalTime; // ���� ���� �ð�
    a.tService = (int)(tMaxService * rand0to1()) + 1;  // ���� ���� �ð�
    printf("�� %d �湮 (���� �ð� : %d��)\n", a.id, a.tService);
    enqueue(a);
}

void read_sim_params()
{
    printf("�ùķ��̼� �� �ִ� �ð� (��:10) = ");
    scanf("%d", &nSimulation);
    printf("�����ð��� �����ϴ� �� �� (��:0.5) = ");
    scanf("%lf", &probArrival);
    printf("�� ���� ���� �ִ� ���� �ð� (��:5) = ");
    scanf("%d", &tMaxService);
    printf("===============================================\n");
}

void run_simulation()
{
    Customer a;
    int clock = 0; // �ʱ� �ð�
    int serviceTime = -1; // ó�� ���� �ð�

    init_queue(); // ť �ʱ�ȭ
    nCustomers = totalWaitTime = nServedCustomers = 0;  // ��� ���� �ʱ�ȭ
    while (clock < nSimulation) { // ���� �ð��� ��ü �ù����̼� �ð����� ���� ��
        clock++;
        printf("���� �ð� = %d\n", clock);

        if (rand0to1() > probArrival) // ���س��� �����ð����� ������ Ŭ ��
            insert_customer(clock);
        if (serviceTime > 0) // ����Ÿ���� 0���� ũ�� �Ǹ� ���� Ÿ�� ����
            serviceTime--;
        else {
            if (is_empty())
                continue;
            a = dequeue();
            nServedCustomers++;  // ���� ���� �� �� ����
            totalWaitTime += clock - a.tArrival; // ��ü ���ð� += ���� �ð� - ���ð�
            printf("�� %d ���� ����(���ð�:%d��)\n", a.id, clock - a.tArrival);
            serviceTime = a.tService - 1; // ���� �ð��� = ���� ���� �ð�-1 
        }
    }
}

void print_result()
{
    printf("================================================================");
    printf(" ���� ���� ����          = %d\n", nServedCustomers);
    printf(" ��ü ��� �ð�              = %d��\n", totalWaitTime);
    printf(" ���� �� ��� ���ð�    = %-5.2f��\n", (double)totalWaitTime / nServedCustomers);
    printf(" ���� ��� �� ��            = %d\n", nCustomers - nServedCustomers);
}

#include<time.h>
void main()
{
    srand((unsigned int)time(NULL));
    read_sim_params();
    run_simulation();
    print_result();
}