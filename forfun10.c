#include <stdio.h>
int main(void){
    double array[50];
    double readValue = 0.0;
    int cellNumber = 0;
    int cellNumber2 = 0;
    int i = 0;
    int h_mny;
    double to = 0.0;
    double b  = 0.0;
    double array2[50];
    scanf("%d", &h_mny);
    for(i=0;i<h_mny;i++){
        scanf("%lf",&readValue);
        to = to + readValue;
        array[cellNumber] = readValue;
        cellNumber = cellNumber + 1;
        if(h_mny - i == 1){
            b = to/h_mny;
        }
    }
    for(i=0;i<h_mny;i++){
        array2[cellNumber2] = b - array[cellNumber2];
        printf("%.1lf\n", array2[cellNumber2] );
        cellNumber2 = cellNumber2 + 1;
    }
    
    return 0;
}

/*Input
5
40.0
12.0
20.0
5.0
33.0
Output
-18.0
10.0
2.0
17.0
-11.0*/