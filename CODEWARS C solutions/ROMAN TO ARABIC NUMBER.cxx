#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned from_roman (const char *roman){
                 int n[10] = {0};
                 for(int i=0;i<(int)strlen(roman);i++){
                            if(roman[i] == 'I'){
                            	    n[i] = 1;
                            }else if(roman[i] == 'V'){
                            	     n[i] = 5;
                            }else if(roman[i] == 'X'){
                            	     n[i] = 10;
                            }else if(roman[i] == 'L'){
                            	     n[i] = 50;
                            }else if(roman[i] == 'C'){
                            	    n[i] = 100;
                            }else if(roman[i] == 'D'){
                            	     n[i] = 500;
                            }else if(roman[i] == 'M'){
                            	      n[i] = 1000;
                            }		
                 }
                 for(int i =0;i<(int)strlen(roman);i++){
                      if(n[i] != 0){
                      	   if(n[i+1] > n[i]){
                      	            n[i] = n[i+1] - n[i];
                      	            n[i+1] = 0;	
                      	   }
                      }
                 }
                 unsigned sum = 0;
                 for(int i=0;i<(int)strlen(roman);i++){
                           sum += n[i];	
                 }
                return sum;
}

void to_roman(unsigned number, char *roman){
          roman[0] = '\0';
         	int n[4] = {0};
         	unsigned ll =number;
         	int o = 1;
         	int ccc = 0;
         	while(ll >= 10){
         	           ll /= 10;
         	           o *= 10;
         	           ccc++;	
         	}
         	ll = number;
         	int j = ccc;
         	while(j >= 0){
         		      n[j] = ll%10;
         		      ll /= 10;
         		      j--;
         	}
         	int nw[4];
         	for(int i = 0;i<4;i++){
         	       nw[i] = n[i] * o;
         	       o /= 10;
         	}
         	
         	for(int i = 0;i<4;i++){
         	       printf("e %d ", nw[i]);
         	}
         	int i = 1, v = 5, x = 10, l = 50, c = 100, d = 500, m = 1000;
             
          char *c_p = roman;
         	for(int i2 =0;i2<4;i2++){
         	      printf("\ne2 %d\n ", nw[i2]);
         	      if(nw[i2] >= i && nw[i2] <= i+i+i){
         	      		        if(nw[i2] == 1){
         	      		        	         memcpy(c_p, "I", 1);
         	      		        	         c_p++;
         	      		        }else if(nw[i2] == 2){
         	      		        	          memcpy(c_p, "II", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 3){
         	      		        	          memcpy(c_p, "III", 3);
         	      		        	         c_p += 3;
         	      		        }
         	      }else if(nw[i2] > i+i+i && nw[i2] <= v+i+i+i){
         	      		       if(nw[i2] == 4){
         	      		                      memcpy(c_p, "IV", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 5){
         	      		        	         memcpy(c_p, "V", 1);
         	      		        	         c_p += 1;
         	      		        }else if(nw[i2] == 6){
         	      		        	          memcpy(c_p, "VI", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 7){
         	      		        	           memcpy(c_p, "VII", 3);
         	      		        	         c_p += 3;
         	      		        }else if(nw[i2] == 8){
         	      		        	         memcpy(c_p, "VIII", 4);
         	      		        	         c_p += 4;
         	      		        }	      		
         	      }else if(nw[i2] > v+i+i+i && nw[i2] <= x+x+x){
         	      		       if(nw[i2] == 9){
         	      		                      memcpy(c_p, "IX", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 10){
         	      		        	          memcpy(c_p, "X", 1);
         	      		        	         c_p += 1;
         	      		        }else if(nw[i2] == 20){
         	      		        	         memcpy(c_p, "XX", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 30){
         	      		        	          memcpy(c_p, "XXX", 3);
         	      		        	         c_p += 3;
         	      		        }
         	      }else if(nw[i2] > x+x+x && nw[i2] <= l+x+x+x){
         	      		       if(nw[i2] == 40){
         	      		                     memcpy(c_p, "XL", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 50){
         	      		        	          memcpy(c_p, "L", 1);
         	      		        	         c_p += 1;
         	      		        }else if(nw[i2] == 60){
         	      		        	          memcpy(c_p, "LX", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 70){
         	      		        	          memcpy(c_p, "LXX", 3);
         	      		        	         c_p += 3;
         	      		        }else if(nw[i2] == 80){
         	      		        	         memcpy(c_p, "LXXX", 4);
         	      		        	         c_p += 4;
         	      		        }
         	      }else if(nw[i2] > l+x+x+x && nw[i2] <= c+c+c){
         	      		       //printf("must %d ", nw[i]);
         	      		       if(nw[i2] == 90){
         	      		                     memcpy(c_p, "XC", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 100){
         	      		        	         memcpy(c_p, "C", 1);
         	      		        	         c_p += 1;
         	      		        }else if(nw[i2] == 200){
         	      		        	       //  printf("HERE\n");
         	      		        	         memcpy(c_p, "CC", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 300){
         	      		        	       memcpy(c_p, "CCC", 3);
         	      		        	         c_p += 3;
         	      		        }
         	      }else if(nw[i2] > c+c+c && nw[i2] <= d+c+c+c){
         	      		       if(nw[i2] == 400){
         	      		                       memcpy(c_p, "CD", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 500){
         	      		        	          memcpy(c_p, "D", 1);
         	      		        	         c_p += 1;
         	      		        }else if(nw[i2] == 600){
         	      		        	         memcpy(c_p, "DC", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 700){
         	      		        	         memcpy(c_p, "DCC", 3);
         	      		        	         c_p += 3;
         	      		        }else if(nw[i2] == 800){
         	      		        	        memcpy(c_p, "DCCC", 4);
         	      		        	         c_p += 4;
         	      		        }
         	      }else if(nw[i2] > d+c+c+c && nw[i2] <= m+m+m){
         	      		       if(nw[i2] == 900){
         	      		                      memcpy(c_p, "CM", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 1000){
         	      		        	          memcpy(c_p, "M", 1);
         	      		        	         c_p += 1;
         	      		        }else if(nw[i2] == 2000){
         	      		        	         memcpy(c_p, "MM", 2);
         	      		        	         c_p += 2;
         	      		        }else if(nw[i2] == 3000){
         	      		        	         memcpy(c_p, "MMM", 3);
         	      		        	         c_p += 3;
         	      		        }
         	      }	
         	}
         	*c_p = '\0';
         	printf("f %s", roman);
}
int main(void){
             	char *ro = (char *)malloc(100 * sizeof(char));
             	to_roman(1273, ro);
             	from_roman("MM");
}