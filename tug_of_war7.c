#include <stdio.h>

int main(void){
    int i;
    int it;
    scanf("%d", &it);
    int t_w1 = 0;
    int t_w2 = 0;
    int h;
    int e = 1;
    for(i=0; i < 2*it; i++){
        scanf("%d", &h);
        if(e % 2 == 0){
            t_w2 = t_w2 + h;    
        }else{
            t_w1 = t_w1 + h;
        }
        e++;
    }
    
    if(t_w1 > t_w2){
           printf("Team 1 has an advantage\n");
    }else{
           printf("Team 2 has an advantage\n");
    }
    printf("Total weight for team 1: %d\nTotal weight for team 2: %d", t_w1, t_w2);
    return 0;
}

/*Input
4
110
106
113
102
112
121
117
111
Output
Team 1 has an advantage
Total weight for team 1: 452
Total weight for team 2: 440*/