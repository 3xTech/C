#include <stdio.h>
#include <math.h>

int main(void){
    int mbr = 0;
    double sq = 0;
    double e = 0;
    scanf("%d", &mbr);
    sq = sqrt(mbr);
    e = exp(mbr);
    printf("%.8lf\n",sq);
    printf("%.10lf\n",e);
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.c -o program -lm");
    
    return (0);
}