#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare_int(const void *key1, const void *key2)
{
       if(*(int *)key1 < *(int *)key2)
       {
                return -1;
       }
       else if(*(int *)key1 > *(int *)key2)
       { 
               return 1;
       }else{
              return 0;
       }
}


int ins_sort(void *data, int size, int esize, int (* compare)(const void *key1, const void *key2))
{
      char *a = data;
      void *key;
      int i, j;

      key = malloc(sizeof(esize));
      if (key == NULL)  return -1;

      for(j = 1; j < size; j++)
      {
             memcpy(key, &a[j * esize]   ,esize);
             i = j - 1;

             while(i >= 0 && compare(&a[i * esize], key) > 0)
             {
                     memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
                     i--;
             }
             memcpy(&a[(i + 1) * esize], key, esize);
      }
      free(key);
      return 0;
}

int main()
{
   int data[] = {10,7,7,8,3,4,2,0,1};
   int size = sizeof(data) / sizeof(data[0]);
   
   ins_sort(data, size, sizeof(int), compare_int);

   printf("Sorted--------->\n");
   for(int i = 0; i < size; i++)
   {
       printf("%d ", data[i]);
   }
    return 0;
}