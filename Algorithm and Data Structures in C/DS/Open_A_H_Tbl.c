#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct OHT_{
             int size;
             void *vacated;
             int positions;
             int (*h1)(const void *key);
             int (*h2)(const void *key);
             int (*match)(const void *key1, const void *key2);
             void (*destroy)(void *data);
             void **table;
} OHT;

static char vacated_sentinel; // A mark for position

int oht_init(OHT *oht, int positions, int (*h1)(const void *key), int (*h2)(const void *key),int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
            int i;
            if((oht->table = (void **)malloc(positions * sizeof(void *))) == NULL)
            {
                return -1;
            }

            oht->positions = positions;

            for(i = 0; i<oht->positions;i++)
            {
                 oht->table[i] = NULL;
            }
            

            oht->size = 0;
            oht->match = match;
            oht->destroy = destroy;
            oht->h1 = h1;
            oht->h2 = h2;
            
            oht->vacated = &vacated_sentinel;
            return 0;
}


void oht_destroy(OHT *oht)
{
          
          int i;
          if(oht->destroy != NULL)
          {
                 for(i = 0; i<oht->positions; i++)
                 {
                          if(oht->table[i] != NULL && oht->table[i] != oht->vacated)
                          {
                            oht->destroy(oht->table[i]);
                          }
                 }
          }
          free(oht->table);
          memset(oht, 0, sizeof(OHT));
}

int oht_lookup(const OHT *oht, void **data);
int oht_insert(OHT *oht, const void *data)
{
        void *tmp;
        int position, i;

        if(oht->size == oht->positions)
        {
            return -1;
        }
        tmp = (void *)data;
        if(oht_lookup(oht, &tmp) == 0)
        {
            return 1;
        }

        for(i = 0; i < oht->positions; i++)
        {
                position = (oht->h1(data) + (i * oht->h2(data))) % oht->positions;
                if(oht->table[position] == NULL || oht->table[position] == oht->vacated)
                {
                            oht->table[position] = (void *)data;
                            oht->size++;
                            return 0;
                }
        }
        return -1;
}

int oht_remove(OHT *oht, void **data)
{
            int position, i;

            for(i = 0; i<oht->positions; i++)
            {
                     position = (oht->h1(*data) + (i* oht->h2(*data))) % oht->positions;
                     if(oht->table[position] == NULL)
                     { 
                            return -1; //Data not found
                     }
                     else if(oht->match(oht->table[position], *data))
                     {
                            *data = oht->table[position];
                            oht->table[position] = oht->vacated;
                            oht->size--;
                            return 0;
                     }
            }
            return -1;
}


int oht_lookup(const OHT *oht, void **data)
{
          int position, i;

          for(i = 0; i < oht->positions; i++)
          {
                      position = (oht->h1(*data) + (i * oht->h2(*data))) % oht->positions;

                      if(oht->table[position] == NULL)
                      {
                                   return -1;
                      }
                      else if(oht->match(oht->table[position], *data))
                      {
                                   *data = oht->table[position];
                                   return 0;
                      }
          }
          return -1;
}

#define oht_size(oht) ((oht)->size)

int h1(const void *key) 
{       
       return (*(int *)key) % 11;
}

int h2(const void *key) 
{
    return 7 - (*(int *)key % 7); 
}

int match(const void *key1, const void *key2) 
{
    return *(int *)key1 == *(int *)key2;
}

void destroy(void *data) 
{
    free(data); 
}


int main()
{
      OHT myOht;
      int *data, i;

       
      if(oht_init(&myOht, 11, h1, h2 , match, destroy) != 0)
      {
          printf("Failed!!!\n");
          return 1;
      }
     

      for(i = 0; i < 7; i += 2)
      {
          if((data = (int *)malloc(sizeof(int))) == NULL)
               return 1;
          *data = i;
          oht_insert(&myOht, data);
      }
       
      printf("Hash Table Size = %d\n", oht_size(&myOht));

      int key = 5;
      void *l_data = &key;
      if(oht_lookup(&myOht, &l_data) == 0)
      {
                printf("Found data : %d\n", *(int *)l_data);
      }else{
              printf("Not found: %d!!\n", key);
      }
      return 0;
}



