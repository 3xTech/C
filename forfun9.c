#include <stdio.h>

int main(void){
    int array[10];
    int c_n = 0;
    int k_v;
    int each;
    int i;
    int n_nd;
    for(i=0; i<10; i++){
        scanf("%d", &k_v);
        array[c_n] = k_v;
        c_n++;
    }
    scanf("%d", &n_nd);
    printf("%d", array[n_nd]);
    return 0;
}
/*500 180 650 25 666 42 421 1 370 211
3
25*/