#include <stdio.h>

int min(int, int);

int main(void){
    int i_n;
    int i;
    int i_c;
    int i_m = 0;
    scanf("%d", &i_n);
    for(i=0;i<i_n;i++){
        scanf("%d", &i_c);
        if(i==0){
            i_m = i_c;
        }
        i_m = min(i_c, i_m);
    }
    printf("%d", i_m);
    return 0;
}

int min(int i_comp, int i_comp2){
    int iresult = 0;
    if(i_comp > i_comp2){
        iresult = i_comp2;
    }else{
        iresult = i_comp;
    }
    return iresult;
}