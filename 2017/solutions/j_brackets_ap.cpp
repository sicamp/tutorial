#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> par;
typedef pair <ll, ll> parll;
int const INF = 1e9 + 7;
ll const LLINF = 1e18 + 7;
ld const eps = 1e-8;
ld const PI = acos(-1);
ll const p_hash = 257;
ll const mod = 1e9 + 9;
bool operator == (par a, par b) {
	return (a.first == b.first && a.second == b.second);
}
par operator + (par a, par b) {
	return{ a.first + b.first, a.second + b.second };
}
par operator - (par a, par b) {
	return{ a.first - b.first, a.second - b.second };
}
bool operator < (par const& a, par const& b) {
	return a.first < b.first || (a.first == b.first && a.second < b.second);
}
istream& operator >> (istream& in, par & a) {
	return (in >> a.first >> a.second);
}
ostream& operator << (ostream& ou, par a) {
	return (ou << a.first << " " << a.second << endl);
}
namespace std {
	template <>
	struct hash <par> {
		std::size_t operator ()(const par& a) const {
			using std::size_t;
			using std::hash;
			return (1LL * hash<int>()(a.first) * p_hash + 1LL * hash<int>()(a.second)) % mod;
		}
	};
}
bool eq(ld const& a, ld const& b) {
	return (a - b < eps && a - b > -eps);
}
bool less(ld const& a, ld const& b) {
	return (a - b < -eps);
}
void print_vector(vector <int> & a) {
	cout << a.size() << '\n';
	for (int i : a) cout << i << ' ';
	cout << '\n';
}

par a[100100];
par tree[400100];
ll o = 1;

par merge(par a, par b) {
	return{ a.first + max(0, b.first - a.second), b.second + max(0, a.second - b.first) };
}

void build(int n) {
	while (o <= n) o *= 2;
	for (int i = o; i < o + n; i++) tree[i] = a[i - o];
	for (int i = o + n; i < o + o; i++) tree[i] = { 0, 0 };
	for (int i = o - 1; i > 0; i--) tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

par get(int v, int lv, int rv, int l, int r) {
	if (l <= lv && rv <= r) return tree[v];
	if (rv <= l || r <= lv) return{ 0, 0 };
	int mv = lv + rv >> 1;
	return merge(get(2 * v, lv, mv, l, r), get(2 * v + 1, mv, rv, l, r));
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int b = 0;
	for (int i = 0; i < n; i++) a[i] = { (s[i] == ')'), (s[i] == '(') };
	build(n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		par cur = get(1, 0, o, l, r);
		cout << cur.first + cur.second << endl; 
	}
	return 0;
}
