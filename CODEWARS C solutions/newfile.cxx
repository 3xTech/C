#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MX_SIZE 10000

char *expandedForm(char *string, unsigned long long n) {
    *string = '\0';
    unsigned long long cop = n;
    unsigned long long m = 1;

    while (cop >= 10) {
        m *= 10;
        cop /= 10;
    }

    unsigned long long arr[50] = {0};
    unsigned long long cop2 = n;
    int i = 0;
    unsigned long long d = m;

    while (d > 0) {
        arr[i] = cop2 / d; 
        cop2 %= d;
        d /= 10; 
        i++;
    }

    unsigned long long arr2[50] = {0};
    int k = 0;
    unsigned long long dd = m;
    while (1) {
        arr2[k] = arr[k] * dd;
        if (dd == 1) {
            break;
        }
        dd /= 10;
        k++;
    }
    int l = 0;
    while (l < i) {
        char buffer[1000];
        if (arr2[l] != 0) {
            snprintf(buffer, sizeof(buffer), "%llu", arr2[l]);
            strncat(string, buffer, MX_SIZE - strlen(string) - 1);
            if (l < i - 1) {
                int nextNonZeroIndex = l + 1;
                while (nextNonZeroIndex < i && arr2[nextNonZeroIndex] == 0) {
                    nextNonZeroIndex++;
                }
                if (nextNonZeroIndex < i) {
                    strncat(string, " + ", MX_SIZE - strlen(string) - 1);
                }
            }
        }
        l++;
    }
    return string;
}

int main() {
    char result[MX_SIZE];

    printf("Expanded form of 70304: %s\n", expandedForm(result, 70304));
    printf("Expanded form of 14040: %s\n", expandedForm(result, 14040));
    printf("Expanded form of 70004: %s\n", expandedForm(result, 70004));

    return 0;
}