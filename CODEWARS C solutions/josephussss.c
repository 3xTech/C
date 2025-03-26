#include <stdio.h>
#include <stddef.h>

void delete_element(int arr[], int size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}
void josephus_permutation (size_t n, int permuted[n], const int array[n], size_t k){
           int c = k-1;
           int i = 0;
           int j = 0;
           while(1){
               permuted[j] = array[c];
               if((c + k) < (n)){
                  delete_element(array, n, c);
                  n--;
                  c += (k-1);
               }else if((c + k) >= (n)){
                   delete_element(array, n, c);
                   c = (c+k) - n;
                   if(c >= (int) n){
                     break;
                   }
                   n--;
               }
               j++;
               i++;
           }
}

int main() {
    int array[] = {39, 51, 4, 39, 40, 7, 55, 61, 7, 67, 51, 24, 9, 37, 97, 48, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39};  // Original array
    size_t n = sizeof(array) / sizeof(array[0]);
    int permuted[n];                       // Array for Josephus permutation
    size_t k = 3;                          // Every 3rd person is eliminated

    josephus_permutation(n, permuted, array, k);

    // Print the Josephus permutation
    printf("Josephus permutation:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", permuted[i]);
    }
    printf("\n");

    // Print the original array after deletions
    printf("Original array after deletions:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
