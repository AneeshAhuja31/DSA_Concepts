#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the linked list
void Insert(Node*& b, int x) {  //call by reference
    Node* p = b;
    Node* t;
    
    // Create a new node
    t = new Node;
    t->data = x;
    t->next = NULL;

    // If list is empty, insert at head
    if (b == NULL) {
        b = t;
    } else {
        // Traverse to the end of the list
        while (p->next != NULL) 
            p = p->next;
        p->next = t;  // Insert at the end
    }
}

// Function to delete and return the first node from the linked list
int Delete(Node*& b) {   //call by reference
    Node* p = b;
    int x = -1;

    // If the list is not empty
    if (p != NULL) {
        x = p->data;
        b = p->next;  // Move head to the next node
        delete p;      // Delete the old head
    }

    return x;
}

// Function to find the maximum element in an array
int findMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

// Function to perform Bin Sort
void BinSort(int A[], int n) {
    int max = findMax(A, n);
    Node** Bins; // Double pointers because Bins is an Array of pointers to Node
    Bins = new Node*[max + 1]; 

    // Initialize bins elements to NULL
    for (int i = 0; i <= max; i++) 
        Bins[i] = NULL;

    // Insert elements into bins
    for (int i = 0; i < n; i++) 
        Insert(Bins[A[i]], A[i]);

    // Collect sorted elements from bins
    int i = 0, j = 0;
    while (i <= max) { //while loop with dual purpose which are to empty Bins[i] and to traverse through Bins
        if (Bins[i] != NULL) 
            A[j++] = Delete(Bins[i]);
        else 
            i++; //i will only increase if Bins[i] is empty
    }
}

int main() {
    int A[] = {1, 3, 7, 12, 16, 9, 24, 5, 1, 3};
    int n = 10;

    BinSort(A, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
