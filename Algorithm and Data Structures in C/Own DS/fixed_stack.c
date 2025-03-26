#include <stdio.h>
#include <stdlib.h>

#define MAX


typedef struct Stack_{
         int top;
         int el[MAX];
}Stack;

void stk_init(Stack *stack)
{
        stack->top = -1;
}

int is_full(Stack *stack)
{
      return (stack->top == MAX - 1);
}

int is_empty(Stack *stack)
{
    return (stack->top == -1);
}

void push(Stack *stack, const int data)
{
       stack->el[++stack->top] = data;
}

int pop(Stack *stack)
{
       return stack->el[stack->top--];
}


int main()
{
   Stack myStack;
   stk_init(&myStack);

  
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    push(&myStack, 4);

    printf("Size: %d\n", myStack.top+1);

    while(myStack.top != -1)
    {
             printf("Data : %d, %d\n", pop(&myStack), myStack.top);
    }





    return 0;
}

