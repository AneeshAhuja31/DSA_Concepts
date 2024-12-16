#include<iostream>
using namespace std;

void Insert(int H[], int n) {
    int i = n, temp;
    temp = H[i];
    while (i > 1 && temp > H[i / 2]) { // Max-Heap condition
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}

int Delete(int A[], int n) {
    int x = A[n]; // storing last element
    int i, j;
    int val = A[1]; // storing deleted root
    A[1] = A[n]; // putting last element at first index
    A[n] = val; // placing the root at the end
    i = 1, j = 2 * i;

    while (j < n) {
        if (j + 1 < n && A[j + 1] > A[j]) // compare children
            j = j + 1;
        if (A[i] < A[j]) { // compare parent and child
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        } else {
            break;
        }
    }
    return val;
}

int main() {
    int H[] = {0, 2, 5, 8, 9, 4, 10, 7}; // First element is dummy for 1-based index
    int size = sizeof(H) / sizeof(H[0]) - 1;

    for (int i = 2; i <= size; i++) {
        Insert(H, i);
    }

    cout << "After inserting elements: ";
    for (int i = 1; i <= size; i++) {
        cout << H[i] << " ";
    }
    cout << endl;

    cout<<"After Sorting: ";
    for(int i=size;i>=1;i--)
        Delete(H,i);
    for (int i = 1; i <= size; i++) {
        cout << H[i] << " ";
    }
    return 0;
}
