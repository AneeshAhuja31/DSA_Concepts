#include<iostream>
using namespace std;

class UpperTri {
private:
    int* A;
    int n;
public:
    // Constructor definitions
    UpperTri() {
        n = 2;
        A = new int[2 * (2 + 1) / 2];
    }
    UpperTri(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~UpperTri() {
        delete[] A;
    }

    // Function prototypes
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

// Set function definition
void UpperTri::Set(int i, int j, int x) {
    if (i <= j)
        A[j * (j - 1) / 2 + (i - 1)] = x;
}

// Get function definition
int UpperTri::Get(int i, int j) {
    if (i <= j)
        return A[j * (j - 1) / 2 + (i - 1)];
    return 0;
}

// Display function definition
void UpperTri::Display() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j)
                cout << A[j * (j - 1) / 2 + (i - 1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    UpperTri lm(d);

    int x;
    cout << "Enter All Elements: " << endl;
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            cin >> x;
            lm.Set(i, j, x);
        }
    }

    cout << "The Upper Triangular Matrix is: " << endl;
    lm.Display();

    return 0;
}
