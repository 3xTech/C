#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {

               if(rows < 3){
                  if(rows == 0){
                           int *fa = (int *) malloc((rows*cols)* sizeof(int));
                           return fa;
                  }else if(rows == 1){
                          int *fa = (int *) malloc((rows*cols)* sizeof(int));
                          fa[0] = mx[0][0];
                          fa[1] = mx[1][0];
                          return fa;
                  }else if(rows == 2){
                          int *fa = (int *) malloc((rows*cols)* sizeof(int));
                          fa[0] = mx[0][0];
                          fa[1] = mx[0][1];
                          fa[2] = mx[1][1];
                          fa[3] = mx[1][0];
                          return fa;
                  }
               }else{
               char direction[150];
               char *n_c = direction;
               
               memcpy(n_c,"FDBUF", 5);
               n_c += 5;
               
               int c = 4, r;
               int is_even = 0;
               
               if(rows % 2 == 0){
                      r = rows;	
                      is_even = 1;
               }else{
               	  r = rows + 1;
               }
               
               while(c != r){
               	 memcpy(n_c, "DBUF", 4);
               	 n_c += 4;
               	 c += 2;
               }
               if(is_even){
               	    memcpy(n_c, "DB", 2);
               	    n_c += 2;
               }
               *n_c = '\0';
               printf("STRING = %s", direction);
               
               int *fa = (int *) malloc((rows*cols)* sizeof(int));
               
               for (int i = 0; i < rows; i++) {
                          fa[i] = mx[0][i];
                 }
               
               int cf = 1, cb = rows-1;
               
               int trc = rows;
               int take_d = rows-1, take_u = 0;
               
               int f_u[rows-2];
               for (int i = rows-2; i >= 1; i--) {
                          f_u[i] = i;
               }
               int f_d[rows-1]; 
               for (int i = 1; i < rows; i++) {
                          f_d[i] = i;
                 }
                 
               int f_b[rows-1];
               for (int i = rows-2; i >= 0; i--) {
                          f_b[i] = i;
                 }
               int f_f[rows-2]; 
               for (int i = 1; i <= rows-2; i++) {
                          f_f[i] = i;
                }
                 
                int fu_l = 0, fu_h = rows-3;
                int fd_l = 0, fd_h = rows-2;
                
                int fb_l = 0, fb_h = rows-2;
                int ff_l = 0, ff_h = rows-3;
               
               for(int i =0;i<(int) strlen(direction); i++){
                             if(direction[i] == 'F' && i != 0){
                             	       for(int ii = ff_l;ii<=ff_h;ii++){
                             	               	fa[trc] = mx[cf][f_f[ii]];
                             	               	trc++;
                             	       }
                                       ff_h = ff_h - 1;
                             	       ff_l = ff_l + 1;	 
                                       cf++;      
                             }else if(direction[i] == 'D'){
                             	      for(int ii = fd_l;ii<=fd_h;ii++){
                             	      	      fa[trc] = mx[f_d[ii]][take_d];
                             	      	      trc++;
                             	       }
                             	       fd_h = fd_h - 1;
                             	       fd_l = fd_l + 1;
                                       take_d--; 
                             }else if(direction[i] == 'B'){
                             	       for(int ii = fb_l;ii<=fb_h;ii++){
                             	               	fa[trc] = mx[cb][ii];
                             	               	trc++;
                             	       }
                             	       cb--; 
                             }else if(direction[i] == 'U'){
                                       for(int ii = fu_l;ii<=fu_h;ii++){
                             	      	      fa[trc] = mx[f_u[ii]][take_u];
                             	      	      trc++;
                             	       }
                             	       fu_h = fu_h - 1;
                             	       fu_l = fu_l + 1;
                                       take_u++;
                             }	
               	
               }
                return fa;
               }
}





#include <stdio.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols);

int main(int argc, char *argv[]) {
    size_t p;

    // Ad
    int arr2x2[2][2] = {
        {1, 2},
        {3, 4}
    };
    snail(&p, (const int **)arr2x2, 2, 2);
    printf("\n");

    int arr3x3[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    snail(&p, (const int **)arr3x3, 3, 3);
    printf("\n");

    int arr4x4[4][4] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };
    snail(&p, (const int **)arr4x4, 4, 4);
    printf("\n");

    int arr5x5[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    snail(&p, (const int **)arr5x5, 5, 5);
    printf("\n");

    int arr6x6[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };
    snail(&p, (const int **)arr6x6, 6, 6);
    printf("\n");

    int arr7x7[7][7] = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40, 41, 42},
        {43, 44, 45, 46, 47, 48, 49}
    };
    snail(&p, (const int **)arr7x7, 7, 7);
    printf("\n");

    return 0;
}
