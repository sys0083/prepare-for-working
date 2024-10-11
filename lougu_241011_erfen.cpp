#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int x, y, m;
	cin >> x >> y >> m;
	double l = 0, r = 300, mid;  // 对率区间进行二分，这里用的百分制 
	double err = 0.001;
	while (r - l > err) {
		mid = (l + r) / 2; 
		double w = x;
		for (int i = 0; i < m; ++ i) {
			w = w - y + mid/100 * w;
		}
		if (w < err) {
			l = mid;  //钱还完了，说明利率小了 
		} else {
			r = mid;  // 钱没还完，说明利率大了 
		}
	}
	printf("%0.1lf", l);
	
	return 0;
}
