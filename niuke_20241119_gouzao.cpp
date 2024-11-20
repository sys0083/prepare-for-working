#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long i64;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector pre(n + 1, vector<int> (16, 0));

    auto calc = [](int x) {
        int ans = 0 ;
        if (x % 3 == 0) ans |= 1;
        if (x % 9 == 0) ans |= 2;
        if (x % 5 == 0) ans |= 4;
        if (x % 11 == 0) ans |= 8;
        return ans;
    };

    auto check = [&](int j, int x) {
        return (j | x) == 15 || ((j | x) == 13 && j & 1 && x & 1);
    };

    i64 ans = 0;
    for (int i = 1;i <= n; ++ i) {
        cin >> a[i];
        b[i] = calc(a[i]);

        for (int j = 0; j < 16; ++ j) {
            if (check(b[i], j))
                ans += pre[i-1][j];
        }
        pre[i] = pre[i-1];
        pre[i][b[i]] ++;
    }

    vector suf(n + 2, vector<int> (16, 0));
    for (int i = n;i >= 1; -- i) {
        suf[i] = suf[i+1];
        suf[i][b[i]] ++;
    }

    i64 max = 0;
    for (int i = 1;i <= n; ++ i) {
        int x = a[i];
        x ++;
        int mask = calc(x);

        i64 res = 0;
        for (int j = 0; j < 16; ++ j) if (check(mask, j)) res += pre[i-1][j];
        for (int j = 0; j < 16; ++ j) if (check(mask, j)) res += suf[i+1][j];

        for (int j = 0; j < 16; ++ j) if (check(b[i], j)) res -= pre[i-1][j];
        for (int j = 0; j < 16; ++ j) if (check(b[i], j)) res -= suf[i+1][j];
        max = std::max(max, res);
    }

    cout << ans + max << endl;


}

int main() {
    int t;
    t = 1;
//    cin >> t;
    while (t --) {
        solve();
    }


    return 0;
}
