#include <stdio.h>

int main(void){
    int number = 10;
    int i;
    int j = 0;
    int k = 0;
    int sum = 0;
	if(number<0){
      return 0;
    }else{
      for(i=0;i<number;i++){
        if(i%3==0 && i%5!=0){
          sum = sum + i;
        }else if(i%5==0 && i%3!=0){
          sum = sum + i;
          printf("l  %d", i);
        }else if(i%5==0 && i%3==0){
          sum = sum + i;
        }
      }
    }

    printf("end %d", sum);
    return 0;
}



