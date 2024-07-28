#include <stdio.h>

int main(void){
    int rng = 0;
    int rng2 = 0;
    scanf("%d %d", &rng, &rng2);
    int c_t = 0;
    while(c_t != -999){
        scanf("%d", &c_t);
        if(c_t != -999){
            if(c_t >= rng && c_t <= rng2){
                printf("Nothing to report\n");
            } else{
                 printf("Alert!\n");
                 c_t = -999;
            }
        }
    }
    return 0;
}
