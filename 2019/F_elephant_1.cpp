#include <stdio.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include<vector>
#include <istream>
#include<iomanip>
#include<stack>
using namespace std;

#define ll long long

ll to_dm(string &s) {
	ll k = 1;
	ll ans = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		ans = ans + (s[i] - '0') * k;
		k = k * 2;
	}
	return ans;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG
	int n, k;
	cin >> n >> k;
	string s ="";
	for (int i = 0; i < k; i++) {
		s += '1';
	}
	for (int i = k; i < 30; i++) {
		s += '0';
	}
	reverse(s.begin(), s.end());
	vector<int>ans;
	do {
		ll k = to_dm(s);
		if (k <= n)
			ans.push_back(k);
		else
			break;
	} while (next_permutation(s.begin(), s.end()));

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size() && i < 1000; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}