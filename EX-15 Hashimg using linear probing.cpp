#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct HashTable {
    int keys[SIZE];
    int values[SIZE];
    int size;
};

void initializeHashTable(struct HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        ht->keys[i] = -1;  
        ht->values[i] = -1;
    }
    ht->size = 0;
}

int hash(int key) {
    return key % SIZE;
}

void insert(struct HashTable* ht, int key, int value) {
    if (ht->size == SIZE) {
        printf("Hash table is full. Cannot insert %d.\n", key);
        return;
    }

    int index = hash(key);
    while (ht->keys[index] != -1) {
        index = (index + 1) % SIZE;  
    }

    ht->keys[index] = key;
    ht->values[index] = value;
    ht->size++;
}

int search(struct HashTable* ht, int key) {
    int index = hash(key);
    int originalIndex = index;

    while (ht->keys[index] != -1) {
        if (ht->keys[index] == key) {
            return ht->values[index];
        }
        index = (index + 1) % SIZE;  
        if (index == originalIndex) {
            break;  
        }
    }

    return -1;  
}

void display(struct HashTable* ht) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (ht->keys[i] != -1) {
            printf("[%d] -> %d\n", ht->keys[i], ht->values[i]);
        }
    }
}

int main() {
    struct HashTable ht;
    initializeHashTable(&ht);

    insert(&ht, 5, 50);
    insert(&ht, 15, 150);
    insert(&ht, 25, 250);
    insert(&ht, 6, 60);

    printf("Hash table after insertions:\n");
    display(&ht);

    int keyToSearch = 15;
    int foundValue = search(&ht, keyToSearch);
    if (foundValue != -1) {
        printf("Value for key %d: %d\n", keyToSearch, foundValue);
    } else {
        printf("Key %d not found.\n", keyToSearch);
    }

    return 0;
}

