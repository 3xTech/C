#include <stdio.h>

int main(void){
    int n = 0;
    int i;
    char f_n[101];
    char l_n[101];
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%s %s", f_n, l_n);
        printf("%s %s\n", l_n, f_n);
    }
    return 0;
}