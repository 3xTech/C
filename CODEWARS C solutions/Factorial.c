#include <stdio.h>
#include <math.h>

long zeros(long n) {
  long fct = 0;
  int i = 1;
  int p = (int) pow(5, i);
  while(n/p != 0){
      fct = fct + (n/p);
      i++;
      p = (int) pow(5, i);
  }
  return fct;
}