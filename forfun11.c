#include <stdio.h>

int main(void) {

    double ingre[10];
    double prc[10];
    int i;
    int h_mny;
    double to = 0;
    scanf("%d", &h_mny);
    for (i=0; i<h_mny; i++) {
        scanf("%lf", &ingre[i]);
    }
    for (i=0; i<h_mny; i++) {
        scanf("%lf", &prc[i]);
    }
    for(i=0;i<h_mny;i++){
        to = to + (ingre[i] * prc[i]);
    }
    printf("%.6lf", to);
    return 0;
}
/*4
9.90 5.50 12.0 15.0
0.250 1.5 0.300 1.0
Output:
29.325000

9.90×0.250=2.475
5.50×1.5=8.25
5.50×1.5=8.25
12.0×0.300=3.60
12.0×0.300=3.60
15.0×1.0=15.00
15.0×1.0=15.00
*/