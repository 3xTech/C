#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct BTreeN_{
                 void *data;
                 struct BtreeN_ *left;
                 struct BtreeN_ *right;
} BtreeN;

typedef struct BTree_{
                 int size;               
                 BtreeN *root;
                 void (*destroy)(void *data);
}Btree;

#define btree_size(btree) ((btree)->size)
#define  btree_root(btree) ((btree)->root)
#define  btree_left(node) ((node)->left)
#define  btree_right(node) ((node)->right)



void BT_init(Btree *btree, void (*destroy)(void *data))
{
          btree->size = 0;
          btree->root = NULL;
          btree->destroy = destroy;
}
void BT_rem_left(Btree *btree, BtreeN *node);
void BT_destroy(Btree *btree)
{
        BT_rem_left(btree, NULL);
        memset(btree, 0 , sizeof(Btree));
}

int BT_ins_left(Btree *btree, BtreeN *node, const void *data)
{
         BtreeN *new, **position;

         if(node == NULL)
         {
               if(btree_size(btree) > 0)
               {
                    return -1;
               }
               position = &btree->root;
         }else{
               if(btree_left(node) != NULL)
                    return -1;
               position = &node->left;
         }

         if((new = (BtreeN *)malloc(sizeof(BtreeN))) == NULL)
              return -1;
         
         new->data = (void *)data;
         new->left = NULL;
         new->right = NULL;
         *position = new;
         btree->size++;
         return 0; 
}


int BT_ins_right(Btree *btree, BtreeN *node, const void *data)
{
            BtreeN *new, **position;
             
            if(node == NULL)
            {
                  if(btree_size(btree) > 0)
                         return -1;
                  position = &btree->root;
            }else{
                 if(btree_right(node) != NULL)
                      return -1;
                 position = &node->right;
            }

            if((new = (BtreeN *)malloc(sizeof(BtreeN))) == NULL)
                 return -1;


            new->data = (void *)data;
            new->right = NULL;
            new->left = NULL;
            *position = new;
            btree->size++;
            return 0;

}

void BT_rem_left(Btree *btree, BtreeN *node)
{
               BtreeN **position;

               if(btree_size(btree) == 0)
                     return;

               if(node == NULL)
               {
                      position = &btree->root;
               }else{
                     position = &node->left;
               }

               if(*position != NULL)
               {
                              BT_rem_left(btree, *position);
                              BT_rem_right(btree, *position);

                              if(btree->destroy != NULL)
                              {
                                   btree->destroy((*position)->data);
                              }

                              free(*position);
                              *position = NULL;
                              btree->size--;
               }
}


void BT_rem_right(Btree *btree, BtreeN *node)
{
       BtreeN **position;

       if(btree_size(btree) == 0)
       {
          return;
       }
       
       if(node == NULL)
       {
            position = &btree->root;
       }else{
              position = &node->right;
       }

       if(*position != NULL)
       {
                 BT_rem_right(btree, *position);
                 BT_rem_left(btree, *position);

                 if(btree->destroy != NULL)
                 {
                       btree->destroy((*position)->data);
                 }
                  
                 free(*position);
                 *position = NULL;
                 btree->size--;

       }
}


int BT_merge(Btree *merge, Btree *left, Btree *right, const void *data)
{
      BT_init(merge, left->destroy);

      if(BT_ins_left(merge , NULL, data) != 0)
      {
                  BT_destroy(merge);
                  return -1;
      }

      btree_root(merge)->left = btree_root(left);
      btree_root(merge)->right = btree_root(right);

      merge->size = merge->size + btree_size(left) + btree_size(right);

      left->root = NULL;
      left->size = 0;
      right->root = NULL;
      right->size = 0;


     return 0;
}

void destroy(void *data)
{
     free(data);
}



int main()
{
     Btree myBtree;
     BT_init(&myBtree, destroy);
     
     char *data1 = strdup("Root");
     char *data2 = strdup("Right");
     char *data3 = strdup("Left");


     BT_ins_left(&myBtree, NULL, data1);
     BT_ins_left(&myBtree, btree_root(&myBtree), data2);
     BT_ins_right(&myBtree, btree_root(&myBtree), data3);

     printf("Size = %d\n", btree_size(&myBtree));


     return 0;
}