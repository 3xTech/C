#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100


char** split(char *input, int *size) {
    char **words = (char**)malloc(MAX_WORDS * sizeof(char*));
    int word_count = 0;
    char *token = strtok(input, " ");

    while (token != NULL) {
        if (strcmp(token, "and") != 0) {
            char *dash_pos = strchr(token, '-');
            if (dash_pos) {
                *dash_pos = '\0';  
                words[word_count] = (char*)malloc(strlen(token) + 1);
                strcpy(words[word_count++], token); 

                words[word_count] = (char*)malloc(strlen(dash_pos + 1) + 1);
                strcpy(words[word_count++], dash_pos + 1);  
            } else {
                words[word_count] = (char*)malloc(strlen(token) + 1);
                strcpy(words[word_count++], token);  
            }
        }
        token = strtok(NULL, " ");
    }
    *size = word_count; 
    return words;     
}
long parse_int (const char* number) {
     int num[8] = {0};
     char *l[] = {
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
        "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"
    };
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000
    };
    int s = 0;
    char *n_c = (char *) malloc(strlen(number) +1);
    strcpy(n_c, number);
    char **a_s = split(n_c, &s);
    for(int i=0; i<8;i++){
         printf("%s ", a_s[i]);	
    }
    printf("\n");
    int m = 0;
    for(int i=0; i<s;i++){
         for(int j=0;j<30;j++){
                  if(strcmp(a_s[i], l[j]) == 0 && a_s[i] != '\0'){
                  	   num[m] = a[j];
                  	   m++;
                  }
         }
    }
    for(int i=0; i<8;i++){
             printf("%d ", num[i]);
     }
     printf("\n");
    long sum = 0;
    int track = 0;
    for(int i=0; i<8;i++){
         if(i == 0){
              sum = num[i];
              continue;	
         }
         if(num[i] == 100 || num[i] == 1000 || num[i] == 1000000){
         	    sum *= num[i];
         	    if(num[i] == 1000){
         	            track = i+1;
         	            break;	
         	    }
         }else{
                sum += num[i];	
         }
    }
    long sum2 = 0;
    if(track != 0){
             for(int i=track; i<8;i++){
                         if(i == track){
                                    sum2 = num[i];
                                    continue;	
                         }
                        if(num[i] == 100){
         	                      sum2 *= num[i];
                        }else{
                                   sum += num[i];	
                        }
    }}
    printf("Sum = %ld\n", sum+sum2);
    for (int i = 0; i < s; i++) {
        free(a_s[i]);
    }
    free(a_s);
    free(n_c);
    return sum + sum2;
}

int main() {
    // Example input
    char input[] = "twenty";
    //"seven hundred eighty-three thousand nine hundred and nineteen";
    //"two hundred forty-six";
    parse_int(input);
    return 0;
}