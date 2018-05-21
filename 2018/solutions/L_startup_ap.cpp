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
#include <cassert>
#include <bitset>
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> par;
typedef pair<ll, ll> parll;
int const INF = 1e9 + 7;
ll const LLINF = 1e18 + 7;
ld const eps = 1e-10;
ld const PI = acos(-1);
ll const PH = 257;
ll const PH1 = 359;
ll const mod = 1e9 + 9;
ll const mod1 = 1e9 + 7;

par operator + (par const& a, par const& b) {
	return{ a.first + b.first, a.second + b.second };
}
int operator - (par const& a, par const& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
bool operator == (par const& a, par const& b) {
	return (a.first == b.first && a.second == b.second);
}
bool operator != (par const& a, par const& b) {
	return (a.first != b.first || a.second != b.second);
}
bool operator == (parll const& a, parll const& b) {
	return (a.first == b.first && a.second == b.second);
}
bool operator < (par const& a, par const& b) {
	return (a.first < b.first || (a.first == b.first && a.second < b.second));
}
istream& operator >> (istream& in, par & a) {
	return (in >> a.first >> a.second);
}
ostream& operator << (ostream& ou, par a) {
	return (ou << a.first << ' ' << a.second << '\n');
}
istream& operator >> (istream& in, parll & a) {
	return (in >> a.first >> a.second);
}
ostream& operator << (ostream& ou, parll a) {
	return (ou << a.first << ' ' << a.second << '\n');
}

namespace std {
	template <>
	struct hash<par> {
		std::size_t operator ()(par const& a) const {
			using std::hash;
			using std::size_t;
			return size_t((1LL * hash<int>()(a.first) * PH + hash<int>()(a.second)) % mod);
		}
	};
}

inline ll randll() {
	ll res = rand();
	for (int i = 0; i < 3; i++) {
		res <<= 16;
		res += rand();
	}
	return res;
}

inline ld log(ld a, ld b) {
	return (log(b) / log(a));
}

string a[310];
vector <parll> h[310];
pair <ll, ll> st[100100];

void calc(int k) {
	vector <parll> hs;
	hs.clear();
	hs.push_back({ 0, 0 });
	for (int i = 0; i < a[k].size(); i++) {
		hs.push_back({ (hs.back().first * PH + a[k][i]) % mod, (hs.back().second * PH1 + a[k][i]) % mod1 });
	}
	h[k] = hs;
}

pair <ll, ll> substr(int i, int l, int r) {
	return{ (h[i][r].first - h[i][l].first * st[r - l].first % mod + mod + mod) % mod, (h[i][r].second - h[i][l].second * st[r - l].second % mod1 + mod1 + mod1) % mod1};
}

bool eq(int i, int j, int len) {
	return substr(i, a[i].size() - len, a[i].size()) == substr(j, 0, len);
}

int nd[310][310];
int dp[310][310];
par pr[310][310];
int priority[310];
int npriority[310];
int was[310];

string makestr(int id, int k) {
	vector <int> seq;
	for (par cur = make_pair(id, k); cur.first != -1; cur = pr[cur.first][cur.second]) seq.push_back(cur.first);
	reverse(seq.begin(), seq.end());
	string res = a[seq[0]];
	for (int i = 1; i < seq.size(); i++) for (int j = a[seq[i]].size() - nd[seq[i - 1]][seq[i]]; j < a[seq[i]].size(); j++) res += a[seq[i]][j];
	return res;
}

int main() {
	freopen("startup.in", "r", stdin);
	freopen("startup.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if (!k) return 0;
	st[0] = { 1, 1 };
	for (int i = 1; i <= 100000; i++) {
		st[i].first = st[i - 1].first * PH % mod;
		st[i].second = st[i - 1].second * PH1 % mod1;
	}
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)	calc(i);
	
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		int len = 0;
		int common = 0;
		for (len = 1; len < min(a[i].size(), a[j].size()); len++) {
			if (eq(i, j, len)) common = len;
		}	
		nd[i][j] = a[j].size() - common;
	}
	//cerr << substr(1, 1, 7) << substr(3, 0, 6);
	for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) {
		dp[i][j] = INF;
		pr[i][j] = { -1, -1 };
	}
	vector <int> order;
	for (int i = 0; i < n; i++) {
		dp[i][1] = a[i].size();
		priority[i] = i;
		order.push_back(i);
	}
	for (int cnt = 1; cnt < k; cnt++) {
		for (int i : order) {
			for (int j = 0; j < n; j++) {
				if (dp[j][cnt + 1] > dp[i][cnt] + nd[i][j]) {
					dp[j][cnt + 1] = dp[i][cnt] + nd[i][j];
					pr[j][cnt + 1] = { i, cnt };
					npriority[j] = priority[i];
				}
			}
		}
		vector <par> norder;
		for (int i = 0; i < n; i++) norder.push_back({ npriority[i], i });
		sort(norder.begin(), norder.end());
		for (int i = 0; i < n; i++) {
			order[i] = norder[i].second;
			priority[i] = npriority[i];
			was[i] = 0;
		}
	}
	int ans = INF;
	int id = -1;
	for (int i = 0; i < n; i++) if (ans > dp[i][k]) {
		ans = dp[i][k];
	}
	vector <string> poss;
	for (int i = 0; i < n; i++) if (ans == dp[i][k]) poss.push_back(makestr(i, k));
	sort(poss.begin(), poss.end());
	cout << poss[0] << '\n';
	return 0;
}
