

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N], tree[4 * N];

// Assign value in tree[node] of array
void build_seg_tree(int node, int l, int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    build_seg_tree(2 * node, l, (l + r) / 2);
    build_seg_tree(2 * node + 1, ((l + r) / 2) + 1, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}


int query_solved(int node, int l, int r, int i, int j) {
    if (l >= i and r <= j) return tree[node];
    if (j < l or i > r) return -1;
    int left_node_value = query_solved(2 * node, l, (l + r) / 2, i, j);
    int right_node_value = query_solved(2 * node + 1, ((l + r) / 2) + 1, r, i, j);

    return (left_node_value + right_node_value);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        build_seg_tree(1, 0, n - 1);

        int q;cin >> q;
        while (q--) {
            int l, r;cin >> l >> r;
            int x = query_solved(1, 0, n - 1, l - 1, r - 1);
            cout << x << '\n';
        }
    }
    return 0;
}
