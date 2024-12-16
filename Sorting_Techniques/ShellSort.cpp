#include<iostream>
using namespace std;
void ShellSort(int A[], int n) {
    int gap, i, j;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            int temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp) {
                A[j + gap] = A[j];
                j -= gap;
            }
            A[j + gap] = temp;
        }
    }
}

int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A) / sizeof(A[0]);

    ShellSort(A, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}