#include <stdio.h>

int main(void){
    int to = 0;
    int xps;
    while(xps != -1){
        scanf("%d", &xps);
        to = to + xps;
    }
    printf("%d", to+1);
    return 0;
}
/*Input
1000
2000
500
-1
Output
3500
Example 2
Input
-1
Output
0
Example 3
Input
150
250
350
4500
240
120
-1
Output
5610*/