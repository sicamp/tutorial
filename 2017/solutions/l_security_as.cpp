#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_MASK = 16;
const int MAXN = 1e5 + 10;

vector <vector <int> > g;
vector <vector <int> > col;
bool used[MAXN];
long long ans[MAX_MASK];

int dfs(int v, int mask) {
	int sum = 1;
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++) {
		int nxt = g[v][i];
		int color = col[v][i];
		if (used[nxt])
			continue;
		if ((1 << color) & mask)
			sum += dfs(nxt, mask);
	}
	return sum;
}

int main() {

	freopen("security.in", "r", stdin);
	freopen("security.out", "w", stdout);

	int n;
	cin >> n;
	g.resize(n); col.resize(n);
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--; c--;
		g[a].push_back(b);
		g[b].push_back(a);
		col[a].push_back(c);
		col[b].push_back(c);
	}

	long long answer = 0;
	for (int i = 1; i < MAX_MASK; i++) {
		for (int j = 0; j < n; j++) {
			if (!used[j]) {
				long long cur = dfs(j, i);
				ans[i] += (cur * (cur - 1)) / 2;
			}
		}
		for (int j = 0; j < n; j++) {
			used[j] = false;
		}
		for (int j = ((i - 1) & i); j; j = ((j - 1) & i)) {
			ans[i] -= ans[j];
		}
		answer += ans[i] * __builtin_popcount(i);
	}

	cout << answer;


	return 0;
}
