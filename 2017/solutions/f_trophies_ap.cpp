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
ll const PH = 257;
ll const mod = 1e9 + 9;
ll const sz = 1e6 + 3;
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
			return (1LL * hash<int>()(a.first) * PH + 1LL * hash<int>()(a.second)) % mod;
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

vector <int> g[200100];
ll a[200100];
ll mx[200100];

ll calcmx(int v, int pr) {
	mx[v] = a[v];
	for (int to : g[v]) if (to != pr) mx[v] = max(mx[v], calcmx(to, v));
	return mx[v];
}

void dfs(int v, int pr, ll & ans, ll out) {
	if (out != -INF) ans = max(ans, mx[v] + out);
	pair <ll, ll> ch = { -INF, -INF };
	for (int to : g[v]) if (to != pr) {
		if (ch.second < mx[to]) ch.second = mx[to];
		if (ch.first < ch.second) swap(ch.second, ch.first);
	}
	for (int to : g[v]) if (to != pr) {
		if (mx[to] == ch.first) dfs(to, v, ans, max(out, ch.second)); else dfs(to, v, ans, max(out, ch.first));
	}
}

ll solve(int n) {
	calcmx(1, -1);
	ll ans = -INF;
	dfs(1, -1, ans, -INF);
	return (ans == -INF) ? -1 : ans;
}

int main() {
	unsigned int start = clock();
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("trophies.in", "r", stdin);
	freopen("trophies.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		int v, w;
		cin >> v >> w;
		g[v].push_back(w);
		g[w].push_back(v);
	}
	ll ans = solve(n);
	cout << ans;
#ifdef _DEBUG
	cout << endl << clock() - start;
#endif 
	return 0;
}
