#include <stdio.h>

int main(void){
    int i;
    int mult = 0;
    int v;
    printf("Put the multiplication table you wanna see: ");
    scanf("%d", &v);
    for(i=0; i < 11; i++){
        printf("%dx%d = %d\n", mult, v, mult*v);
        mult++;
    }
    return 0;
}