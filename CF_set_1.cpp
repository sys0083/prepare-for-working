#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

void solve() {
    set<PII> st;
//	unordered_set<PII> st;  // 这里报错了，因为unordered_set需要为 pair 定义一个哈希函数和相等比较函数
    unordered_map<int, int> mp;
    int n; cin >> n;
    int x, y;
    for (int i = 0;i < n; ++ i) {
        cin >> x >> y;
        st.insert(make_pair(x,y));
        mp[x] ++;
    }
    LL ans = 0;
    for (auto m : mp) {
        if (m.second == 2) {
            ans += n-2;
        }
    }
    // 枚举水平直角三角形顶点 + set优化枚举左右顶点
    for (auto s : st) {
        x = s.first, y = s.second ^ 1;
        if (st.find(make_pair(x - 1,y)) != st.end() && st.find(make_pair(x + 1,y)) != st.end()) {
            ans ++;
        }
    }
    cout << ans << endl;
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
