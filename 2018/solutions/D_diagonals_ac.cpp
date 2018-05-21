#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct diagonal {
	int len;
	int ind;
	long long sum;
	long long max;
	diagonal() : len(0), sum(0), max(0), ind(0) {}
	diagonal(int ind, int l, long long s, long long m) : ind(ind), len(l), sum(s), max(m) {}
};

bool cmp(const diagonal & a, const diagonal & b) {
	return a.len < b.len ||
		a.len == b.len && a.sum < b.sum ||
		a.len == b.len && a.sum == b.sum && a.max < b.max;
}

int main() {

	ifstream cin("diagonals.in");
	ofstream cout("diagonals.out");

	int n, m;
	cin >> n >> m;
	vector<vector<long long>> matr(n);
	for (auto & l : matr) {
		l.resize(m);
		for (auto & e : l) {
			cin >> e;
		}
	}

	vector<diagonal> d(n + m - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int d_num = i + j;
			d[d_num] = { i + j, d[d_num].len + 1, d[d_num].sum + matr[i][j], max(d[d_num].max, matr[i][j]) };
		}
	}

	sort(d.begin(), d.end(), cmp);

	for (auto & e : d) {
		cout << e.ind + 1 << ' ';
	}

	return 0;
}