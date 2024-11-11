#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long i64;

void solve() {
    int n; cin >> n;
    vector <i64> a(n), id(n);
    for (int i = 0;i < n; ++ i) {
        cin >> a[i];
    }
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int x, int y){return a[x] > a[y];});
    i64 ans = 0, tot = 0;
    for (int i = 0;i < n; ++ i) {
        i64 tmp = 1ll * (a[id[i]]) * (i+1) * (i+1);
        if (ans < tmp) {
            ans = tmp, tot = i+1;
        }
    }
    cout << tot << endl;
    sort(id.begin(), id.begin() + tot);
    for(int i = 0;i < tot; ++ i) {
        cout << id[i] + 1 << " ";
    }

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