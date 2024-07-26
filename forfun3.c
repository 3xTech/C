#include <stdio.h>

int main(void){
    double mny;
    double pr;
    scanf("%lf", &mny);
    scanf("%lf", &pr);
    int f = mny/pr;
    printf("%d\n", f);
    return 0;
}

/*48.0
3.50
Output
13
Input
27.0
5.0
Output
5*/