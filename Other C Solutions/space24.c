#include <stdio.h>

int total_space(int, char);
int main(void){
    int i;
    int h_c = 0;
    char t_c;
    int to = 0;
    int n = 0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d %c", &h_c, &t_c);
        if(t_c == 'i' || t_c == 'c' || t_c == 'd'){
            int r = total_space(h_c,t_c);
            to = to + r;
        }else{
            n = 0;
            printf("Invalid tracking code type\n");
        }
    }
    if(n != 0){
        printf("%d bytes\n", to);
    }
    return 0;
}

int total_space(int i, char c){
    int result = 0;
    if(c == 'i'){
        result = i * 4;
    }else if(c == 'c'){
        result = i * 1;
    }else if(c == 'd'){
        result = i * 8;
    }
    return result;
}