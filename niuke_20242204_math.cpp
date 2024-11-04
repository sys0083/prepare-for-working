#include <iostream>
#include <algorithm>
#include <set>
#include <array>
using namespace std;

const int N = 1010;
int x[N], y[N], n;

void solve() {
    cin >> n;
    for (int i = 0;i < n; ++ i) {
        cin >> x[i];
        x[i] = (x[i] + 100010) * 2;
    }
    for (int i = 0;i < n; ++ i) {
        cin >> y[i];
        y[i] = (y[i] + 100010) * 2;
    }
    set<array<int, 4>> a;
    for (int i = 0;i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            int nx = (x[i] + x[j]) / 2, ny = (y[i] + y[j]) / 2;
            int dx = -(ny - y[j]), dy = (nx - x[j]);
            if (dx < 0) {
                dx = -dx, dy = -dy;
            }
            int k;
            if (abs(dx) && abs(dy)) {
                int g = __gcd(dx, dy);
                dx /= g, dy /= g;
                k = nx / dx;
            }
            else {
                if (abs(dx)) {
                    k = nx;
                    dx = 1;
                } else {
                    dy = 1;
                    k = ny;
                }
            }
            int xx = nx - k * dx, yy = ny - k * dy;
            a.insert({xx, yy, dx, dy});
        }
    }
    cout << a.size() << endl;
}

int main() {
    int t;
    t = 1;
     cin >> t;
    while (t --) {
        solve();
    }

    return 0;
}