Tree was given:
###Input:
           1
         /   \
        2     3
       / \   / \
      4   5 6   7


###Output:
  Pre-ordered:   1 2 4 5 3 6 7
  In-ordered:    4 2 5 1 6 3 7
  Post-ordered:  4 5 2 6 7 3 1


## Structure of BT:
```c++
struct Node {  
    int data;
    Node* left; 
    Node* right;
    Node(int val) {    
        data = val;
        left = right = NULL;   // Initialized;
    }
};
```
## Data assaign of BT:
```c++
void data_add() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preOrdered(root);
    inOrdered(root);
    postOrdered(root);
}
```

## Traversal of BT:
```c++
void preOrdered(Node *n) { //root-left-right
    if(!n) return;
    cout << n-> data << ' ';
    preOrdered(n->left);
    preOrdered(n->right);
}
void inOrdered(Node *n) {  //left-root-right
    if(!n) return;
    inOrdered(n->left);
    cout << n->data << ' ';
    inOrdered(n->right);
}
void postOrdered(Node *n) { //left-right-root
    if(!n) return;
    postOrdered(n->left);
    postOrdered(n->right);
    cout << n-> data << ' ';
}
```

```c++
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {   //Structure of a Binary Tree
    int data;
    Node* left; 
    Node* right;
    Node(int val) {    
        data = val;
        left = right = NULL;   // Initialized;
    }
};

void preOrdered(Node *n) { //root-left-right
    if(!n) return;
    cout << n-> data << ' ';
    preOrdered(n->left);
    preOrdered(n->right);
}

void inOrdered(Node *n) {  //left-root-right
    if(!n) return;
    inOrdered(n->left);
    cout << n->data << ' ';
    inOrdered(n->right);
}

void postOrdered(Node *n) { //left-right-root
    if(!n) return;
    postOrdered(n->left);
    postOrdered(n->right);
    cout << n-> data << ' ';
}

void data_add() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preOrdered(root);
    inOrdered(root);
    postOrdered(root);
}

int32_t main() {
    data_add();
    return 0;
}
```
