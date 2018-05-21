#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
	ifstream cin("first.in");
	ofstream cout("first.out");

	set<char> l;
        
        int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (l.find(s[0]) == l.end()) {
			l.insert(s[0]);
			cout << s << '\n';
		}
	}

	return 0;
}