#include <stdio.h>
#include <stdlib.h>

// Node
typedef struct Node_{
     int data;
     struct Node_ *next;
} Node;


// List
typedef struct List_{
     Node *head;
     Node *tail;
     int size;
     void (* destroy) (void *data);
} List;


// List init
void listInit(List *list, void (* destroy)(void *data)){
               list->head = NULL;
               list->tail = NULL;
               list->size = 0;
               list->destroy = destroy;
}

void list_destroy(List *list){
       void *data;
       while(list->size > 0){
          if(lst_rem_nxt(list, NULL, &data) == 0 && list->destroy != NULL){
                        list->destroy(data);
          }
       }
}

int lst_rem_nxt(List *list,Node *node, void **data){
        if(list->head == 0) return -1;
        Node *rem;
        if(node == NULL){
              *data = list->head->data;
              // Remove from Head
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

 int lst_ins_next(List *list, Node *node, const void *data){
         Node *newNode = (Node *) malloc(sizeof(Node));
         if(newNode == NULL) return -1;

         newNode->data = (void *) data;
         if(node == NULL){
                 if(list->size == 0){
                    list->tail = newNode;
                 }
                 newNode->next = list->head;
                 list->head = newNode;
         }else{
                if(node->next == NULL){
                     list->tail = newNode;
                }
                newNode->next = node->next;
                node->next = newNode;

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
     listInit(&list, free);
     
     int *f_e = (int *) malloc(sizeof(int));
     *f_e = 1;
     lst_ins_next(&list, NULL, f_e);

     int *s_e = (int *)malloc(sizeof(int));
     *s_e = 2;
     lst_ins_next(&list, list.head, s_e);
      
     int *t_e = (int *) malloc(sizeof(int));
     *t_e = 3;
     lst_ins_next(&list, list_tail(&list), t_e);

     Node *cur = list.head;
     while(cur){
             printf("%d\n", *(int *)list_data(cur));
             cur = list_next(cur);
     }
     printf("Size %d", list_size(&list));

}