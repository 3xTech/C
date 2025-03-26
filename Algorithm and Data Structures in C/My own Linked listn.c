#include <stdio.h>
#include <stdlib.h>


typedef struct Node_{
          void *data;
          struct Node_ *next;
} Node;

typedef struct List_{
          int size;
          Node *head;
          Node *tail;
          void (* destroy)(void *data);
} List;


void list_init(List *list, void (* destroy) (void * data)){
             list->size = 0;
             list->head = NULL;
             list->tail = NULL;
             list->destroy = destroy;

}

int list_rem_next(List *list, Node *node,  void **data){
            if(list->size == 0) return -1;
            Node *rem;
            if(node == NULL){
                  *data = list->head->data;
                  rem = list->head;
                  list->head = list->head->next;
                  if(list->size == 1){
                        list->tail = NULL;
                  }
            }else{
                  if(node->next == NULL) return -1;
                  *data = node->next->data;
                  rem = node->next;
                  node->next = node->next->next;
                  if(node->next == NULL){
                        list->tail = node;
                  }
            }
            free(rem);
            list->size--;
            return 0;
}
void list_rst(List *list){
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
}

void list_destroy(List *list){
        void *data;
        while(list->size > 0){
            if(list_rem_next(list, NULL, &data) == 0 && list->destroy != NULL){
                       list->destroy(data);
            } 
        }
        list_rst(list);
}

int list_ins_next(List *list, Node * node, void *data){
          Node *new = (Node *)malloc(sizeof(Node));
          if(new == NULL) return -1;
          new->data = (void *) data;

          if(node == NULL){
                  if(list->size == 0){
                        list->tail = new;
                  }
                  new->next = list->head;
                  list->head = new;
          }else{
                 if(node->next == NULL){
                          list->tail = new;
                 }
                 new->next = node->next;
                 node->next = new;
          }
         list->size++;
         return 0;
}

int list_size(const List *list){
               return list->size;
 }

 Node * list_head(const List *list){
          return list->head;
 }

Node * list_tail(const List *list){
              return list->tail;
 }

int l_is_head(List *list, const Node *node){
       return (node == list->head ? 1 : 0);
}
int l_is_tail(List *list, const Node *node){
       return (node->next == NULL ? 1 : 0);
}
void * list_data(const Node *node){
      return node->data;
}
Node *list_next(const Node *node){
           return node->next;
}

int main(void){
      List list;
      list_init(&list, free);

      int *d1 = (int *)malloc(sizeof(int));
      *d1 = 2;
      list_ins_next(&list,NULL,d1);
      int *d2 = (int *)malloc(sizeof(int));
      *d2 = 4;
      list_ins_next(&list, list.head, d2);
      int *d3 = (int *)malloc(sizeof(int));
      *d3 = 6;
      list_ins_next(&list, list_tail(&list), d3);
      int *d4 = (int *)malloc(sizeof(int));
      *d4 = 8;
      list_ins_next(&list, list_tail(&list), d4);

      Node *cur = list.head;

      while(cur){
           printf("%d\n", *(int *)list_data(cur));
           cur = list_next(cur);
      }
    
    printf("%d", list_size(&list));

    list_destroy(&list);
    return 0;

}