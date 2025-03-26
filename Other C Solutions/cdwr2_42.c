#include <stdio.h>

int main(void){


        int k_t = 0;
        int c = 1;
        int c_n = 3210987654;
        int fw = c_n;
        int fw2 = c_n;
        int i,j;
        
        while(fw>=10){
            fw = fw/10;
            c++;
        }
        printf("this is c %d ", c);
        int arr[c];
        int k = (c*2)-1;
        while(k>=c){
            int sq = (fw2%10) * (fw2%10);  
            fw2 = fw2/10;
            arr[k-c] = sq;
            k--;
        }
        for(j=0;j<c;j++){
            printf("Here %d\n", arr[j]);
        }
        int b_n = arr[0];
        for(i=0;i<c;i++){
            if(i>0){
               if(arr[i]<10){
                   b_n *= 10;
                   b_n += arr[i];
               }else{
                   b_n *= 100;
                   b_n += arr[i];
               }
            }
        }
        printf("%d\n", b_n);
        return 0;
}

