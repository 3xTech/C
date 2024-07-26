#include <stdio.h>

int main(void){
    int i;
    int j = 1;
    double amt;
    int pnd = 120;
    int cst = 45;
    scanf("%lf", &amt);
    for(i = 0; i < amt; i++){
          if(j*pnd < amt){
            j++;
          } else{
            break;
          }
    }
    printf("%d", j*cst);
    
    return 0;
}

/*295.8
Output:
135
*/