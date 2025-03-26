#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SOlved it only bcuz chatGPT tell me abut a Dynamic Prog trick
int max(int a, int b) {
    return (a > b) ? a : b;
}

char* lcs(const char* x, const char* y) {
       int l_x = strlen(x);
       int l_y = strlen(y);
       int ** tbl = (int **) malloc((l_x + 1) * sizeof(int *));
       for(int i = 0; i<(l_x +1); i++){
            tbl[i] = (int *) malloc((l_y + 1) * sizeof(int));
       }
       // Fill 1st row and column with zeros
       for(int i = 0; i<l_x +1; i++){
            if(i < l_y + 1){
               tbl[0][i] = 0;
            }
            tbl[i][0] = 0;
       }
       //Let s fill the rest to get len lcs
       for(int i = 1; i<l_x +1;i++){
             for(int j=1;j<l_y +1;j++){
                 if(x[i-1] == y[j-1]){
                     tbl[i][j] = tbl[i-1][j-1] + 1;
                 }else{
                     tbl[i][j] = max(tbl[i-1][j], tbl[i][j-1]);
                 }
             }
       }
       //After getting len now let s tack back
       int c1 = l_x;
       int c2 = l_y;
       int min = l_x < l_y ? l_x : l_y;
       int i = min;
       char *lcs = (char *) malloc((min + 1) * sizeof(char));
       while(c1 > 0 && c2 > 0){
              if(x[c1-1] == y[c2-1]){
                   lcs[i] = x[c1-1];
                   c1--;
                   c2--;
                   i--;
              }else{
                    if(tbl[c1-1][c2] > tbl[c1][c2-1]){
                            c1--;
                    }else{
                        c2--;
                    }
              }
       }
       //Got the lcs backward let's reverse it'
      char *flcs = (char *) malloc((min - i) * sizeof(char));
      for(int j = 0; j < min - i; j++) {
                   flcs[j] = lcs[i + j + 1];
      }
      flcs[min - i] = '\0';

      return flcs;
}