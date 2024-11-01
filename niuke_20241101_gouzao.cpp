#include <iostream>
#include <algorithm>
#include <vector>
#include<numeric>

const int INF = 0x3f3f3f3f;

typedef long long i64;

int main() {
    i64 n, m, p;
    std::cin >> n >> m;
    p = m;

    std::vector<i64> a(n+1, 0);
    int st = 1 + (((p & 1) && ((n / 2) & 1)) || ((p % 2 == 0) && ((n / 2) % 2 == 0)));
    for (int i = st; i <= n; i += 2, m--) a[i] ++;

    m /= 2;
    i64 tmp = m / n;
    m %= n;

    for (int i = 1;i <= n; ++ i) a[i] += 2*tmp;
    for (int i = st ^ 3; i <= n && m != 0; i += 2, m --) a[i] += 2;
    for (int i = st; i <= n && m; i += 2, m --) a[i] += 2;

    i64 sum = std::accumulate(a.begin(), a.end(), 0ll);
    if (sum != p) {
        std::cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; i ++) std::cout << a[i] << " ";

    return 0;
}