#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *strsum(const char *a, const char *b)
{
    int f_s[100000];
    int s_s[100000];
    int i = 0;
    int j = 0;
    while(*(a + i) != '\0'){
         f_s[i] = *(a + i) - '0'; 
         i++;
    }
    while(*(b + j) != '\0'){
         s_s[j] = *(b + j) - '0';
         j++;
    }
    int f[100000];
    int carry = 0;
    int n;
    if(i > j){
          n = i + 1;
          while(i >= 0){
              if(j >0){
                   if(carry == 1){ 
                          if(f_s[i-1] + s_s[j-1] + carry >= 10){
                                  f[i-1] =  (j > 0) ?  ((f_s[i-1] + s_s[j-1] + carry) %10 ) : (f_s[i-1] + s_s[j-1] + carry);
                                  carry = 1;
                         }else{
                                       f[i-1] =  (f_s[i-1] + s_s[j-1] + carry);
                                       carry = 0;
                         }
                   }else{
                        if(f_s[i-1] + s_s[j-1] >= 10){
                                    //printf("Higher Sum = %d\n", ((f_s[i-1] + s_s[j-1]) % 10));
                                    f[i-1] = ((f_s[i-1] + s_s[j-1]) % 10);
                                     carry = 1;
                        }else{
                                 //printf("LOW Sum = %d\n", (f_s[i-1] + s_s[j-1]));
                                 f[i-1] = ((f_s[i-1] + s_s[j-1]));
                        }
                        }
             }else{
                 	if(i==0){
                 	  if(carry == 1){
                             //printf("Hi last = %d and carry = %d and last el = %d and index = %d\n", (s_s[j] + carry), carry, s_s[j], j);
                         	 f[i] = (f_s[i] + carry);
                         	 carry = 0;
                          }else{
                     	f[i] = f_s[i];
                       }
                       break;
                 }
                 	if(carry == 1){
                          if(f_s[i-1] + carry >= 10){
                                  f[i-1] = (f_s[i-1] + carry) %10;
                                  carry = 1;
                          }else{
                         	 f[i-1] = (f_s[i-1] + carry);
                         	 carry = 0;
                          }
                     }else{
                     	f[i-1] = f_s[i-1];
                     }
             }
             j--;
             i--;
          }	
    }else{
    	n = j + 1;
    	while(j >=0){
             if(i >0){
                   if(carry == 1){ 
                          if(f_s[i-1] + s_s[j-1] + carry >= 10){
                                  f[j-1] =  (j > 0) ?  ((f_s[i-1] + s_s[j-1] + carry) %10 ) : (f_s[i-1] + s_s[j-1] + carry);
                                  carry = 1;
                          }else{
                                      
                                       if(j-1 != 0){
                                            f[j-1] =  (f_s[i-1] + s_s[j-1] + carry);
                                            carry = 0; 
                                            }
                         }
                   }else{
                       if(j-1 != 0){
                        if(f_s[i-1] + s_s[j-1] >= 10){
                                    
                                    f[j-1] = ((f_s[i-1] + s_s[j-1]) % 10);
                                     carry = 1;
                        }else{
                                 
                                 f[j-1] = ((f_s[i-1] + s_s[j-1]));
                        }}
                   }
             }else{
                 
                 if(j==0){
                 	  if(carry == 1){
                             
                              if(i != 0){ 
                     	          f[j] = s_s[j] + carry;
                              }else{
                         	       f[j] =  f_s[j] + s_s[j] + carry;
                              }
                          }else{
                              
                              if(i != 0){ 
                     	          f[j] = s_s[j];
                              }else{
                         	       f[j] =  f_s[j] + s_s[j];
                              }
                            }
                       break;
                 }
                 if(carry == 1){
                          if(s_s[j-1] + carry >= 10){
                                  f[j-1] = (s_s[j-1] + carry) %10;
                                  carry = 1;
                          }else{
                         	 f[j-1] = (s_s[j-1] + carry);
                         	 carry = 0;
                          }
                   }else{
                     	f[j-1] = s_s[j-1];
                     }
             }
             j--;
             i--;
          }
    }
    /*for (int i = 0; i<5; i++) {
           printf("%d", f[i]);
    }
    f[n] = '\0';
    printf("\n");*/
    int w = 0;
    int n_z = 0;
    for (int i = 0; i<n; i++) {
        if(f[i] != 0){
             w = i;
             //printf("f = %d\n", w);
             break;
         }else{
              n_z++;	
         }  
    }
    if(n_z == (n)){
        char *sp = (char *) malloc(2 * sizeof(char));
        sp[0] = '0';
        sp[1] = '\0';
        return sp;
    }else{
   char * str = (char *) malloc((n - w + 1) * sizeof(char));
   str[0] = '\0';
   int si = 0;
   for (int i = w; i<n-1; i++) {
                  char buffer[10];
                  sprintf(buffer, "%d", f[i]);
                  strcat(str, buffer);
                  //printf("i = %d \n", i);
      }
     str[n] = '\0';
     return str;
}
}

int main() {
    const char *num1 = "50095301248058391139327916261";
    //"123456789";
    const char *num2 = "81055900096023504197206408605"; 
    //"987654321";
    
    char * f = strsum(num1, num2);  // Call the function with the numbers
    printf("FINAL	S = %s\n", f);          
    return 0;
}
