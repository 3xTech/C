#include <stdio.h>

int main(void){
    int c_p;
    double grth;
    scanf("%d", &c_p);
    scanf("%lf", &grth);
    int f = c_p * (1 + (grth/100));
    printf("%d\n", f);
    return 0;
}
/*123
7.0
Output:
131*/