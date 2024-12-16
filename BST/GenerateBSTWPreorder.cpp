#include <iostream>
#include <stack>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
} *root = NULL;

void CreatePre(int pre[], int n) {
    if (n == 0) return; // Handle the case where the array is empty

    std::stack<Node*> stk;
    Node* t, * p; // t is used to create nodes, p is a pointer
    int i = 0;

    // Create the root node
    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;  //Move pointer to root

    while (i < n) {
        if (pre[i] < p->data) { // If the next value is less than the current node, it goes to the left child
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p); // Push the greater node onto the stack
            p = t; // Move pointer to new node
        } 
        else { // If the next value is greater than the current node, it goes to the right child
            while (!stk.empty() && pre[i] > stk.top()->data) {  //while next element of array is greater than stacktop, keeping popping the stack and keep assigning popped nodes to pointer node in every iteration
                p = stk.top();
                stk.pop();
            }
            //after termination of loop assign the array element as the rchild of pointer node
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            p = t;
        }
    }
}

void Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

int main() {
    int pre[] = { 10, 5, 1, 8, 30 };
    int n = sizeof(pre) / sizeof(pre[0]);

    CreatePre(pre, n);

    cout << "Inorder Traversal of the constructed BST: ";
    Inorder(root);
    cout << endl;

    return 0;
}
