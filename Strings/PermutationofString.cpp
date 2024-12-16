#include<iostream>
using namespace std;

void permutation(char s[], int k) {
    static int A[10] = {0};  // Array to keep track of used characters
    static char Result[10];  // Array to store current permutation

    if (s[k] == '\0') {  // Base condition: end of string
        Result[k] = '\0';  // Null-terminate the permutation
        cout << Result << endl;  // Print the permutation
    } else {
        for (int i = 0; s[i] != '\0'; i++) {
            if (A[i] == 0) {  // If the character is not yet used
                Result[k] = s[i];  // Add character to the current position
                A[i] = 1;  // Mark character as used
                permutation(s, k + 1);  // Recur for the next position
                A[i] = 0;  // Backtrack: Unmark the character as used
            }
        }
    }
}

int main() {
    char str[] = "ABC";
    permutation(str, 0);  // Start from index 0
    return 0;
}
