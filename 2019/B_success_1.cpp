#include <stdio.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include<vector>
#include <istream>
#include<iomanip>
#include<stack>
using namespace std;

struct item {
	int tid;
	int x;
	int y;

	item(){}

	item(int _tid, int _x, int _y) {
		tid = _tid;
		x = _x;
		y = _y;
	}

	void scan() {
		cin >> tid >> x >> y;
	}
};

int lenght(int x, int y, int x1, int y1) {
	return abs(x - x1) + abs(y - y1);
}

bool cmp(item a, item b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}


int main(){
	int n, m;
	cin >> n >> m;
	vector<item> A(n), B(m);
	for (int i = 0; i < n; i++) {
		A[i].scan();
	}
	for (int i = 0; i < m; i++) {
		B[i].scan();
	}
	sort(B.begin(), B.end(), cmp);
	int ans = 1e9;
	int x = 0, y = 0;
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int l = lenght(A[j].x, A[j].y, B[i].x, B[i].y);
			if (A[j].tid != B[i].tid)
				l = l * 2;
			cnt += l;
		}
		if (ans > cnt) {
			ans = cnt;
			x = B[i].x;
			y = B[i].y;
		}
	}
	cout << ans << '\n';
//	cout << x << " " << y << '\n';

	return 0;
}
