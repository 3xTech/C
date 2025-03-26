#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_op(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int is_d_f(char ch) {
    return (isdigit(ch) || ch == '.');
}

int main() {
    char expression[1000] = "(2 / (2 + 3) * 4.33 - -6)";  
    double arr[1000]; 
    int n_c = 0;  
    int i = 0, len = strlen(expression);
    
    
    double ad = 101.011;  
    double sub = 102.022; 
    double mul = 103.033; 
    double div = 104.044; 
    double o_p = 105.055; 
    double c_p = 106.066; 
    
     while (i < len) {
    if (isspace(expression[i])) {
        i++;
        continue;
    }

    
    if (expression[i] == '-' && (i + 1 < len && is_d_f(expression[i + 1]))) {
        char buf[50];
        int b_i = 0;
        buf[b_i++] = '-';  
        i++;  
        while (i < len && is_d_f(expression[i])) {
            buf[b_i++] = expression[i++];
        }
        buf[b_i] = '\0';
        arr[n_c++] = atof(buf);  
        continue;
    } 

    if (expression[i] == '-') {
        arr[n_c++] = sub;
        i++;
        continue;
    }

    if (is_d_f(expression[i])) {
        char buf[50];
        int b_i = 0;
        while (i < len && is_d_f(expression[i])) {
            buf[b_i++] = expression[i++];
        }
        buf[b_i] = '\0';
        arr[n_c++] = atof(buf);  
        continue;
    }

    if (is_op(expression[i])) {
        if (expression[i] == '+') {
            arr[n_c++] = ad; 
        } else if (expression[i] == '*') {
            arr[n_c++] = mul;
        } else if (expression[i] == '/') {
            arr[n_c++] = div;
        }
        i++;
    } else if (expression[i] == '(') {
        if(i!=0){
             arr[n_c++] = o_p;
         }
         i++;
    } else if (expression[i] == ')') {
       if(i!=len-1){
           arr[n_c++] = c_p;
       }
       i++;
    }
}

     for (int j = 0; j < n_c; j++) {
           printf("%lf ", arr[j]);
    }
    printf("V F \n");
    for (int j = 0; j < n_c; j++) {
        if (arr[j] == div) {
                arr[j-1] = arr[j-1] / arr[j+1];
                arr[j] = 0.0;
                arr[j+1] = 0.0;
         }
     }
     for (int j = 0; j < n_c; j++) {
        if (arr[j] == mul) {
                //printf("%lf and %lf and result %lf\n", arr[j-1], arr[j+1], arr[j-1] * arr[j+1]);  
                arr[j-1] = arr[j-1] * arr[j+1];
                arr[j] = 0.0;
                arr[j+1] = 0.0;
         }
     }
     for (int j = 0; j < n_c; j++) {
           printf("%lf ", arr[j]);
    }
    printf("F \n");
    for (int j = 0; j < n_c; j++) {
        if (arr[j] == o_p) {
              //   while(arr[j]) != c_p){
                            	
                // }
         }
     }
    for (int j = 0; j < n_c; j++) {
        if (arr[j] == o_p || arr[j] == c_p) {
                 arr[j] = 0.0;
         }
     }
     for (int j = 0; j < n_c; j++) {
           printf("%lf ", arr[j]);
    }
    printf("No pa \n");
     double arr2[1000];
     int f = 0;
     for (int j = 0; j < n_c; j++) {
            if(arr[j] != 0.0){
                  arr2[f] = arr[j];
                  f++;	
            }  
    }
    for (int j = 0; j < f; j++) {
           printf("%lf ", arr2[j]);
    }
    printf("arr2 \n");
     for (int j = 0; j < f; j++) {
            if(arr2[j] == ad){
                arr2[j-1] = arr2[j-1] + arr2[j+1];
                arr2[j] = 0.0;
                arr2[j+1] = 0.0;
            }  
    }
    for (int j = 0; j < f; j++) {
           printf("%lf ", arr2[j]);
    }
    printf("arr2 after add \n");
    double arr3[1000];
     int f2 = 0;
     for (int j = 0; j < f; j++) {
            if(arr2[j] != 0.0){
                  arr3[f2] = arr2[j];
                  f2++;	
            }  
    }
     for (int j = 0; j < f2; j++) {
            if(arr3[j] == sub){
                arr3[j-1] = arr3[j-1] - arr3[j+1];
                arr3[j] = 0.0;
                arr3[j+1] = 0.0;
            }  
    }
    printf("\n");
   for (int j = 0; j < f2; j++) {
           printf("%lf ", arr3[j]);
    }
    return arr3[0];
}


