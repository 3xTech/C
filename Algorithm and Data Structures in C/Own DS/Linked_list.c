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



void lk_init(List *lk, void (* destroy)(void *data))
{
          lk->destroy = destroy;
          lk->size = 0;
          lk->head = NULL;
          lk->tail = NULL;
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
        }else{
              if(node->next == NULL)
              {
                    return -1;
              }
              *data = node->next->data;  
              rem = node->next;  
              node->next = node->next->next;
              if(node->next == NULL)
              {
                      lk->tail = node;
              }
        }
        free(rem);
        lk->size--;
        return 0;
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
          }else{
                   if(node->next == NULL)
                   {
                         lk->tail = new;
                   }
                   new->next = node->next;
                   node->next = new;
                   
          }
          lk->size++;
          return 0;
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



int main()
{
   List myList;
   lk_init(&myList, destroy);

   int *d1 = (int *)malloc(sizeof(int));
   int *d2 = (int *)malloc(sizeof(int));
   int *d3 = (int *)malloc(sizeof(int));
   int *d4 = (int *)malloc(sizeof(int));

   *d1 = 2;
   *d2 = 4;
   *d3 = 6;
   *d4 = 8;

    lk_ins_nxt(&myList, NULL, d1);
    lk_ins_nxt(&myList, myList.head, d2);
    lk_ins_nxt(&myList, myList.tail, d3);
    lk_ins_nxt(&myList, myList.tail, d4);

     Node *cur = myList.head;
     while(cur){
             printf("%d\n", *(int *)lk_data(cur));
             cur = lk_nxt(cur);
     }
     printf("Size %d\n", lk_size(&myList));
     lk_destroy(&myList);
     Node *cur2 = myList.head;
     while(cur2){
             printf("%d\n", *(int *)lk_data(cur2));
             cur2 = lk_nxt(cur2);
     }
     printf("Size %d", lk_size(&myList));


    return 0;
}


