#include <stdio.h>

void meow(void);
int main(void){
    int i = 3;
    while(i > 0){
        printf("%i\n", i);
        i--;
    }
    for(int i = 3; i >0; i--){
        meow();
    }
}

void meow(void){
    printf("me0w\n");
}