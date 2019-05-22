#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s = "", ans = "", s2;
	cin >> s;

	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			ans += s[i];
		else
		{
			int tmp = int(s[i]);
			s2 = "'";
			while (tmp > 0)
				s2 += char((tmp % 10) + '0'), tmp /= 10;
			s2 += "'", reverse(s2.begin(), s2.end());
			ans += s2;
		}
	cout << ans;
	cin >> s;
	return 0;
}
