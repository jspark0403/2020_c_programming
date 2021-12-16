#define STACK_SIZE 5 // STACK_SIZE 정의
typedef int element; //element의 type을 int로 정의?
element stack[STACK_SIZE]; // 5개짜리 스택을 정의함
int top = -1; // top은 -1로 초기화.

void push(element item) {
    if (top >= STACK_SIZE - 1) {
        // top이 스택사이즈면 5-1(4)보다 크면 안됨.
        //배열이기 때문에 0부터 4까지만, 4부터는 full
        printf("Stack is full\n");
    }
    else {
        stack[++top] = item;
        //Stack의 공간이 있는 상태이므로 top 증가, item 대입
    }
}
element pop() {
    if (top == -1)
        printf("Empty\n");
    else
        return stack[top--]; // top이 옮겨지고 item 삭제.

}

element peek() {
    if (top == -1)
        printf("Stack is full\n");
    else
        return stack[top];
    //가장 최근 item 반환이기 떄문에 top의 증감x
}

