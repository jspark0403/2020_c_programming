#define STACK_SIZE 5 // STACK_SIZE ����
typedef int element; //element�� type�� int�� ����?
element stack[STACK_SIZE]; // 5��¥�� ������ ������
int top = -1; // top�� -1�� �ʱ�ȭ.

void push(element item) {
    if (top >= STACK_SIZE - 1) {
        // top�� ���û������ 5-1(4)���� ũ�� �ȵ�.
        //�迭�̱� ������ 0���� 4������, 4���ʹ� full
        printf("Stack is full\n");
    }
    else {
        stack[++top] = item;
        //Stack�� ������ �ִ� �����̹Ƿ� top ����, item ����
    }
}
element pop() {
    if (top == -1)
        printf("Empty\n");
    else
        return stack[top--]; // top�� �Ű����� item ����.

}

element peek() {
    if (top == -1)
        printf("Stack is full\n");
    else
        return stack[top];
    //���� �ֱ� item ��ȯ�̱� ������ top�� ����x
}

