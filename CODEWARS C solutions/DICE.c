#include <stdio.h>

int score(const int dice[5]) {
    int arr[6] = {0};
    int sum = 0;
    for(int i = 0; i < 5; i++){
        if(dice[i] == 1){
           arr[0] += 1;
        }
        if(dice[i] == 2){
           arr[1] += 1;
        }
        if(dice[i] == 3){
           arr[2] += 1;
        }
        if(dice[i] == 4){
           arr[3] += 1;
        }
        if(dice[i] == 5){
           arr[4] += 1;
        }
        if(dice[i] == 6){
           arr[5] += 1;
        }
    }
    printf("Content of arr: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    for(int i = 0; i < 6; i++){
        if(i == 0){
           if(arr[0] >= 3){
             arr[0] -= 3;
             sum += 1000;
           } else if(arr[0] == 5){
              sum = 1200;
              return sum;
           }
        }
        if(i == 1){
           if(arr[1] >= 3){
             arr[1] -= 3;
             sum += 200;
           } else if(arr[1] == 5){
              sum = 200;
              return sum;
           }
        }
        if(i == 2){
           if(arr[2] >= 3){
             arr[2] -= 3;
             sum += 300;
           } else if(arr[2] == 5){
              sum = 300;
              return sum;
           }
        }
        if(i == 3){
           if(arr[3] >= 3){
             arr[3] -= 3;
             sum += 400;
           } else if(arr[3] == 5){
              sum = 400;
              return sum;
           }
        }
        if(i == 4){
           if(arr[4] >= 3){
             arr[4] -= 3;
             sum += 500;
           } else if(arr[4] == 5){
              sum = 600;
              return sum;
           }
        }
        if(i == 5){
           if(arr[5] >= 3){
             arr[5] -= 3;
             sum += 600;
           } else if(arr[5] == 5){
              sum = 600;
              return sum;
           }
        }
    }
    printf("\n");
    printf("Content of arr2: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }
    for(int i = 0; i < 6; i++){
        if(i == 0){
           if(arr[0] == 1){
             arr[0] -= 1;
             sum += 100;
           } else if(arr[0] == 2){
              sum += 200;
           }
        }
        if(i == 4){
           if(arr[4] == 1){
             arr[4] -= 1;
             sum += 50;
           } else if(arr[4] == 2){
              sum += 100;
           }
        }
    }
   return sum;
}

int main() {
    int dice[5] = {1, 2, 3, 3, 5};  // example input
    int result = score(dice);
    // Print the score result
    printf("\nScore: %d\n", result);
    return 0;
}
