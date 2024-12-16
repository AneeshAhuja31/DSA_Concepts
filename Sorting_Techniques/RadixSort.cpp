#include<iostream>
using namespace std;

// Function to get the maximum value in the array
int findMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp (1's, 10's, 100's place)
void BinDigitCount(int A[],int n,int exp){
    int output[n]; // Output array to store sorted numbers
    int count[10] = {0}; // There are 10 possible digits (0-9)

    // Store the count of occurrences of each digit
    for(int i=0;i<n;i++){
        int digit = (A[i]/exp)%10;
        count[digit]++;
    }

    // Update count[i] to contain the actual position of the digits
    //After this loop runs, the count[] array contains the cumulative frequency of the digits
    for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1];
    //now count[i] represents the last known index in output of digit i

    // Build the output array
    for(int i=n-1;i>=0;i--){  //loop start from end of loop
        int digit = (A[i]/exp)%10;
        output[count[digit]-1] = A[i];   //filling output array based upon digit order
        count[digit]--;  // after assignment of the element based on their digit count of that digit is reduced to give index of another element with the same digit
    } 

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) 
        A[i] = output[i];
}

void RadixSort(int A[],int n){
    int max = findMax(A,n); // Get the maximum number in the array

    //Perform BinCount for each digit. The exponent exp represents 1's, 10's, 100's, etc.
    for(int exp=1;max/exp>0;exp*=10)
        BinDigitCount(A,n,exp);
}

int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A) / sizeof(A[0]);

    RadixSort(A, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}