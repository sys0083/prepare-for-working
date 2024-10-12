#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int l, n, m;

const int N = 100010;
int pos[N];

bool check(int x) {
    int st = pos[0];
    int cnt = 0; // 统计需要移动的石块的数量
    for (int i = 1; i <= n+1; ++ i) {
        if (pos[i] - st < x) {
            cnt ++;
        } else {
            st = pos[i];
        }
    }
    return cnt <= m;
}

int main() {
    cin >> l >> n >> m;
    for (int i = 1;i <= n; ++ i) {
        cin >> pos[i];
    }
    pos[0] = 0, pos[n+1] = l;
    int left = -1, right = l + 1;
    int mid;
    while (left + 1 < right) {
        mid = (left + right) >> 1;
        if (check(mid)) left = mid;
        else right = mid;
    }
    cout << left << endl;


    return 0;
}
