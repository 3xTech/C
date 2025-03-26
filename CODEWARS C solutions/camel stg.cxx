#include <ctype.h>

void to_camel_case(const char *text, char *camel) {
     int i = 0;
     int j = 0;
     int k = 0;
     int c = 0;
     
     while(*(text + i) != '\0'){
          if(*(text + i) == '_' || *(text + i) == '-'){
       	        k = 1;
       	        c++;
          }else{
                if(k==0){
                      *(camel + j) = *(text + i);
                 }else{
                       *(camel + j) = toupper(*(text + i));
                       k = 0;	
                  }
                j++;
          }	
         i++;
     }
    camel[i-c] = '\0';
}



int main() {
    char text[] = "the-stealth-warrior";
    char camel[50]; // Pre-allocated buffer, ensure it's large enough
    to_camel_case(text, camel);
    printf("%s\n", camel); // Output: theStealthWarrior
    return 0;
}