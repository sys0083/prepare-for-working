#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

typedef long long LL;

void solve() {
    int n, m; cin >> n >> m;
    vector<LL> p(n + 1), sum(n+1), sz(n+1); // p指链式并查集的根节点
    for (int i = 1;i <= n; ++ i) {
        cin >> sum[i];
        p[i] = i;
        sz[i] = 1;
    }
    auto find = [&](int x) -> int {
        while(x != p[x]) x = p[x] = p[p[x]];
        return x;
    };
    auto merge = [&](int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (u < v) swap(u, v); // 向右合并,保证u > v
        sum[u] += sum[v];
        sz[u] += sz[v];
        p[v] = p[u];
    };
    while (m -- ) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            while (l < r) {
                merge(l, l + 1);
                l = find(l);
            }
        } else {
            int i; cin >> i;
            i = find(i);
            double ans = (double) sum[i] / (double) sz[i];
            cout << fixed << setprecision(10) << ans << endl;
        }
    }
}

signed main() {
    int t;
    t = 1;
//     cin >> t;
    while (t --) {
        solve();
    }

    return 0;
}