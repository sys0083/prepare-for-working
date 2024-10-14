#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
double sum[N];
int cows[N];
int n, m;

bool check(double avg) {
    for (int i = 1; i <= n; ++ i) sum[i] = sum[i - 1] - avg + cows[i];
    
    double minv = 2000;
    for (int i = 0, j = m; j <= n; ++ i, ++ j) {
        minv = min(minv, sum[i]);
        if (sum[j] >= minv) return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> cows[i];
    double l = 0, r = 2000;
    while (r - l > 1e-5) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << int (1000 * r) << endl;
    
    return 0;
}