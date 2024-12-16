#include <iostream>
using namespace std;

int main() {
    char A[] = "finding";
    int H[26] = {0};  // Initialize all elements of H to 0

    // First loop to count occurrences of each character
    for (int i = 0; A[i] != '\0'; i++) {
        H[A[i] - 'a'] += 1;  // Increment the count for the corresponding character
    }

    // Loop to print characters that appear more than once
    for (int i = 0; i < 26; i++) {
        if (H[i] > 1) {
            printf("%c ", i + 'a');  // Print the character
            printf("%d\n", H[i]);    // Print the count of the character
        }
    }

    return 0;
}
