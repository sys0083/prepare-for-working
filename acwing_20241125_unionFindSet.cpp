#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010;
int p[N], d[N];

int find(int x) {
    if (x != p[x]) {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

signed main()
{
    int n, k; cin >> n >> k;
    for (int i = 1;i <= n; ++ i) p[i] = i;

    int t, x, y, ans = 0;
    for (int i = 1; i <= k; ++ i) {
        cin >> t >> x >> y;
        if (x > n || y > n) {
            ans ++;
            continue;
        }
        int px = find(x), py = find(y);
        if (t == 1) {
            // 在一棵树树上就判断，不在就插入
            if (px == py && (d[x] - d[y]) % 3 != 0) {
                ans ++;
            } else if (px != py) {
                p[px] = py;
                d[px] = d[y] - d[x]; // 存储相对于根节点的距离
            } else continue;
        } else {
            if (px == py && (d[x] - d[y] - 1) % 3 != 0) {
                ans ++;
            } else if (px != py) {
                p[px] = py;
                d[px] = d[y] + 1 - d[x];
            } else continue;
        }
    }
    cout << ans << endl;

    return 0;
}