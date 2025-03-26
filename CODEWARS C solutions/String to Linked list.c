#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// "Preloaded Code" (do NOT modify!)
typedef struct node {
  int data;
  struct node *next;
} Node;

Node *parse(const char *string) {
    //TODO: return the linked list represented by the provided string
    char *cp = (char *) malloc(strlen(string) +1);
    strcpy(cp, string);
    Node *head = NULL;
    Node *cur = NULL;
    char *tok = strtok(cp, " -> ");
    while(tok != NULL){
      if(strcmp(tok, "NULL")== 0){
         break;
      }
      Node *new = (Node *)malloc(sizeof(Node));
      new->data = atoi(tok);
      new->next = NULL;
      
      if(!head){
         head = new;
      }else{
         cur->next = new;
      }
      cur = new;
      tok = strtok(NULL, " -> ");
    }
  return head;
}