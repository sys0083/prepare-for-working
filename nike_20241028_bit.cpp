#include <iostream>
#include <algorithm>
#include <vector>

const int INF = 0x3f3f3f3f;
int n, m, k;

int main() {
    std::cin >> n >> m;
    std::string str;
    std::vector<int> a(n);
    for (int i = 0;i < n; ++ i) {
        std::cin >> str;
        for (int j = 0;j < m; ++ j) {
            if (str[j] == '1') a[i] |= (1<<j);
        }
    }
    std::cin >> k;
    std::vector<int> b(k);
    for (int i = 0;i < k; ++ i) {
        std::cin >> str;
        for (int j = 0;j < m; ++ j) {
            if (str[j] == '1') b[i] |= (1<<j);
        }
    }
    
    for (int i = 0; i < n; ++ i) {
        int ans = INF;
        for (int mask = 0; mask < (1 << k); ++ mask) {
            int x = 0, cnt = 0;
            for (int j = 0; j < k; ++ j) {
                if (mask >> j & 1) x |= b[j], cnt ++;
            }
            if ((a[i] & x) == a[i]) ans = std::min(ans, cnt);
        }
        if (ans == INF) puts("-1");
        else std::cout << ans << std::endl;
    }
    
    return 0;
}