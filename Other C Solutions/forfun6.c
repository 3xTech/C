#include <stdio.h>

int main(void){
    int nb_h;
    int max = 53;
    scanf("%d", &nb_h);
    if(nb_h > 8){
        printf("%d", 53);
    }else{
        printf("%d", (nb_h * 5) + 10);
    }
   
    return 0;
}

/*Input
7
Output
45
Example 2
Input
10
Output
53*/