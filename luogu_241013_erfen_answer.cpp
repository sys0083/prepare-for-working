#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int l, n, k;

const int N = 100010;
int pos[N];

bool check(int x) {
    int st = 0;
    int cnt = 0;
    for (int i = 2; i <= n; ++ i) {
        while (pos[i] - st > x) {
            st += x;
            cnt ++;
            if (cnt > k) return true;  // 这里要加上一个特判，不然TLE
        }
        st = pos[i];
    }
    return false;
}

int main() {
    cin >> l >> n >> k;
    for (int i = 1;i <= n; ++ i) {
        cin >> pos[i];
    }
    sort(pos + 1, pos + n + 1);
    int left = -1, right = l + 1;
    int mid;
    while (left + 1 < right) {
        mid = (left + right) >> 1;
        if (check(mid)) left = mid;
        else right = mid;
    }
    cout << right << endl;


    return 0;
}
