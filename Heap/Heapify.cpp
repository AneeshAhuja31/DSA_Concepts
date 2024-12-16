#include<iostream>
using namespace std;

void Heapify(int A[],int n){
    //Start from the last non leaf node (whose index is n/2) and heapify each node iteratively
    for(int i=n/2;i>=1;i--){
        int largest=i ;
        int left=2*largest; //Left Child
        int right=2*largest+1; //Right Child

        //Heapify current node iteratively
        while(largest<=n/2){  // Loop while 'largest' has at least one child (n/2 is the last non leaf node)
            left = 2 * largest;
            right = 2 * largest + 1;

            // Compare with left child
            if (left <= n && A[left] > A[largest]) {
                largest = left;
            }
            
            // Compare with right child
            if (right <= n && A[right] > A[largest]) {
                largest = right;
            }
            // If largest is not the original root, swap
            if (largest != i) {
                swap(A[i], A[largest]);
                i = largest;  // Move the index to the swapped child and continue
            } 
            else {
                break;  // Stop if heap property is satisfied
            }
        }
    }
}
int main() {
    // 0 is a dummy value to make the array 1-based indexing
    int A[] = {0, 3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int size = sizeof(A) / sizeof(A[0]) - 1;  // Calculate size excluding dummy

    // Build a max-heap
    Heapify(A, size);

    cout << "Max-Heap: ";
    for (int i = 1; i <= size; i++) {
        cout << A[i] << " ";
    }
    return 0;
}