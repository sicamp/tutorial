#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 41;

struct ST {
	int sz;
	vector<int> t;
	ST() {}

	void build(const vector<pair<int, int>> &data, const vector<int> &deg, int v = 0, int l = 0, int r = -1) {
		if (r == -1) r = sz;
		if (l + 1 == r) {
			t[v] = deg[data[l].second];
			return;
		}
		int m = (l + r) / 2;
		build(data, deg, v * 2 + 1, l, m);
		build(data, deg, v * 2 + 2, m, r);
		t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
	}

	ST(const vector<pair<int, int>> &data, const vector<int> &deg) {
		sz = data.size();
		t.resize(sz * 4);
		for (int &x : t) x = INF;
		build(data, deg);
	}

	int getMin(int L, int R, int v = 0, int l = 0, int r = -1) {
		if (r == -1) r = sz;
		if (L >= r || l >= R) return INF;
		if (L <= l && r <= R) return t[v];
		int m = (l + r) / 2;
		return min(getMin(L, R, v * 2 + 1, l, m), getMin(L, R, v * 2 + 2, m, r));
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> deg(n, 0);
	vector<int> l(n), r(n);
	vector<pair<int, int>> ls(n), rs(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		ls[i] = {l[i], i};
		rs[i] = {r[i], i};
	}	
	sort(ls.begin(), ls.end());
	sort(rs.begin(), rs.end());

	for (int i = 0; i < n; i++) {
		int mor = ls.end() - upper_bound(ls.begin(), ls.end(), make_pair(r[i], n));
		int les = lower_bound(rs.begin(), rs.end(), make_pair(l[i], 0)) - rs.begin();
		deg[i] = n - 1 - mor - les;			
	}

	//cout << "deg cnt" << endl;

	ST st_l(ls, deg);
	ST st_r(rs, deg);

	//cout << "st build" << endl;

	vector<int> ans(n, INF);
	for (int i = 0; i < n; i++) {
		int id = rs[i].second;
		int pos = lower_bound(rs.begin(), rs.end(), make_pair(l[id], 0)) - rs.begin();
		ans[id] = min(ans[id], st_r.getMin(pos, i + 1));
	}

	for (int i = n - 1; i >= 0; i--) {
		int id = ls[i].second;
		int pos = upper_bound(ls.begin(), ls.end(), make_pair(r[id], n)) - ls.begin();
		ans[id] = min(ans[id], st_l.getMin(i, pos));
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (D) cout << " ";
		else cout << "\n";
	}
	if (D) cout << "\n";
}

int main() {
	int tst = 1;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 5;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}
