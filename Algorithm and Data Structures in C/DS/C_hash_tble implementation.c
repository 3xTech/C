#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Node
typedef struct ListElmt_{
     int data;
     struct ListElmt_ *next;
} ListElmt;


// List
typedef struct List_{
     ListElmt *head;
     ListElmt *tail;
     int size;
     void (* destroy) (void *data);
} List;

// Initialize the linked list
void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

// Destroy the linked list
void list_destroy(List *list) {
    void *data;
    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }
}

// Insert an element after a specified element
int list_ins_next(List *list, ListElmt *element, const void *data) {
    ListElmt *new_element;
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL) return -1;

    new_element->data = (void *)data;

    if (element == NULL) {
        if (list_size(list) == 0) {
            list->tail = new_element;
        }
        new_element->next = list->head;
        list->head = new_element;
    } else {
        if (element->next == NULL) {
            list->tail = new_element;
        }
        new_element->next = element->next;
        element->next = new_element;
    }
    list->size++;
    return 0;
}

// Remove the element after a specified element
int list_rem_next(List *list, ListElmt *element, void **data) {
    ListElmt *old_element;

    if (list_size(list) == 0) return -1;

    if (element == NULL) {
        *data = list->head->data;
        old_element = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    } else {
        if (element->next == NULL) return -1;

        *data = element->next->data;
        old_element = element->next;
        element->next = element->next->next;

        if (element->next == NULL) {
            list->tail = element;
        }
    }
    free(old_element);
    list->size--;
    return 0;
}

// Return the head of the list
ListElmt *list_head(const List *list) {
    return list->head;
}

// Return the next element in the list
ListElmt *list_next(const ListElmt *element) {
    return element->next;
}

// Return the data stored in an element
void *list_data(const ListElmt *element) {
    return element->data;
}

// Return the size of the list
int list_size(const List *list) {
    return list->size;
}













// C H-table structure
typedef struct CHT_{
         int buckets;
         int size;
         int (*h)(const void *key);
         int (*match) (const void * key1, const void *key2);
         void (*destroy)(void *data);
         List *table;
} CHT;

// Init 
int CHT_init(CHT *cht,int buckets,int (*h)(const void *key),int (*match)(const void *key1, const void *key2),void (*destroy)(void *data))
{

        if((cht->table = (List *)malloc(buckets * sizeof(List))) == NULL)
        {
             return -1;
        }
        cht->buckets = buckets;

        for(int i=0;i<cht->buckets;i++)
        {
               list_init(&cht->table[i], destroy);
        }
        
        cht->h = h;
        cht->match = match;
        cht->destroy = destroy;
        cht->size = 0;

        return 0;
}


// Destroy

void CHT_destroy(CHT *cht)
{
        
       for(int i = 0; i<cht->buckets; i++)
       {
                 list_destroy(&cht->table[i]);
       }

       free(cht->table);
       memset(cht,0,sizeof(CHT));

}

//Lookup
int CHT_lookup(CHT *cht, void **data)
{
                    ListElmt *node;
                    int bucket;

                    bucket = cht->h(*data) % cht->buckets;

                    for(node = list_head(&cht->table[bucket]);node != NULL;node = list_next(node))
                    {
                            if(cht->match(*data, list_data(node)))
                            {
                                 *data = list_data(node);
                                return 0;
                            }
                    }
                   return -1;
}

//Insertion
int CHT_insert(CHT *cht, const void *data)
{
              void *tmp;
              int bucket;
              int retval;

              tmp = (void *)data;
              if(CHT_lookup(cht, &tmp) == 0)
                      return -1;

              bucket = cht->h(data) % cht->buckets;
              if((retval = list_ins_next(&cht->table[bucket], NULL, data)) == 0)
                      cht->size++;

              return retval;
}

// Remove
int CHT_rmve(CHT *cht, void **data)
{
                ListElmt *node, *prev = NULL;
                int bucket;

                bucket = cht->h(*data) % cht->buckets;

                for(node = list_head(&cht->table[bucket]); node != NULL; node = list_next(node))
                {
                          if(cht->match(*data, list_data(node)))
                          {
                                   if(list_rem_next(&cht->table[bucket], prev, data) == 0)
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

// Hash Func

int hash_func(const void *key)
{
       return *((int *)key);
}

// Match

int match_func(const void *key1, const void *key2)
{
        return *((int *)key1) == *((int *)key2);
}


//Destroy
void destroy_func(void *data)
{
      free(data);
}


int main()
{
        CHT myCht;
        int *data, *look_data;
        int i;

        CHT_init(&myCht, 11, hash_func, match_func, destroy_func);

        for(i = 0; i<20;i++)
        {
               data = (int *)malloc(sizeof(int));
               *data = i;
               CHT_insert(&myCht, data);

        }
        look_data = (int *)malloc(sizeof(int));
        *look_data = 5;
          
        if(CHT_lookup(&myCht, (void **)&look_data) == 0)
        {
                  printf("FOUND!!!! %d\n", *look_data);
        }
        else{
                   printf("Not found!\n");         
        }
       return 0;

}





