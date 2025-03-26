#include <stdio.h>

#define MAX 100   // Fixed capacity size


struct Stack{
          int top;  // keep track of the el at the top
          int el[MAX];
};


void stack_Init(struct Stack *stack){
           stack->top = -1;   // initialize top to -1 mean the stack is empty
}

int is_full(struct Stack *stack){
         return (stack->top  == MAX - 1);
}

int is_empty(struct Stack *stack){
                return (stack->top == -1);
}


int stack_pop(struct Stack *stack){
           if(is_empty(stack)){
                printf("Stack underflow");
                return -1;
           }
           return stack->el[stack->top--];
}


void stack_push(struct Stack *stack, int data){
            if(is_full(stack)){
                printf("Cannot push! Stack is full!\n");
            }
            stack->el[++stack->top] = data;
            printf("PUSHED!!!!\n");
}

int stack_peek(struct Stack *stack){
            if(is_empty(stack)){
                printf("Stack s empty!!!\n");
            }
             return stack->el[stack->top];
} 


int main(void){
    struct Stack myStack;
    stack_Init(&myStack);

    stack_push(&myStack, 2);
    stack_push(&myStack, 4);
    stack_push(&myStack, 6);
    stack_push(&myStack, 8);
    
    while(myStack.top != -1){
        printf("Data %d\n", stack_pop(&myStack));
    }

    return 0;
}