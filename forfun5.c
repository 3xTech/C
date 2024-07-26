#include <stdio.h>

int main(void){
    int nb_p;
    double c_g;
    double c_u;
    scanf("%d", &nb_p);
    scanf("%lf", &c_g);
    if(nb_p == 0){
        c_u = c_g;
    }else{
        c_u = (c_g + 1)/(nb_p +1);
    }
    printf("%.2lf", c_u);
    return 0;
}
/*0 23.9
Output
23.90
 

Input
2 45.5
Output
15.50
 

Input
3 34.8
Output
8.95*/