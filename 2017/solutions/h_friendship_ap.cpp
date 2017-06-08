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

struct pnt {
	int x; bool type; int num;
	pnt() {}
	pnt(int x, bool t, int num) : x(x), type(t), num(num) {};
	bool operator < (pnt const& o) const {
		if (x != o.x) return x < o.x;
		if (type != o.type) return type < o.type;
		return num < o.num;
	}
};

pnt line[400100];
bool got[400100];
unordered_set <int> open;

int main() {
	unsigned int start = clock();
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("friendship.in", "r", stdin);
	freopen("friendship.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		line[2 * i] = pnt(l, 0, i);
		line[2 * i + 1] = pnt(r, 1, i);
	}
	vector <int> ans;
	ans.clear();
	sort(line, line + 2 * n);
	for (int i = 0; i < 2 * n; i++) { 
		if (line[i].type == 0) open.insert(line[i].num); else {
			open.erase(line[i].num);
			if (!got[line[i].num]) {
				ans.push_back(line[i].x);
				got[line[i].num] = true;
				for (auto k = open.begin(); k != open.end(); k++) got[*k] = true;
				open.clear();
			}
		}
	}
	print_vector(ans);
#ifdef _DEBUG
	cout << endl << clock() - start;
#endif 
	return 0;
}
