#ifndef LIST_H
#define LIST_H

// Define the structure for linked list elements
typedef struct ListElmt_ {
    void *data;
    struct ListElmt_ *next;
} ListElmt;

// Define the structure for the linked list
typedef struct List_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    ListElmt *head;
    ListElmt *tail;
} List;

// Function prototypes
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void **data);
ListElmt *list_head(const List *list);
ListElmt *list_next(const ListElmt *element);
void *list_data(const ListElmt *element);
int list_size(const List *list);

#endif
