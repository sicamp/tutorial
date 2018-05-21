#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);


	int n, k;
	cin >> n >> k;

	vector <int> v(n + k);
	for (int i = 0; i < n + k; i++) {
		cin >> v[i];
	}

	int d;
	cin >> d;

	vector <vector <int> > inds(k, vector <int>(n + 1, -1));
	vector <vector <int> > dp(k, vector <int>(n + 1, 0));
	for (int j = 0; j <= n; j++) {
		dp[0][j] = v[j];
	}
	for (int i = 1; i < k; i++) {
		int mn = dp[i - 1][0], mnj = 0;
		for (int j = 0; j <= n; j++) {
			if (mn + (j - mnj)*d > dp[i - 1][j]) {
				mn = dp[i - 1][j];
				mnj = j;
			}
			dp[i][j] = dp[i - 1][mnj] + d * (j - mnj) + v[j + i];
			inds[i][j] = mnj;
		}
	}

	vector <int> ans(k);
	int mn = dp[k - 1][0];
	int mnj = 0;
	for (int j = 1; j <= n; j++) {
		if (mn > dp[k - 1][j]) {
			mn = dp[k - 1][j];
			mnj = j;
		}
	}
	ans[k - 1] = mnj + k - 1;
	for (int i = k - 1; i > 0; i--) {
		mnj = inds[i][mnj];
		ans[i - 1] = mnj + i - 1;
	}

	cout << mn << "\n";
	for (int i = 0; i < k; i++) {
		cout << ans[i] + 1 << " ";
	}
}
