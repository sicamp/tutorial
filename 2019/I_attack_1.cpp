#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pii;
#define len(x) (int)(x).size()
#define F first
#define S second
typedef long double ld;

bool cmp(pii p1, pii p2) {
	return p1.F * p2.S > p2.F * p1.S;
}

const ld EPS = 1e-9;

void run() {
	int n;
	int D, P;
	cin >> n >> D >> P;
	vector<pii> a(n);
	int attack_sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].F >> a[i].S;
		attack_sum += a[i].F;
	}
	sort(all(a), cmp);
	ld castle_hp = P;
	for (int i = 0; i < n; ++i) {
		ld t = (ld)a[i].S / D;
		castle_hp -= t * attack_sum;
		if (castle_hp < EPS) {
			cout << "YES\n";
			return;
		}
		attack_sum -= a[i].F;
	}
	cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}