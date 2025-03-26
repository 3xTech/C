#include <stdio.h>

int main(void){
    int i = 0;
    int l = 0;
    int kn = 0;
    char word[51];
    scanf("%s", word);
    while(word[l] != '\0'){
        l++;
    }
    
    for(i=0;i<l;i++){
        if(l%2 == 0){
            int m = l/2;
            if((i+m - m < m) && (word[i+m - m] == 't' || word[i+m - m] == 'T')){
                kn = 1;
                printf("%d", 1);
            }else{
                if((i+m - m > m) && (word[i+m - m] == 't' || word[i+m - m] == 'T')){
                  kn = 1;
                  printf("%d", 2);
                  }
            }   
        }else{
             if(word[i] == 't' || word[i] == 'T'){
                kn = 1;
                printf("%d", 1);
            } 
        }
    }
    if(kn == 0){
        printf("%d", -1);
    }
    return 0;
}