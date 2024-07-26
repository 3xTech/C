#include <stdio.h>

int main(void){
    int hwmany;
    int i;
    int to = 0;
    int t;
    scanf("%d", &hwmany);
    for(i = 0; i < hwmany; i++){
        scanf("%d", &t);
        to = to + t;
    }
    double avg;
    avg = (double) to / hwmany;
    printf("%.2lf", avg);
}