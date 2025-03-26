#include <stdio.h>
#define MAX 100


struct Stack{
    int top;
    int arr[MAX];
};


void stack_Init(struct Stack *stack){
                    stack->top = -1;
}


int is_full(struct Stack *stack){
      return stack->top == MAX - 1;
}

int is_empty(struct Stack *stack){
      return stack->top == -1;
}

void push(struct Stack *stack, int data){
    if(is_full(stack)){
             printf("Full\n");
    }
    stack->arr[++stack->top] = data;
    printf("Pushed!!!\n");
}


int pop(struct Stack *stack){
      if(is_empty(stack)){
           printf("Underflow\n");
      }
      return stack->arr[stack->top--];
}


int peek(struct Stack *stack){
      return stack->arr[stack->top];
}

int main(void){
    struct Stack myStack;
    stack_Init(&myStack);

    push(&myStack, 2); 
    push(&myStack, 4);
    push(&myStack, 6);
    push(&myStack, 8);


    while(myStack.top != -1){
          printf("Data %d\n", pop(&myStack));
    }


    return 0;
}