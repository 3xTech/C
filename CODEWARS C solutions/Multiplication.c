#include <stdio.h>
#include <stdlib.h>

int **multiplication_table(int n) {
    // MINE
    /*
    #include <stdlib.h>
int **multiplication_table(int n) {
    int ** table = malloc(n * sizeof(int *));
    int i, j;
    for(i=0;i<n;i++){
       * (table + i) = (int *) malloc(n * sizeof(int));
       for(j=0;j<n;j++){
          *(* (table + i) + j) = (i + 1) * (j + 1);
       }
    }
    return table;
}
    */
    // Allocate memory for an array of pointers (n rows)
    int **table = malloc(n * sizeof(int *));
    
    // For each row, allocate memory for n integers (n columns)
    for (int i = 0; i < n; i++) {
        table[i] = malloc(n * sizeof(int));
        
        // Fill the row with multiplication values
        for (int j = 0; j < n; j++) {
            table[i][j] = (i + 1) * (j + 1); // Fill with (i+1) * (j+1) as per the example
        }
    }
    
    return table;  // Return the pointer to the dynamically allocated table
}

// Helper function to print the table (for testing)
void print_table(int **table, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

// Helper function to free the memory
void free_table(int **table, int n) {
    for (int i = 0; i < n; i++) {
        free(table[i]);  // Free each row
    }
    free(table);  // Free the array of row pointers
}

int main() {
    int n = 3;  // Size of the multiplication table
    int **table = multiplication_table(n);  // Create the table
    
    print_table(table, n);  // Print the table
    
    free_table(table, n);  // Free the memory after use
    
    return 0;
}

