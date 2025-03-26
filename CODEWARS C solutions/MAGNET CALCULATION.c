#include <stdio.h>
#include <math.h>

double doubles(int maxk, int maxn) {
         int k = 1;
         double sum = 0;           
         while(k<maxk+1){
                 int n = 1;
                 while(n<maxn+1){
                 	  double sor = k*pow((double)(n + 1), 2*k); 
                 	  sum +=  1.0/sor;
                 	  //printf("the form = %lf, n = %d, the pow = %lf, the cal = %lf\n", sum, n,pow((double)(n + 1), 2*k),(1.0/k*pow((double)(n + 1), 2*k)) );
                 	  n++;
                 }
                 k++;
           }  
           printf("F SUM = %lf\n", sum); 
	       return sum;
}


int main(void){
	
	doubles(1, 10);
	
	
	
}