#include <stdio.h>
long long rectangle_rotation(int a, int b)
{
    int r_b = b-1, r_a = a-1;
    int sum = 0;
    if(r_a > r_b){
          sum = (r_a * r_b) + ((r_a-1) * (r_b-1));
    }else{
          sum = (r_a * r_b) + ((r_a-1) * (r_b-1));
    }
    printf("SUM = %d\n", sum);
    return sum; // Do your magic!
}  
int main(int argc, char *argv[])
{
	rectangle_rotation(30,3);
}