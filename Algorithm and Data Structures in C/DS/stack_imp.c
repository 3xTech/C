#include <stdio.h>
#include <stdlib.h>


typedef struct Node_{
        void *data;
        struct Node_ *next;
} Node;

typedef struct List_{
          Node * head;
          int size;
          void (* destroy) (void *data);
} List;

typedef List Stack;

void list_init(List *list, void (*destroy)(void * data)){
                      list->head = NULL;
                      list->size = 0;
                      list->destroy = destroy;
}

int list_rem_next(List *list, Node *node, void **data){
                   if(list->size == 0) return -1;
                   Node *rem;
                   if(node == NULL){
                        *data = list->head->data;
                        rem = list->head;
                        list->head = list->head->next;     
                   }
                   free(rem);
                   list->size--;
                   return 0;
}

void list_rst(List *list){
        list->head = NULL;
        list->size = 0;
}
void list_destroy(List *list){
               void *data;
               while(list->size > 0){
                      if(list_rem_next(list, NULL, &data)== 0 && list->destroy != NULL){
                               list->destroy(data);
                      }

               }
               list_rst(list);
}

int list_ins_next(List *list, Node *node, const void *data){
               Node *new = (Node *) malloc(sizeof(Node));
               if( new == NULL) return -1;
               new->data = (void *) data;

               if(node == NULL){
                       new->next = list->head;
                       list->head = new;
               }
               list->size++;
               return 0;
}


void stack_init(List *list, void (* destroy)(void * data)){
        return list_init(list, destroy);


}

void stack_destroy(List *list){
     return list_destroy(list);
}
int stack_push(List *list, void *data){
        return list_ins_next(list, NULL, data);
}
int stack_pop(List *list, void **data){
        return list_rem_next(list, NULL, data);
}
#define peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define size(stack) ((stack)->size)

int main(void){
         Stack stack;
         stack_init(&stack, free);
        
        int *d1 = (int *)malloc(sizeof(int));
        int *d2 = (int *)malloc(sizeof(int));
        int *d3 = (int *)malloc(sizeof(int));
        int *d4 = (int *)malloc(sizeof(int));

        *d1 = 2;
        *d2 = 4;
        *d3 = 6;
        *d4 = 8;

        stack_push(&stack, d1);
        stack_push(&stack, d2);
        stack_push(&stack, d3);
        stack_push(&stack, d4);
         
        int *data;
        while(size(&stack) > 0){
                   stack_pop(&stack, (void **)&data);
                   printf("Data %d\n", *data);
        }
        stack_destroy(&stack);
        return 0;
}

