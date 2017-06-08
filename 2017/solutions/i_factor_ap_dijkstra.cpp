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

ll mul[10100];
ll dv[10100];
bool w[10100];
ll ans[10100];
vector <parll> d[10100];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> mul[i];
	for (int i = 1; i <= n; i++) {
		cin >> dv[i];
		ans[i] = mul[i];
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (i != j) {
			if (i % j == 0) d[i].push_back({ j, dv[i / j] });
			if (j % i == 0) d[i].push_back({ j, mul[j / i] });
		}
	}
	ans[1] = 0;
	for (int i = 0; i < n; i++) {
		ll m = LLINF, v = -1;
		for (int j = 1; j <= n; j++) if (!w[j] && ans[j] < m) {
			m = ans[j];
			v = j;
		}
		w[v] = true;
		for (parll to : d[v]) if (ans[to.first] > ans[v] + to.second) {
			ans[to.first] = ans[v] + to.second;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}
