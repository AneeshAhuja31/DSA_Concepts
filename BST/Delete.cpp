#include<iostream>
using namespace std;

struct Node{
    Node*lchild;
    int data;
    Node*rchild;
}*root=NULL;

void Insert(int key){
    Node*t=root;
    Node*r,*p;

    if(root==NULL){
        p = new Node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t){
        r=t; //we use r as parent node
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else  //when key==t->data
            return; //do nothing
    }
    p = new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;

    //link with parent node
    if(key<r->data) r->lchild=p;
    if(key>r->data) r->rchild=p;
}

int Height(Node*p){
    if(p==NULL) return 0;
    int x=Height(p->lchild);
    int y=Height(p->rchild);
    return x>y?x+1:y+1;
}

Node*InPre(Node*p){
    while(p && p->rchild)
        p=p->rchild;  //go to rightmost of the left subtree
    return p;
}

Node*InSucc(Node*p){
    while(p && p->lchild)
        p=p->lchild;  //go to leftmost of the right subtree
    return p;
}

Node*Delete(Node*p, int key){
    Node*q;
    if(p == NULL) return NULL;

    //Recursive Search
    if(key < p->data)
        p->lchild = Delete(p->lchild, key); //Equated p->lchild to update the current node
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key); //Equated p->rchild to update the current node
    
    else{
        if(p->lchild == NULL && p->rchild == NULL){  //Leaf Node Deletion process
            if(p == root)
                root = NULL;
            delete p;
            return NULL;
        }
        else if (p->lchild == NULL) { // Node with only right child (1*)
            Node* temp = p->rchild;
            delete p;
            return temp;
        }
        else if (p->rchild == NULL) { // Node with only left child (1*)
            Node* temp = p->lchild;
            delete p;
            return temp;
        }
        //2* node case
        if(Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;  // copy the value of the InPre to the node with the key value
            p->lchild = Delete(p->lchild, q->data);  //Delete the node which was previously the InPre or carry on if not leaf node and repeat process
                                                     //Until a leaf node is not found the recursion will carry on
        } 
        else {
            q = InSucc(p->rchild);
            p->data = q->data; //copy the value of the InSucc to the node with the key value
            p->rchild = Delete(p->rchild, q->data);  //Delete the node which was previously the InSucc or carry on if not leaf node and repeat process
                                                     //Until a leaf node is not found the recursion will carry on
        }
    }
    
    return p;  // Add this return statement to return the updated node to lchild/rchild
}

void Inorder(Node*p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

int main(){
    Insert(10);
    Insert(5);
    Insert(30);
    Insert(8);
    Insert(1);
    Inorder(root);
    cout << endl;
    
    // Deleting node with key 3 (does not exist, no changes to tree)
    root = Delete(root, 3);
    Inorder(root);
    cout << endl;
    // Deleting node with key 5 (exists in tree)
    root = Delete(root, 5);
    Inorder(root);
    cout << endl;
}