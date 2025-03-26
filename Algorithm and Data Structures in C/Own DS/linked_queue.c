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

typedef List Queue;


void lk_init(List *lk, void (* destroy)(void *data))
{
          lk->destroy = destroy;
          lk->size = 0;
          lk->head = NULL;
          lk->tail = NULL;
}

void queue_init(Queue *queue, void (*destroy)(void *data))
{
       lk_init(queue, destroy);   
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

void queue_destroy(Queue *queue)
{
        lk_destroy(queue);
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

int dequeue(Queue *queue, void **data)
{
       return lk_rem_nxt(queue, NULL, data);
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
                        lk->head = new;
                    }
                    lk->tail->next = new;
                    lk->tail = new;
                    lk->tail->next = NULL;
          }
          lk->size++;
          return 0;
}

int enqueue(Queue *queue, const void *data)
{
         return lk_ins_nxt(queue, NULL, data);
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

#define queue_size(queue) lk_size(queue)

int main()
{

   Queue myQueue;
   queue_init(&myQueue, destroy);

   int *d1 = (int *)malloc(sizeof(int));
   int *d2 = (int *)malloc(sizeof(int));
   int *d3 = (int *)malloc(sizeof(int));
   int *d4 = (int *)malloc(sizeof(int));

   *d1 = 1;
   *d2 = 2;
   *d3 = 3;
   *d4 = 4;

   printf("Size : %d\n", queue_size(&myQueue));

   enqueue(&myQueue, (void *) d1);
   enqueue(&myQueue, (void *) d2);
   enqueue(&myQueue, (void *) d3);
   enqueue(&myQueue, (void *) d4);

   printf("Size : %d\n", queue_size(&myQueue));

   void *data;
   while(myQueue.size > 0)
   {
        dequeue(&myQueue, &data);
        printf("Data:  %d\n", *(int *)data);
   }


   return 0;
}
