#include <stdio.h>

int main(void){
    int age;
    int wgt;
    scanf("%d", &age);
    scanf("%d", &wgt);
    if(age==60){
        printf("%d", 0);
    } else if(age < 10){
        printf("%d", 5);
    }else{
        if(wgt>20){
            printf("%d", 10+30);
        }else{
            printf("%d", 30);
        }
    }
    return 0;
}
/*Input:
22
25
Output:
40*/