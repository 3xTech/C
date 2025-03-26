#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
typedef struct Node_{
     void *data;
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

void list_destroy(List *list);

int lst_rem_nxt(List *list,Node *node, void **data){
        if(list->head == 0) return -1;
        Node *rem;
        if(node == NULL){
              *data = (void *) list->head->data;
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
void list_destroy(List *list){
       void *data;
       while(list->size > 0){
          if(lst_rem_nxt(list, NULL, &data) == 0 && list->destroy != NULL){
                        list->destroy(data);
          }
       }
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







typedef struct CHT_{
         int size;
         int buckets;
         void (* destroy)(void *data);
         int (* h)(const void *key);
         int (* match)(const void *key1, const void *key2);
         List *table;   
}CHT;


int CHT_init(CHT *cht,int buckets, void (* destroy)(void * data), int(* h)(const void *key), int(*match)(const void *key1, const void *key2))
{

               if((cht->table = (List *)malloc(buckets * sizeof(List))) == NULL )
                    return -1;

               cht->buckets = buckets;
               for(int i = 0;i<buckets; i++)
               {
                         listInit(&cht->table[i], destroy);
               }

               cht->size = 0;
               cht->h = h;
               cht->match = match;
               cht->destroy = destroy;
               return 0;
}


void CHT_destroy(CHT *cht)
{
               
            for(int i =0;i<cht->buckets;i++)
            {
                   list_destroy(&cht->table[i]);

            }

            free(cht->table);
            memset(cht, 0, sizeof(CHT));
}

int CHT_lookup(CHT *cht, void **data)
{
        Node *node;
        int bucket;

        bucket = cht->h(*data) % cht->buckets;

        for(node = list_head(&cht->table[bucket]); node != NULL; node = list_next(node))
        {
                      if(cht->match(*data,  list_data(node)))
                      {
                                   *data = list_data(node);
                                   return 0;
                      }
        }
        return -1;
}


int CHT_insert(CHT *cht, const void *data)
{ 
                void *tmp;
                int retval, bucket;
                tmp = (void *)data;

                if(CHT_lookup(cht, &tmp) == 0)
                   return -1;

                bucket = cht->h(data) % cht->buckets;

                if((retval = lst_ins_next(&cht->table[bucket], NULL, data) == 0))
                {
                           cht->size++;     
                }
                return retval;
}


int CHT_remove(CHT *cht, void **data)
{
               
            Node *node, *prev = NULL;
            int bucket = cht->h(*data) % cht->buckets;

            for(node = list_head(&cht->table[bucket]); node != NULL; node = list_next(node))
            {
                if(cht->match(*data, list_data(node)))
                {
                      if(lst_rem_nxt(&cht->table[bucket], prev, data) == 0)
                      {
                            cht->size--;
                            return 0;
                      }else{
                            return -1;
                      }
                }    
                prev = node;
            }
            return -1;
}

int hash_funct(const void *key)
{
    return *((int *) key);
}

int match(const void *key1, const void *key2)
{
                 return *((int *)key1) == *((int *)key2);
}

void destroy(void *data)
{
    free(data);
}


int main()
{
        CHT myCht;
        int *data, *look_data;
        int i;

        CHT_init(&myCht, 11, destroy, hash_funct, match);

        for(i = 2; i<20;i+= 2)
        {
               data = (int *)malloc(sizeof(int));
               *data = i;
               printf("data %d and i = %d\n", *data, i);
               CHT_insert(&myCht, data);

        }
        look_data = (int *)malloc(sizeof(int));
        *look_data = 5;

        /*for(int i = 0;i<20;i++){
               CHT_lookup(&myCht, (void **)&look_data);
               printf()
        }*/
          
        if(CHT_lookup(&myCht, (void **)&look_data) == 0)
        {
                  printf("FOUND!!!! %d\n", *look_data);
        }
        else{
                   printf("Not found!\n");         
        }
        free(look_data);
        CHT_destroy(&myCht);
       return 0;

}