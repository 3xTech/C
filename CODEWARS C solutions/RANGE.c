#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *range_extraction(const int *args, size_t n) {
    int t = 0;
    int f = 0;
    int l = 0;
    int arr[n];
    int f_a = 0;
    for(int i = 0; i<(int)n; i++) {
        //printf("the num +1 = %d and next = %d\n",  (*(args + i) + 1), (*(args + i+1)));
        if((*(args + i) + 1) == *(args + i+1)) {
            if(t == 0) {
                //printf("Here f = %d\n",  *(args + i));
                f = *(args + i);
            }
            t++;
        } else {
            if(t >= 2) {
                l = *(args + i);
                arr[f_a] = f;
                arr[f_a+1] = l;
                l = 0;
                t = 0;
                f = 0;
                f_a += 2;
            }
            l = 0;
            t = 0;
            f = 0;
        }
    }
    char *f_s = (char *) malloc(n*n*n * sizeof(char));
    f_s[0] = '\0'; 

    /*for(int i = 0; i < no; i++) {
        char tmp[20];
        sprintf(tmp, "%d", f_arr[i]);  // Convert the number to string

        strcat(f_s, tmp);  // Concatenate the number to f_s

        if(i < no - 1) {
            strcat(f_s, "-");  // Add a dash if it's not the last number
        }
    }*/
    if(f_a == 0){
        for(int i = 0; i < (int)n; i++) {
        char tmp[20];
        sprintf(tmp, "%d", args[i]);
        strcat(f_s, tmp); 
        if(i < (int)n - 1) {
            strcat(f_s, ","); 
        }}
    }
    else{
    int a_i = 2;
    int h = arr[1];
    int lo = arr[0];
    char tmp[20];
    for(int j = 0; j<(int) n;j++){
    	  if(args[j] > h || args[j] < lo){
    	          sprintf(tmp, "%d", args[j]);
    	          strcat(f_s, tmp); 
                  if(j < (int)n - 1) {
                      strcat(f_s, ","); 
                  } 
    	  }
    	  if(args[j] == lo){
    	           sprintf(tmp, "%d", args[j]);
    	          strcat(f_s, tmp); 
                  if(j < (int)n - 1) {
                      strcat(f_s, "-"); 
                  }             
    	   }
    	   if(args[j] == h){
    	                sprintf(tmp, "%d", args[j]);
    	                strcat(f_s, tmp); 
                        if(j <(int) n - 1) {
                               strcat(f_s, ","); 
                        }
                        if(a_i < f_a){
    	                   h = arr[a_i + 1];
    	                   lo = arr[a_i];
    	                   a_i += 2;}
    	     }
    }}
    //return f_s;
    printf("Extracted ranges: ");
    for (int i = 0; i < n*n; i++) {
        printf("%c", f_s[i]);
    }
    printf("\n");
}

int main() {
    int args[] = { 1,3,4,5,6,8,9,10,12,13,15,17,18,20,23}; // Example input
    size_t n = sizeof(args) / sizeof(args[0]);

    range_extraction(args, n); // Call the function

    return 0;
}
