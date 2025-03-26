#include <stdio.h>


int main(void){
    int i;
    int j = 67;
    char words[68][41];
    for(i=0;i<68;i++){
        scanf("%s", words[i]);
    }
    for(i=0;i<68;i++){
        printf("%s ", words[j]);
        j--;
    }
    
    return 0;
}
