#include <stdio.h>

int main(void){
    int a = 5;
    int b =  -1;
    int op = 0;
    int l = 0;
    int i, sum;
    if(a==b){
      return a;
    }else{
        if(a>b){
          op = a;
          l = b;
        }else{
          op = b;
          l = a;
        }
        i = l+1;
        sum = l;
        while(i<op+1){
           sum += i;
           printf("%d   sum1\n", sum);
           i++;
        }
        printf("%d i\n", i);
      }
    printf("sum1 %d\n", sum);
    
    return 0;
}
/* (5 , -1), 14, "Expected %d, instead got %d", 14 , get_sum(5 , -1));
(505 , 4), 127759, "Expected %d, instead got %d", 127759 , get_sum(505 , 4));
(-50 , 0), -1275, "Expected %d, instead got %d", -1275 , get_sum(-50 , 0));
   (321 , 123), 44178, "Expected %d, instead got %d", 44178 , get_sum(321 , 123));
    (-1 , -5), -15, "Expected %d, instead got %d", -15 , get_sum(-1 , -5));
    (-5 , -5), -5, "Expected %d, instead got %d", -5 , get_sum(-5 , -5));
   (get_sum(-504 , 4), -127250, "Expected %d, instead got %d", -127250 , get_sum(-504 , 4));
}*/