#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define form(i, a, b) for (int i = a - 1; i >= b; i--)
#define all(a) a.begin(), a.end()

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

using namespace std;

static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

struct task {
	string inn;
	string sted;

	bool operator < (const task &t) const {
		return sted < t.sted;
	}
};

int main() {
	ios::sync_with_stdio(false);

	freopen("tasks.in", "r", stdin);
	freopen("tasks.out", "w", stdout);

	int n;
	cin>>n;

	vector<task> a(n);
	forn(i, 0, n) {
		cin >> a[i].inn;
		a[i].sted = a[i].inn;
		sort(all(a[i].sted));
	}

	sort(all(a));

	forn(i, 0, n - 1)
		cout << a[i].inn << '\n';
	cout << a[n - 1].inn;

	return 0;
}
