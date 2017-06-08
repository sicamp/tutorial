#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long z_function(string s, int start) {
	int n = (int) s.length();
	vector<int> z(n);
	long long ans = 0;
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
		if (i > start)
			ans += z[i];
	}
	return ans;
}

int main() {

	freopen("plagiarism.in", "r", stdin);
	freopen("plagiarism.out", "w", stdout);

	string s1, s2;
	cin >> s1 >> s2;

	long long ans = 0;
	while (!s1.empty()) {
		string to_check = s1 + '#' + s2;
		ans += z_function(to_check, s1.size());
		reverse(s1.begin(), s1.end());
		s1.pop_back();
		reverse(s1.begin(), s1.end());
	}

	cout << ans;

	return 0;
}
