#include <stdio.h>

void reverseArray(int *);

int main(void){
    int arr[6];
    int i, j;
    for(i=0;i<6;i++){
      scanf("%d", &arr[i]);
    }
    reverseArray(arr);
    for(j=0;j<6;j++){
      printf("%d ", arr[j]);
    }
    return 0;
}

void reverseArray(int * arr){
    int l = 5;
    int i;
    for(i=0;i<3;i++){
        int temp = * (arr + i);
        * (arr + i) = * (arr + l);
        * (arr + l) = temp;
        l--;
    }
}