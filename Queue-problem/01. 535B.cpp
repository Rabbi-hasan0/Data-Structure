#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
int n;
int solved() {
    queue<int> qu;
    qu.push(4);
    qu.push(7);
    int ans = 0;
    while(1) {
        if(qu.empty()) {
            break;
        }
        int x = qu.front() * 10 + 4;
        if(x <= n) {
           qu.push(x); 
        }
        x = qu.front() * 10 + 7;
        if(x <= n) {
           qu.push(x); 
        }
        if(qu.front() <= n) ans++;
        qu.pop();
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--){
        cin >> n;
        print(solved());
    }
    return 0;
}
