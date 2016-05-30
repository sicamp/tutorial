#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

#define mp make_pair
#define pb push_back
#define problem "sumdiff"
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 222;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

ll n, x, ans[z];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			ans[i] += x;
			ans[j] -= x;
		}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	return 0;
}
