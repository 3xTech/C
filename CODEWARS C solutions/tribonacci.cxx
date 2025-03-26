#include <stdlib.h>
#include <stdio.h>

//  return a dynamically allocated `long long` array of results

long long *tribonacci(const long long signature[3], size_t n) {
       if(n==0){
         return NULL;
       }else{
         int f_s = 0; 
         long long * ptr = (long long *) malloc((int) n * sizeof(long long));
         for (int i = 0; i < 3; i++) {
                 *(ptr + i) = *(signature + i);
                 f_s = f_s + (*(signature + i)); 
          }
         *(ptr + 3) = f_s;
         int l = 1;
         int k = 2;
         for (int j = 3; j < ((int)n - 1); j++) {
                 long long k1 = (*(ptr + l)) + (*(ptr + k));
                 *(ptr+(j+1)) = k1  + (*(ptr+j));
                 l++;
                 k++;
              }
        return ptr;
       }
}