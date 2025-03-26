#include <stdio.h>

int sumOfDigits(int);
int main(void){
    int n;
    int r = 0;
    scanf("%d", &n);
    r = sumOfDigits(n);
    printf("%d", r);
    return 0;
}

int sumOfDigits(int g_s){
    int result;
    int div = g_s/10;
    int r = g_s%10;
    if(g_s < 10){
        return g_s;
    }else{
        result = r + sumOfDigits(div);
    }
    return result;
}