#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the open-addressed hash table structure
typedef struct OHTbl_ {
    int positions;
    void *vacated;
    int (*h1)(const void *key);
    int (*h2)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    int size;
    void **table;
} OHTbl;

// Sentinel memory address for vacated elements
static char vacated;

// Initialize the hash table
int ohtbl_init(OHTbl *htbl, int positions, int (*h1)(const void *key), 
               int (*h2)(const void *key), int (*match)(const void *key1, const void *key2), 
               void (*destroy)(void *data)) {
    int i;

    // Allocate space for the table
    if ((htbl->table = (void **)malloc(positions * sizeof(void *))) == NULL)
        return -1;

    htbl->positions = positions;
    for (i = 0; i < htbl->positions; i++)
        htbl->table[i] = NULL;

    // Set the vacated marker
    htbl->vacated = &vacated;
    
    // Set the provided functions
    htbl->h1 = h1;
    htbl->h2 = h2;
    htbl->match = match;
    htbl->destroy = destroy;

    // Initialize the size
    htbl->size = 0;

    return 0;
}

// Destroy the hash table
void ohtbl_destroy(OHTbl *htbl) {
    int i;

    if (htbl->destroy != NULL) {
        for (i = 0; i < htbl->positions; i++) {
            if (htbl->table[i] != NULL && htbl->table[i] != htbl->vacated)
                htbl->destroy(htbl->table[i]);
        }
    }

    free(htbl->table);
    memset(htbl, 0, sizeof(OHTbl));
}

// Insert into the hash table
int ohtbl_insert(OHTbl *htbl, const void *data) {
    void *temp;
    int position, i;

    // Table is full
    if (htbl->size == htbl->positions)
        return -1;

    // Check if the data is already in the table
    temp = (void *)data;
    if (ohtbl_lookup(htbl, &temp) == 0)
        return 1;

    // Use double hashing
    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->h1(data) + (i * htbl->h2(data))) % htbl->positions;
        if (htbl->table[position] == NULL || htbl->table[position] == htbl->vacated) {
            htbl->table[position] = (void *)data;
            htbl->size++;
            return 0;
        }
    }

    return -1;
}

// Remove from the hash table
int ohtbl_remove(OHTbl *htbl, void **data) {
    int position, i;

    // Use double hashing
    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->h1(*data) + (i * htbl->h2(*data))) % htbl->positions;
        if (htbl->table[position] == NULL)
            return -1;
        else if (htbl->match(htbl->table[position], *data)) {
            *data = htbl->table[position];
            htbl->table[position] = htbl->vacated;
            htbl->size--;
            return 0;
        }
    }

    return -1;
}

// Lookup in the hash table
int ohtbl_lookup(const OHTbl *htbl, void **data) {
    int position, i;

    for (i = 0; i < htbl->positions; i++) {
        position = (htbl->h1(*data) + (i * htbl->h2(*data))) % htbl->positions;
        if (htbl->table[position] == NULL)
            return -1;
        else if (htbl->match(htbl->table[position], *data)) {
            *data = htbl->table[position];
            return 0;
        }
    }

    return -1;
}

// Main function to test the hash table
int h1(const void *key) {
    return (*(int *)key) % 11; // Example h1 hash function
}

int h2(const void *key) {
    return 7 - (*(int *)key % 7); // Example h2 hash function
}

int match(const void *key1, const void *key2) {
    return *(int *)key1 == *(int *)key2;
}

void destroy(void *data) {
    free(data); // Free dynamically allocated memory
}

int main() {
    OHTbl htbl;
    int *data, i;
    
    // Initialize the hash table with 11 positions
    if (ohtbl_init(&htbl, 11, h1, h2, match, destroy) != 0)
        return 1;

    // Insert elements
    for (i = 0; i < 7; i++) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
        *data = i + 1;
        ohtbl_insert(&htbl, data);
    }

    // Print the table content
    printf("Hash table size: %d\n", htbl.size);

    // Lookup elements
    int key = 5;
    void *lookup_data = &key;
    if (ohtbl_lookup(&htbl, &lookup_data) == 0)
        printf("Found: %d\n", *(int *)lookup_data);
    else
        printf("Not found: %d\n", key);

    // Remove an element
    if (ohtbl_remove(&htbl, &lookup_data) == 0)
        printf("Removed: %d\n", *(int *)lookup_data);
    
    // Destroy the hash table
    ohtbl_destroy(&htbl);

    return 0;
}
