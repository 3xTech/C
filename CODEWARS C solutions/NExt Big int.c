#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// SOLVED	THIS	PROB	WITH	HELP	OF	chatGPT, however it didnt solve it for me!
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);     
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

long long next_bigger_number(long long n) {
    char s[22];
    sprintf(s, "%llu", n);
    int l = strlen(s);
    if(l==2){
         char tmmp = s[0];
         s[0] = s[1];
         s[1] = tmmp;
         long long r = strtoll(s, NULL, 10);
         return r;
    }
    int lt = l-2;
    int tmp = s[lt] - '0';
    int lo = 0;
    int check = 0;
    for(int i =l-1;i>=0;i--){
         if(tmp < (s[i] - '0')){
             check = 1;
             lo = i-1;
             break;
          }else{
               if(lt > 0){
                 lt--;
                 tmp = s[lt] - '0';
                 }
          }
    }
    if(check == 0){
          return -1;	
    }
    int otp = s[lo+1] - '0';
    int ind = 0;
    for(int i = lo+1; i<l;i++){
         if((s[i] - '0')<= otp && (s[i]-'0') >  (s[lo] - '0')){
             otp = s[i] - '0';
             ind = i;
         }
    }
    // SWAP
    char tpp = s[lo];
    s[lo] = s[ind];
    s[ind] = tpp;
    int arr2[22];
    for(int i =0;i<l;i++){
             arr2[i] = s[i] - '0';
    }
    //SORT
   quicksort(arr2, lo + 1, l - 1);
   char f_s[22];  
   for(int i = 0; i < l; i++){
       f_s[i] = arr2[i] + '0';  
    }
   f_s[l] = '\0';
   long long f_n = strtoll(f_s, NULL, 10);
   return f_n;	
}
int main(void){
     	next_bigger_number(10990);
     	printf("Expected = %lld\n", 19009);
     	//Actual: 10099 Expected: 19009
}