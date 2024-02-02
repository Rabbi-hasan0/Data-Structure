
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N], tree[4 * N];

// Build segment tree
void build_seg_tree(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    build_seg_tree(2 * node, l, (l + r)/ 2);
    build_seg_tree(2 * node + 1, ((l + r)/ 2) + 1, r);
}

// Display segment tree

// void print_seg_tree(int node, int l, int r){
//     cout << "[" << l + 1 << ", " << r + 1 << "] = " << tree[node] << '\n';
//     if(l != r){
//         int mid = (l + r) / 2;
//         print_seg_tree(2 * node, l, mid);
//         print_seg_tree(2 * node + 1, mid + 1, r);
//     }
// }

void print_seg_tree(int node, int l, int r){
    if(l == r){
        cout << "[" << l + 1 << ", " << r + 1 << "] = " << tree[node] << '\n';
        return;
    }
    int mid = (l + r) / 2;
    print_seg_tree(2 * node, l, mid);
    print_seg_tree(2 * node + 1, mid + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; // cin >> t;
    while (t--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        // call for Build segment tree
        build_seg_tree(1, 0, n - 1);
        // call for Print segment tree
        print_seg_tree(1, 0, n - 1);
    }
    return 0;
}
