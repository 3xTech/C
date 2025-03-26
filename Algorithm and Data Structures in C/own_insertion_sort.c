#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int compare_int(const void *key1, const void *key2)
{
          int d1 =  *(int *) key1;
          int d2 = *(int *) key2;

          if(d1 < d2) return -1;
          else if(d1 > d2) return 1;
          else return 0; 
}




int ins_sort(void *data, int size, int esize, int (* compare)(const void *key1, const void *key2))
{
           char *a = data;
           int i,j;
           void *key;


           if((key = (void *)malloc(esize)) == NULL)
                   return -1;

           for(j = 1; j < size; j++)
           { 
                       memcpy(key, &a[j * esize], esize);
                       i = j-1;

                       while(i >= 0 && compare(&a[i * esize], key) > 0)              
                       { 
                                               memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
                                               i--;
                       } 
                       memcpy(&a[(i + 1) * esize],key, esize);
           }
           free(key);
           return 0;
}



int main()
{ 
    int data[] = {12, 12, 10, 8, 6, 4, 2, 0};
    int size = sizeof(data) / sizeof(data[0]);


    printf("Before sorting----------->:\n");
    for(int i = 0; i<size; i++)
    {
            printf("%d ", data[i]);
    }
    printf("\n");
    
    if(ins_sort(data, size, sizeof(int), compare_int) != 0)
    {
            printf("Insertion sort error!!!!");
    }


    printf("After sorting-------------->:\n");
    for(int i = 0; i< size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
