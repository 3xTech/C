// Real Node Swap the latter is about turning string into Linked list!
#include <stdio.h>
struct Node {
  struct Node *next;
};

struct Node *swap_node_pairs (struct Node *head)
{
  struct Node* cun = head;
  struct Node* pre = head;
  int i = 0;
  while(cun != NULL && cun->next != NULL){
       struct Node *t = cun->next;
       struct Node *t2 = t->next;
       t->next = cun;
       if(i > 0){
         pre->next = t;
       }
       if(i == 0){
          head = t;
       }
       cun->next = t2;
       pre = cun;
       cun = t2;
       i++;
  }
  return head;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// "Preloaded Code" (do NOT modify!)
typedef struct node {
  int data;
  struct node *next;
} Node;

// Main Solution
char *stringify(Node *list) {
  // TODO: Return a string representation of the linked list provided
  char *fs = (char *)malloc(5000 * sizeof(char)); 
  char *cur = fs;
  while(list != NULL){
       int len = sprintf(cur, "%d", list->data);
       cur += len;
       if(list != NULL){
          strcpy(cur, " -> ");
          cur += 4;
       }
       list = list->next;
  }
  strcpy(cur, "NULL");
  return fs;
}

int main()
{
	
}