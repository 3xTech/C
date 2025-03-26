#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **createArrayCopy(const char *const array[], int length) {
    char **copy = (char **)malloc(length * sizeof(char *));
    for (int i = 0; i < length; ++i) {
        copy[i] = (char *)malloc(strlen(array[i]) + 1);
        strcpy(copy[i], array[i]);
    }
    return copy;
}

int deleteElement(char **array, int length, int index_to_delete) {
    if (index_to_delete < 0 || index_to_delete >= length) {
        return length;
    }
    free(array[index_to_delete]);
    for (int i = index_to_delete; i < length - 1; ++i) {
        array[i] = array[i + 1];
    }
    return length - 1;
}

char **dirReduc(const char *const array[], int length_in, int *length_out) {
    char **mo_array = createArrayCopy(array, length_in);
    int i = 0;
    while (i < length_in - 1) { 
            if ((mo_array[i][0] == 'N' && mo_array[i+1][0] == 'S')|| 
                (mo_array[i][0] == 'S' && mo_array[i+1][0] == 'N')||
                (mo_array[i][0] == 'W' && mo_array[i+1][0] == 'E')|| 
                (mo_array[i][0] == 'E' && mo_array[i+1][0] == 'W')) {
                length_in = deleteElement(mo_array, length_in, i);
                length_in = deleteElement(mo_array, length_in, i);
                if(i>0){ 
                    i--;
                }
            }else{   
                     i++;
            }
            
    }
    printf("length in = %d\n", length_in);
    *length_out = length_in;
    return mo_array;
}

int main(void) {
    const char *arr[6] = {"NORTH", "WEST", "SOUTH", "EAST"};
    int l = 4;  // Correct length of initialized elements
    int ll = 0;
    char **mo_array = dirReduc(arr, l, &ll);
    for (int i = 0; i < ll; i++) {
        printf("String = %s\n", mo_array[i]);
    }
    printf("AFTER CALL %d\n", ll);
}
