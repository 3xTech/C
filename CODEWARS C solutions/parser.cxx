 #include <stddef.h>

int *parse (const char *program)
{
	// return a heap-allocated int array
	// its length shall be at least equal to
	// the count of 'o' commands in the program
  int c = 0;
  int i = 0;
  while(*(program + i) != '\0'){
       if(* (program + i) == 'o'){
          c++;
       }
      i++;
  }
  c++;
  int b = 0;
  int t = 0;
  int * ptm = (int *) malloc(c * sizeof(int));
  for(int j=0;j<i;j++){
       if(*(program + j) == 'i'){
            b++;
       }else if(* (program + j) == 'd'){
           b--;
       }else if(*(program+j)=='s'){
           b = b*b;
       }else if(*(program + j) == 'o'){
           *(ptm + t) = b;
           t++;
       }
  }
	return ptm;
}