#include <stdio.h>

int main(void){
    int i;
    int j;
    int a;
    int b;
    int cntr = 0;
    int n = 0;
    char word[51];
    char swap;
    scanf("%s", word);
    while(word[n] != '\0'){
        n++;
    }
    
    for (j=0; j<n-1; j++) {
        for (i=0; i<n-1; i++) {
            if (word[i] > word[i+1]) {
                swap = word[i];
                word[i] = word[i+1];
                word[i+1] = swap;
            }
        }
    }
    char ll = '0';
    for(a=0;a<n-1;a++){ 
           if(word[a] == word[a+1] && ll == '0'){
              cntr++;
              ll = word[a];
           }else{
              if(word[a] == word[a+1] ){
                     if(word[a] != ll){
                         cntr++;
                         ll = word[a];
                     }
              }
           }
    }
    printf("%d", cntr);
    return 0;
}