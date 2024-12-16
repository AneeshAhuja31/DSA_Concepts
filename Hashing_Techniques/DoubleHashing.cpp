#include<iostream>
#define SIZE 10
using namespace std;

// First hash function
int h1(int key) {
    return key % SIZE;
}

// Second hash function for double hashing
int h2(int key) {
    return (7 - (key % 7));  // Ensures a step size for probing
}

// Double hashing probe function for insertion
int h0(int H[], int key) {
    int i = 0;
    // Probe using double hashing until an empty spot is found
    while (H[(h1(key) + (i * h2(key))) % SIZE] != 0) 
        i++;
    return (h1(key) + (i * h2(key))) % SIZE;
}

// Insert key using double hashing
void Insert(int H[], int key) {
    int index = h1(key);  // Calculate initial index using the first hash function
    if (H[index] != 0) {  // If there's a collision, use double hashing to find the next available spot
        index = h0(H, key);
    }
    H[index] = key;
}

// Search key using double hashing
int Search(int H[], int key) {
    int i = 0;
    int index = h1(key);  // Calculate initial index using the first hash function
    // Search for the key using double hashing
    while (H[(index + i * h2(key)) % SIZE] != key) {
        if (H[(index + i * h2(key)) % SIZE] == 0)  // If an empty spot is found, the key is not present
            return -1;
        i++;
        if (i >= SIZE)  // Prevent infinite loop if the table is full or key is not found
            return -1;
    }
    return (index + i * h2(key)) % SIZE;  // Return the index where the key is found
}

int main() {
    int HT[SIZE] = {0};  // Initialize hash table with all entries set to 0 (empty)
    
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 26);
    
    // Display the hash table
    for (int i = 0; i < SIZE; i++) {
        cout << HT[i] << " ";
    }
    cout << endl;
    
    // Try searching for key 26
    int key = 26;
    int index = Search(HT, key);
    if (index != -1)
        cout << "Key " << key << " found at index " << index << endl;
    else
        cout << "Key " << key << " not found!" << endl;
    
    return 0;
}
