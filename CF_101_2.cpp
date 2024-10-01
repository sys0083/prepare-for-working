#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, k; // ¼ÇÂ¼Ê×Î²ÔªËØ

LL sum(LL l, LL r) {
    LL s = (LL)(l + r) * (r - l + 1) / 2;
    return s;
}

bool check(int mid) {
    return (sum(k, mid-1) - sum(mid, k + n - 1) < 0);
}

int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = (r - l + 1) / 2 + l;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    cin >> n >> k;
    int mid = bsearch_2(k, n + k - 1);
    cout << min(abs(sum(k, mid) - sum(mid + 1, k + n - 1)), abs(sum(k, mid - 1) - sum(mid, k + n - 1))) << endl;

}


int main()
{
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}
