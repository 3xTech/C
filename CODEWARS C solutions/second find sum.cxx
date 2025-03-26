// Took a look at the first code in solution and run back to do it myself!
// So this Inspired by it!
int find_even_index(const int *values, int length) {
  int sum = 0;
  for(int i = 0;i<length;i++){
    sum += (*(values+i));
  }
  int l = 0;
  int r;
  for(int j=0;j<length;j++){
    r = sum - l - (*(values+j));
    if(l == r){
      return j;
    }
    l += (*(values + j));
  }
  return -1;
}  