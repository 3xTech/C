#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int compare_ints(const void *key1, const void *key2)
{
      int int1 = *(int *)key1;
      int int2 = *(int *)key2;

      if(int1 < int2) return -1;
      else if (int1 > int2)  return 1;
      else return 0;
}



int ins_sort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2))
{ 
         char *a = data;
         void *key;
         int i, j;

         if((key = malloc(esize)) == NULL)
         {  
               return -1;      
         }


         for(j = 1; j<size; j++)
         {
                      memcpy(key , &a[j * esize], esize);
                      i = j - 1;

                      while(i >= 0 && compare(&a[i * esize], key)  > 0)
                      {
                                    memcpy(&a[(i + 1) * esize],  &a[i * esize], esize);
                                    i--;
                      }
                      memcpy(&a[(i + 1) * esize], key, esize);
         }
         free(key);
         return 0;
}

int main()
{
    int data[] = {12, 10, 8, 9, 6,5,3,1,0};
    int size = sizeof(data) / sizeof(data[0]);
    int i;

    printf("Before sorting-----:\n");
    for(i = 0; i<size; i++)
    {
           printf("%d ", data[i]);
    }
    printf("\n");

    if(ins_sort(data, size, sizeof(int), compare_ints) != 0)
    {
           printf("Error------->\n");
    }


    printf("After sorting-----:\n");
    for(i=0; i<size; i++)
    {
              printf("%d ", data[i]);
    }
    printf("\n");


    return 0;
}