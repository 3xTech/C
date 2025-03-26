#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void removeCommaAndSpace(char *str) {
    char *target = strstr(str, ",  and");
    if (target != NULL) {
        memmove(target, target + 2, strlen(target + 2) + 1); 
    }
}
    
char *formatDuration (int n) {
  int time[5] = {0};
  int s = 1, m = 60, h = 3600,d = 86400, y = 31536000;   
  if (n == 0) {
    char *f_s = (char *) malloc(10 * sizeof(char));
    sprintf(f_s, "now");
    return f_s;
  }
  while(n > 0){
       if(n >= y){
           n -= y;
           time[0] += 1;
       }else if(n >= d && n < y){
            n -= d;
           time[1] += 1;
       }else if(n >= h && n < d){
            n -= h;
           time[2] += 1;
       }else if(n >= m && n < h){
           n -= m;
           time[3] += 1;
       }else if(n >= s && n < m){
            time[4] = n;
            break;
       }
  }
   int st = 0;
   for (int j = 0; j < 5; j++) {
           if(time[j] != 0){
           	st = j;
           	break;
           }
    }
   int ed = 0;
   for (int j = 0; j < 5; j++) {
           if(time[j] != 0 && j>st){
           	ed = j;
           }
    }
    int yr = 0, dy = 1, hr = 2, mn = 3, sc = 4;
    if(ed == 0){
           if(st == yr){
           	char *f_s = (char *) malloc(20 * sizeof(char));
           	sprintf(f_s, time[st] == 1 ? "%d year" : "%d years", time[st]);
           	return f_s;
           }else if(st == dy){
           	char *f_s = (char *) malloc(20 * sizeof(char));
           	sprintf(f_s, time[st] == 1 ? "%d day" : " and %d days", time[st]);
           	return f_s;
           }else if(st == hr){
           	char *f_s = (char *) malloc(20 * sizeof(char));
           	sprintf(f_s, time[st] == 1 ? "%d hour" : "%d hours", time[st]);
           	return f_s;
           }else if(st == mn){
           	char *f_s = (char *) malloc(20 * sizeof(char));
           	sprintf(f_s, time[st] == 1 ? "%d minute" : "%d minutes", time[st]);
           	return f_s;
           }else if(st == sc){	
           	char *f_s = (char *) malloc(20 * sizeof(char));
           	sprintf(f_s, time[st] == 1 ? "%d second" : " and %d seconds", time[st]);
           	return f_s;
           }	
    }
    char *f_s = (char *) malloc(900 * sizeof(char));
    char *ptr = f_s;
    for(int i =st; i<5;i++){
           	if(i == yr){
           		  if(time[i] != 0 && ed != i){
           		     char buf[50];
           		     i == ed ? sprintf(buf, time[i] == 1 ? "%d year"  : "%d years", time[i]) : sprintf(buf, time[i] == 1 ? "%d year, "  : "%d years, ", time[i]);
           		     memcpy(ptr, buf,  strlen(buf));
           		     ptr += strlen(buf);
           		  }else if(time[i] != 0 && ed == i){
           		                  char buf[50];
           		                 sprintf(buf, time[i] == 1 ? " and %d year" : " and %d years", time[i]);
           		                 memcpy(ptr, buf,  strlen(buf));
           		                 ptr += strlen(buf);   	
           		     }
           	}else if(i == dy){
           		     if(time[i] != 0 && ed != i){
           		            	 char buf[50];
           		                 i == ed-1 ? sprintf(buf, time[i] == 1 ? "%d day" : "%d days", time[i]) :  sprintf(buf, time[i] == 1 ? "%d day, " : "%d days, ", time[i]);
           		                 memcpy(ptr, buf,  strlen(buf));
           		                 ptr += strlen(buf);
           		     }else if(time[i] != 0 && ed == i){
           		     	        char buf[50];
           		                 sprintf(buf, time[i] == 1 ? " and %d day" : " and %d days", time[i]);
           		                 memcpy(ptr, buf,  strlen(buf));
           		                 ptr += strlen(buf);
           		     }
           	}else if(i == hr){
           		    if(time[i] != 0 && ed != i){
           		            	char buf[50];
           		                i == ed-1 ? sprintf(buf, time[i] == 1 ? "%d hour" : "%d hours", time[i]) : sprintf(buf, time[i] == 1 ? "%d hour, " : "%d hours, ", time[i]);
           		                memcpy(ptr, buf,  strlen(buf));
           		                ptr += strlen(buf);
           		     }else if(time[i] != 0 && ed == i){
           		     	       char buf[50];
           		                 sprintf(buf, time[i] == 1 ? " and %d hour" : " and %d hours", time[i]);
           		                 memcpy(ptr, buf,  strlen(buf));
           		                 ptr += strlen(buf);
           		     }
           	}else if(i == mn){
           		    if(time[i] != 0 && ed != i){
           		            	char buf[50];
           		                i == ed-1 ? sprintf(buf, time[i] == 1 ? "%d minute" : "%d minutes", time[i]) : sprintf(buf, time[i] == 1 ? "%d minute, " : "%d minutes, ", time[i]);
           		                memcpy(ptr, buf,  strlen(buf));
           		                ptr += strlen(buf);
           		     }else if(time[i] != 0 && ed == i){
           		     	        char buf[50];
           		                 sprintf(buf, time[i] == 1 ? " and %d minute" : " and %d minutes", time[i]);
           		                 memcpy(ptr, buf,  strlen(buf));
           		                 ptr += strlen(buf);
           		     }
           	}else if(i == sc){
           		    if(time[i] != 0 && ed != i){
           		            	char buf[50];
           		                i == ed-1 ? sprintf(buf, time[i] == 1 ? "%d second" : "%d seconds", time[i])  :    sprintf(buf, time[i] == 1 ? "%d second, " : "%d seconds, ", time[i]);
           		                memcpy(ptr, buf,  strlen(buf));
           		                ptr += strlen(buf);
           		     }else if(time[i] != 0 && ed == i){
           		     	         char buf[50];
           		                 sprintf(buf, time[i] == 1 ? " and %d second" : " and %d seconds", time[i]);
           		                 memcpy(ptr, buf,  strlen(buf));
           		                 ptr += strlen(buf);
           		     }
           	}
    } 
    *ptr = '\0';
    removeCommaAndSpace(f_s);
  return f_s;
}
int main()
{
	/* (3600, "1 hour");*/
	char *f_s = formatDuration (120);
	printf("%s ", f_s); 
}