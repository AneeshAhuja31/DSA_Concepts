#include<iostream>
#define SIZE 10
using namespace std;

int hasher(int key){
    return key % SIZE;
}

// Quadratic probing
int quadprobe(int H[], int key){
    int index = hasher(key);
    int i = 0;
    while (H[(index + i*i) % SIZE] != 0)  // Using quadratic probing properly
        i++;
    return (index + i*i) % SIZE;
}

void Insert(int H[], int key){
    int index = hasher(key);
    if (H[index] != 0)
        index = quadprobe(H, key);
    H[index] = key;
}

// Search function with quadratic probing
int Search(int H[], int key){
    int index = hasher(key);
    int i = 0;
    while (H[(index + i*i) % SIZE] != key) {
        if (H[(index + i*i) % SIZE] == 0)  // If an empty slot is found, the key is not present
            return -1;
        i++;
        if (i >= SIZE)  // Prevent infinite loop in case of full table
            return -1;
    }
    return (index + i*i) % SIZE;  // Return index of the found key
}

int main(){
    int HT[SIZE] = {0};  // Initialize hash table with 0 (empty slots)
    
    Insert(HT, 12);
    Insert(HT, 25);
    Insert(HT, 35);
    Insert(HT, 75);
    
    for (int i = 0; i < SIZE; i++) {
        cout << HT[i] << " ";
    }
    cout << endl;
    
    int key = 75;
    int index = Search(HT, key);
    if (index != -1)
        cout << "Key " << key << " found at index " << index << endl;
    else
        cout << "Key " << key << " not found!" << endl;
    
    return 0;
}
