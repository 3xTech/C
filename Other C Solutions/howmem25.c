#include <stdio.h>

int getsize(char);
int main(void){
    char c;
    int nu = 0;
    int mb = 0;
    int kb = 0;
    int b = 0;
    int f = 0;
    int r = 0;
    scanf("%c %d", &c,&nu);
    int s = getsize(c)*nu;
    if(s >= 1000 && s < 1000000){ 
        r = s%1000;
        b = r;
        kb = (s - r)/1000;
        printf("%d KB and %d B", kb, b);
    }else if(s >= 1000000){
        r = s%1000;
        b = r;
        f = (s-r)/1000;
        kb = f%1000;
        mb = (f - kb)/1000;
        printf("%d MB and %d KB and %d B", mb, kb, b);
    }else if(s < 1000){
        b = s;
        printf("%d B", b);
    }
    return 0;
}

int getsize(char ch){
    int result = 0;
    if(ch == 'i'){
        result = sizeof(int);
    }else if(ch == 's'){
        result = sizeof(short);
    }else if(ch == 'c'){
        result = sizeof(char);
    }else if(ch == 'd'){
        result = sizeof(double);
    }
    return result;
}