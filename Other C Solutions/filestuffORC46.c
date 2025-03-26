#include <stdio.h>

int main(void){
    FILE *hld;
    hld = fopen("gradeComparison.txt", "r");
    double f_better = 0.0;
    double tmp;
    int i = 2;
    fscanf(hld,"%lf",&tmp);
    double f_nbr = tmp;
    while(fscanf(hld,"%lf",&tmp)!= EOF){
        if(tmp>f_nbr){
            f_better = tmp;
            nbr = i;
            break;
        } 
        i++;
    }
    if(f_better == 0.0){
        printf("Yes");
    }else{
        printf("No %d", i);
    }
    fclose(hld);
    return 0;
}