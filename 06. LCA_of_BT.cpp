#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

bool findPath(Node* root, vector<int>& path, int k) {
  
    // base case
    if (!root)
        return false;

    // Store this node in path vector. The node will be
    // removed if not in path from root to k
    path.push_back(root->key);

    // See if the k is same as root's key
    if (root->key == k)
        return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) or (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root, remove
    // root from path[] and return false
    path.pop_back();
    return false;
}

int findLCA(Node* root, int n1, int n2) {
    vector<int> path1, path2;
    // n1 or n2 is not present, return -1
    if (!findPath(root, path1, n1) or !findPath(root, path2, n2))
        {return -1;}

    for (int i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i]) return path1[i - 1];  
    }
    return -1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
    cout << "LCA(4, 6) = " << findLCA(root, 4, 6) << endl;
    cout << "LCA(3, 4) = " << findLCA(root, 3, 4) << endl;
    cout << "LCA(2, 4) = " << findLCA(root, 2, 4) << endl;

    return 0;
}
