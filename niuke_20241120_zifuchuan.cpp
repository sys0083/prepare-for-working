#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long i64;

int n;
char a[210][220];

//// 原来实现的两个函数，感觉比较有意思。
//void nxt(int &i, int &j, int k) {
//    // 行 列 层数
//    if (j == n + k) { // 右侧
//        if (i == n - k + 1) {
//            j --;
//        }
//        else i --;
//    } else if (i == n - k + 1) { // 上方
//        if (j == n - k + 1) {
//            i ++;
//        }
//        else j --;
//    } else if (j == n - k + 1) { // 左侧
//        if (i == n + k) {
//            j ++;
//        }
//        else i ++;
//    } else { // 下方
//        if (j == n + k) {
//            i --;
//        }
//        else {
//            j ++;
//        }
//    }
//}
//
//bool find(int i, int j, int k, int cnt) {
//    while (cnt -- ) {
//        if (a[i][j] != 'X') return false;
//        nxt(i, j, k);
//    }
//    return true;
//}

void solve() {
    cin >> n;
    for (int i = 1;i <= 2 * n; ++ i) {
        scanf("%s", a[i] + 1);
    }
    vector<string> s(n);
    for (int i = 0; i < n; ++ i) {
        int r = n-i, c = n-i;
        for (; c < n + i + 1; ++ c) s[i] += a[r][c];
        for (; r < n + i + 1; ++ r) s[i] += a[r][c];
        for (; c > n - i; -- c) s[i] += a[r][c];
        for (; r > n - i; -- r) s[i] += a[r][c];
    }
    int ans = 1e9;
    for (int p = 0;p < 4; ++ p) {
        int res = 0;
        for (int i = 0;i < n; ++ i) {
            int nxt[4] = {i+1, 3*i+2, 5*i+3, 7*i+4};
            int end = 1;
            while (end < s[i].size()) {
                if (s[i][end] == 'X' && s[i][end-1] == 'O') break;
                end ++;
            }
            if (end == s[i].size()) end = 0;
            res += (nxt[p] + s[i].size() - end) % s[i].size();
        }
        ans = min(res, ans);
    }
    cout << ans << endl;
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
