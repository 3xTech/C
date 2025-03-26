#include <stdio.h>

int main(void){
    FILE *hld;
    char filename[] = "myGrades.txt";
    int grd;
    int l_grd;
    scanf("%d", &grd);
    hld = fopen(filename, "r");
    while(fscanf(hld, "%d", &l_grd) != EOF){
    }
    fclose(hld);
    if(grd == l_grd){
        hld = fopen(filename, "r");
        while(fscanf(hld, "%d", &l_grd) != EOF){
              printf("%d", l_grd);  
        }
        fclose(hld);
    }else{
        hld = fopen(filename, "a");
        fprintf(hld, " %d ", grd);
        fclose(hld);
        hld = fopen(filename, "r");
        while(fscanf(hld, "%d", &l_grd) != EOF){
              printf("%d ", l_grd);  
        }
        fclose(hld);
        
    }
    return 0;
}
