#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string intToStr(int i) {
	string s;
	if(i / 10) s += char(i / 10 + '0');
	s += char(i % 10 + '0');
	return s;
}

void rec(int n, int mn, string tek) {
	if(n == 0) {
		printf("%s\n", tek.c_str());
		return;
	}
	if(tek != "") tek += '+';
	for(int i = mn; i >= 1; --i)
		rec(n - i, min(n - i, min(mn, i)), tek + intToStr(i));
}

int main() {

	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);

	int n;
	scanf("%d", &n);

	rec(n, n, "");

	return 0;
}
