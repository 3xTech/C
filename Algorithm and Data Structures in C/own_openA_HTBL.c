#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct OHT_{
          int size;
          int positions;
          int (*h1)(void const *key);
          int (*h2)(void const *key);
          int (*match)(const void *key1, const void *key2);
          void (*destroy)(void *data);
          void *vacated;
          void **table;
}OHT;

static char vacated;  // Will use the address of this variable to mark vacated positions


int oht_init(OHT *oht, int positions, int (*h1)(const void *key), int (*h2)(const void *key), int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
              int i;
              oht->positions = positions;
              
              if((oht->table = (void **)malloc(oht->positions * sizeof(void *))) == NULL)
              {
                 return -1;
              }

              for(i = 0; i < oht->positions; i++)
              {
                   oht->table[i] = NULL;
              }

              oht->h1 = h1;
              oht->h2 = h2;
              oht->match = match;
              oht->destroy = destroy;
              oht->size = 0;
              oht->vacated = &vacated;
              return 0;
}

void oht_destroy(OHT *oht)
{
          int i;
          if(oht->destroy != NULL)
          {
                      for(i = 0; i<oht->positions; i++)
                      {
                               if(oht->table[i] != NULL || oht->table[i] != oht->vacated)
                               {
                                    oht->destroy(oht->table[i]);
                               }
                      } 
          }
          free(oht->table);
          memset(oht, 0, sizeof(OHT));
}

int oht_lookup(OHT *oht, void **data);

int oht_insert(OHT *oht, const void *data)
{
       int i, put;
       void *tmp;
       if(oht->size == oht->positions)
       {
         return -1;
       }
       tmp = (void *)data;

       if(oht_lookup(oht, &tmp) == 0)
       {
              return -1;
       }

       for(i = 0; i<oht->positions; i++)
       {
                 put = (oht->h1(data) + (i * oht->h2(data))) % oht->positions;          
                 if(oht->table[put] == NULL || oht->table == oht->vacated)
                 {
                        oht->table[put] = (void *)data;
                        oht->size++;
                        return 0;
                 }
       }
       return -1;
}

int oht_remove(OHT *oht, void **data)
{
        int i, rem;

        for(i = 0; i< oht->positions; i++)
        { 
                rem = (oht->h1(*data) +  (i * oht->h2(*data))) % oht->positions;
                if(oht->table[rem] == NULL)
                {
                     return -1;
                }
                else if(oht->match(oht->table[rem], *data) == 0)
                {
                         *data = oht->table[rem];
                         oht->table[rem] = oht->vacated;
                         oht->size--;
                         return 0;
                }
        }
       return -1;
}

int oht_lookup(OHT *oht, void **data)
{
       int get, i;

       for(i = 0; i< oht->positions; i++)
       {
               get = (oht->h1(*data) + (i * oht->h2(*data))) % oht->positions;
               if(oht->table[get] == NULL)
               {
                    return -1;
               }
               else if(oht->match(oht->table[get], *data))
               {
                    *data = oht->table[get];
                    return 0;
               }
       }
       return -1;
}

int h1(const void *key)
{
       return (*(int *)key);
}

int h2(const void *key)
{
    return 7 - (*(int *)key  % 7);
}

int match(const void *key1, const void *key2)
{
        return (*(int *)key1) == (*(int *) key2);
}

void destroy(void *data)
{
       free(data);
}
#define oht_size(oht)  ((oht)->size)

int main(){
    
    OHT myOHT;
    oht_init(&myOHT, 11, h1, h2, match, destroy);
   
    int i;
    int *data;

    for(i=0; i < 22; i+=2)
    {
          data = (int *)malloc(sizeof(int));
          *data = i;
          printf("Data : %d\n", *data);
          oht_insert(&myOHT, data);
    }
    printf("Open Address Hash Table size = %d\n", oht_size(&myOHT));
    
    int key = 5;
    void *l_data = &key;

    if(oht_lookup(&myOHT, &l_data) == 0)
    {
                printf("Found : %d\n", key);
    }else{
                 printf("Not found!!!!!");
    }





    return 0;
}