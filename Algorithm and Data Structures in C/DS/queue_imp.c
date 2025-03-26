#include <stdio.h>
#include <stdlib.h>


typedef struct Node_{
         void *data;
         struct Node_ *next;
}Node;


typedef struct List_{
          int size;
          Node *head;
          Node *tail;
          void (*destroy) (void *data);
}List;

typedef List Queue;

void list_init(List *list, void (* destroy)(void *data)){
      list->size = 0;
      list->head = NULL;
      list->tail = NULL;
      list->destroy = destroy;
}


void queue_init(List *list, void (* destroy)(void * data)){
            return list_init(list, destroy);
}


int list_rem_next(List *list, Node *node, void **data){
           Node *rem;
           if(list->size == 0) return -1;
           if(node == NULL){
                   *data = list->head->data;
                   rem = list->head;
                   list->head = list->head->next;
                   if(list->size == 1){
                        list->tail = NULL;
                   }
           }
           free(rem);
           list->size--;
           return 0;
}

int queue_dequeue(List *list, void **data){
        return list_rem_next(list, NULL,data);

}
void list_reset(List *list){
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
}
void list_destroy(List *list){
            void *data;
            while(list->size > 0){
                if(list_rem_next(list, NULL, &data)==0 && list->destroy != NULL){
                    list->destroy(data);
                }
            }
            list_reset(list);
}
void queue_destroy(List *list){
         return list_destroy(list);
}

int list_ins_next(List *list, Node *node, const void *data){
            
           Node *new = (Node *)malloc(sizeof(Node));
           if(new == NULL) return -1;

           new->data = (void *)data;
           new->next = NULL;
           if(node == NULL){
              if(list->size == 0){
                   list->head = new;
                   list->tail = new;
              }else{
                   list->tail->next = new;
                   list->tail = new;
              }
           }
           list->size++;
           return 0;
}

int queue_enqueue(List *list, const void *data){
            return list_ins_next(list, NULL, data);
}

int main(void){
      Queue queue;
      queue_init(&queue, free);

      int *d1 = (int *)malloc(sizeof(int));
      int *d2 = (int *)malloc(sizeof(int));
      int *d3 = (int *)malloc(sizeof(int));
      int *d4 = (int *)malloc(sizeof(int));
      
      *d1 = 2;
      *d2 = 4;
      *d3 = 6;
      *d4 = 8;

      queue_enqueue(&queue, d1);
      queue_enqueue(&queue, d2);
      queue_enqueue(&queue, d3);
      queue_enqueue(&queue, d4);

      int *data;
      while(queue.size > 0){
            queue_dequeue(&queue,(void **)&data);
            printf("Data %d\n", *data);
      }

      queue_destroy(queue);

      return 0;
}