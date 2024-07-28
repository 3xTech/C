#include <stdio.h>

int main(void){
    int tog = 0;
    scanf("%d", &tog);
    int g = 0;
    int n_g = 0;
    while(g != tog){
        scanf("%d", &g);
        if(g < tog){
            printf("it is more\n");
        }
        if(g > tog){
            printf("it is less\n");
        }
        n_g++;
    }
    printf("Number of tries needed: %d\n", n_g);
    return 0;
}