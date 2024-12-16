#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    Node* next; // Pointer to the next term in the polynomial
} *poly = NULL;

void Create() {
    Node *t, *last = NULL;
    int num, i;
    cout << "Enter number of terms: ";
    cin >> num;
    cout << "\nEnter each term with coeff and exp:\n";
    for (i = 0; i < num; i++) {
        t = new Node;
        cin >> t->coeff >> t->exp;
        t->next = NULL;  // Initialize next to NULL
        
        if (poly == NULL) {
            poly = last = t;  // First node
        } else {
            last->next = t;   // Link the new node
            last = t;         // Move last to the new node
        }
    }
}

long Eval(Node* p, int x) {
    long val = 0;
    while (p) {
        val += p->coeff * pow(x, p->exp);  // Evaluate the term and add to val
        p = p->next;  // Move to the next term
    }
    return val;
}

void Display(Node* p) {
    while (p != NULL) {
        cout << p->coeff << "x^" << p->exp;
        if (p->next != NULL) cout << " + ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    Create();
    Display(poly);
    int x;
    cout << "Enter value of x: ";
    cin >> x;
    long ans = Eval(poly, x);
    cout << "The value of the polynomial at x = " << x << " is: " << ans << endl;
    return 0;
}
