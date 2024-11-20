#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

vector<int> v;
void pre_cal(int n) {
    queue<int> q;
    q.push(6); q.push(9);
    while (!q.empty()) {
        int val = q.front();
        if (val * 10 + 6 <= n) q.push(val * 10 + 6);
        if (val * 10 + 9 <= n) q.push(val * 10 + 9);
        v.push_back(val); 
        q.pop();
    }
    sort(v.begin(), v.end());
}

int cal(int l, int r) {
    auto lw = lower_bound(v.begin(), v.end(), l);
    auto h = upper_bound(v.begin(), v.end(), r);
    return h - lw;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pre_cal(1e18);
    int t = 1; cin >> t;
    while(t--) {
        int l, r; cin >> l >> r;
        cout << cal(l, r) << '\n';
    }
    return 0;
}
