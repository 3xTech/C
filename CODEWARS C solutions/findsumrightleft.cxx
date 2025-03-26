#include <stdio.h>

int find_even_index(const int *values, int length);

int main() {
    // Test arrays
    int arr1[] = {1, 100, 50, -51, 1, 1};
    int arr2[] = {20, 10, -80, 10, 10, 15, 35};
    int arr3[] = {1, 2, 3, 4, 3, 2, 1};

    // Find and print the result for each array
    printf("Result for arr1: %d\n", find_even_index(arr1, 6));
    printf("Result for arr2: %d\n", find_even_index(arr2, 7));
    printf("Result for arr3: %d\n", find_even_index(arr3, 7));

    return 0;
}

int find_even_index(const int *values, int length) {
  int fs = 0;
  int c = 0;
  for(int i=0;i<length;i++){
      int s = 0;
      int l = i + 1;
      for(int j = 0;j<(length-(i+1));j++){
            s = s + (* (values + l));
            l++;
      }
      if(fs == s){
         c = i;
         return c;
      }
      fs = fs + (*(values + i));
  }
  return -1;
}