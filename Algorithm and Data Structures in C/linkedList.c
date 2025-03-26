#include <stdlib.h>
#include "list.h"

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
