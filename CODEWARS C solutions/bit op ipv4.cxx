#include <stdio.h>
#include <inttypes.h>
#include <string.h>

void uint32_to_ip(uint32_t number, char *IPv4) {
    *IPv4 = '\0';
    int i = 0;
    unsigned int rem = 0;
    int s = 31;
    uint32_t c = number;
    int r[32];    
    while (i < 32) {
        r[i] = c / (1 << s); 
        rem = c % (1 << s); 
        c = rem;
        s--;
        i++;
    }
    int j = 0;
    int p = 7;
    int ns[5];
    int in = 0;
    int s2 = 0;
    while(j<33){
        s2 = s2 +  (r[j] * (1 << p));
        //printf("2 power of = %d and j = %d, the po of 2 = %d and S = %d\n",  (r[j] * (1 << p)), r[j], (1 << p), s2);
        if(j == 7 || j == 15 || j == 23 || j == 31){
              ns[in] = s2;
              s2 = 0;
              p = 8;
              in++;
        }
        p--;
        j++;
    }
    char temp[4];  
    for (i = 0; i < 4; i++) {
        sprintf(temp, "%d", ns[i]); 
        strcat(IPv4, temp);   
        if (i != 3) {                
            strcat(IPv4, ".");
        }
    }
}

int main() {
    uint32_t number = 1234; // Example IP in decimal form (192.168.1.1)
    char IPv4[16];  // IPv4 address space

    uint32_to_ip(number, IPv4);

    


    return 0;
}
