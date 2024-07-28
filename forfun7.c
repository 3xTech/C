#include <stdio.h>

int main(void){
    int n = 0;
    char word[100];
    scanf("%d", &n);
    scanf("%s", word);
    int i;
    for(i=0;i<n;i++){
        printf("%s\n", word);
    }
    
    return 0;
}