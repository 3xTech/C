#include <stdio.h>


int main(void){
    int i;
    int howmany;
    int enginePower;
    int resistance;
    int weight;
    int height;
    int final = 0;
    scanf("%d", &howmany);
    for(i=0; i < howmany; i++){
         scanf("%d%d%d%d", &enginePower, &resistance, &weight, &height);
         int calc = (weight + height) * (resistance - enginePower);
         final = final + calc;
    }
    
    printf("%d", final);
    
}