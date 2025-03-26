#include <stdio.h>
#include <stdlib.h>


typedef struct Node_{
                void *data;
                struct Node_ *next;
}Node;


typedef struct List_{
             Node *head;
             Node *tail;
             int size;
             void (* destroy)(void *data);  
}List;

typedef List Stack;

void lk_init(List *lk, void (* destroy)(void *data))
{
          lk->destroy = destroy;
          lk->size = 0;
          lk->head = NULL;
          lk->tail = NULL;
}

void stk_init(Stack *stack, void (* destroy)(void *data))
{
        lk_init(stack, destroy);
}

int lk_rem_nxt(List *lk, Node *node, void **data);

void lk_destroy(List *lk)
{
           void *data;
           while(lk->size > 0)
           {
                     if((lk_rem_nxt(lk,NULL,&data) == 0) &&  lk->destroy != NULL)
                     {
                             lk->destroy(data);
                     }
           }
}

void stk_destroy(Stack *stack)
{
       lk_destroy(stack);
}

int lk_rem_nxt(List *lk, Node *node, void **data)
{
        if(lk->size == 0)   return -1;
        Node *rem;
        if(node == NULL)
        {
             *data = lk->head->data;
             rem = lk->head;
             lk->head = lk->head->next;
             if(lk->size == 1)
             {
                  lk->tail = NULL;
             }
        }
        free(rem);
        lk->size--;
        return 0;
}

int pop(Stack *stack, void **data)
{
       return lk_rem_nxt(stack, NULL, data);
}

int lk_ins_nxt(List *lk, Node *node, const void *data)
{
          Node *new = (Node *) malloc(sizeof(Node));
          if(new == NULL)
                 return -1;
        
          new->data = (void *) data;

          if(node == NULL)
          {
                    if(lk->size == 0)
                    {
                        lk->tail = new;
                    }
                    new->next = lk->head;
                    lk->head = new;
          }
          lk->size++;
          return 0;
}

int push(Stack *stack, const void *data)
{
         return lk_ins_nxt(stack, NULL, data);
}

void destroy(void *data)
{
     free(data);
}
Node * lk_nxt(Node *node)
{
      return node->next;
}
void * lk_data(Node *node)
{
      return node->data;
} 
int lk_size(List *lk)
{
    return lk->size;
}

#define stk_size(stack) lk_size(stack)

int main()
{
    Stack myStack;
    stk_init(&myStack, destroy);


    int *d1 = (int *)malloc(sizeof(int));
    int *d2 = (int *)malloc(sizeof(int));
    int *d3 = (int *)malloc(sizeof(int));
    int *d4 = (int *)malloc(sizeof(int));

    *d1 = 1;
    *d2 = 2;
    *d3 = 3;
    *d4 = 4;

    push(&myStack, (void *)d1);
    push(&myStack, (void *)d2);
    push(&myStack, (void *)d3);
    push(&myStack, (void *)d4);

    void *data;
    printf("Size: %d\n", stk_size(&myStack));
    while(myStack.size > 0)
    {
          pop(&myStack, &data);
          printf("%d\n", *(int *)data);
    }
    




    return 0;
}
