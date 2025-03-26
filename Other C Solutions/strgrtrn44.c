#include <ctype.h> 
#include <stdio.h>


int main(void){
  char l = '\0';
  char array[] = { 'O','Q','R','S' };
  int arrayLength = 4;
  char u_c[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char l_c[] = "abcdefghijklmnopqrstuvwxyz";
  int wh = 0;
  int i;
  if(isupper(*array)){
      for(i=0;i<26;i++){
                if(*(u_c + i) == * array){
                    wh = i;
                    break;
                }
         }
      for(i=0;i<arrayLength;i++){
           if(*(u_c + (wh+i)) != * (array + i)){
                 l = *(u_c + (wh+i));
                 break;
           }
      }
  }else{
      for(i=0;i<26;i++){
                if(*(l_c + i) == * array){
                    wh = i;
                    break;
                }
         }
       for(i=0;i<arrayLength;i++){
           if(*(l_c + (wh+i)) != * (array + i)){
                 l = *(l_c + (wh+i));
                 break;
           }
      }
  }
  printf("%c here\n", l);
    
  return 0;
}