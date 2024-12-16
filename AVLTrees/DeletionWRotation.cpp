#include<iostream>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    int height;
    Node* rchild;
}*root = NULL;

int NodeHeight(Node* p) {
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(Node* p) {
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node* LLRotation(Node* p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p) root = pl;
    return pl;
}

Node* RRRotation(Node* p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p) root = pr;
    return pr;
}

Node* LRRotation(Node* p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->rchild = pl;
    plr->lchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p) root = plr;
    return plr;
}

Node* RLRotation(Node* p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if (root == p) root = prl;
    return prl;
}

Node* InPre(Node* p) {
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

Node* InSucc(Node* p) {
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node* Delete(Node* p, int key) {
    if (p == NULL)
        return NULL;

    // Traversal for deletion like in a normal BST
    if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    else {
        // Node found to delete
        if (p->lchild == NULL && p->rchild == NULL) {
            delete p;
            return NULL;
        }
        else if (p->lchild != NULL) {
            Node* q = InPre(p->lchild); // Get inorder predecessor
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data); // Delete predecessor
        }
        else {
            Node* q = InSucc(p->rchild); // Get inorder successor
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data); // Delete successor
        }
    }

    // Update height after deletion
    p->height = NodeHeight(p);

    // Balancing the node after deletion
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) >= 0)
        return LLRotation(p);
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) <= 0)
        return RRRotation(p);
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}