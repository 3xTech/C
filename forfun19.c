#include <stdio.h>

int main(void){
    char nme[51];
    int l = 0;
    int cll = 0;
    scanf("%s", nme);
    while(nme[cll] != '\0'){
        l++;
        cll++;
    }
    if(l%2==0){
        printf("%d", 1);
    }else{
        printf("%d", 1);
    }
    return 0;
}
/*Input:
Sharrock
Output:
1
 

Input:
Bonfert
Output:
2*/