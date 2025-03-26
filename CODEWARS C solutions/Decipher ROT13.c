char *rot13 (char *str_out, const char *str_in)
{
  *str_out = '\0';
  int t;
  int j = 0;
  char g_upper[27] = "NOPQRSTUVWXYZABCDEFGHIJKLM";
  char g_lower[27] = "nopqrstuvwxyzabcdefghijklm";
  for(int i = 0;*(str_in + i)!='\0'; i++){
         if (*(str_in + i) >= 'a' && *(str_in + i)<= 'z'){
             t = *(str_in + i) - 'a';
             str_out[j] = g_lower[t];
             j++;
         } else if (*(str_in + i) >= 'A' && *(str_in + i)<= 'Z'){
             t = *(str_in + i) - 'A';
             str_out[j] = g_upper[t];
             j++;
         } else {
            str_out[j] = *(str_in + i);
            j++;
         }    
  }
  str_out[j] = '\0';
  return str_out;
}