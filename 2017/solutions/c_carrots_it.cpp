#include<iostream>
#include<fstream>

using namespace std;

int n, m;
bool a[102][102];

void fail() {
	cout << "NO";
	exit(0);
}

int main() {

	freopen("carrots.in", "r", stdin);
	freopen("carrots.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			int t;
			cin >> t;
			a[i][j] = t == 1;
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (!a[i][j])
				continue;
			if (a[i - 1][j - 1] || a[i - 1][j + 1] || a[i + 1][j - 1] || a[i + 1][j + 1])
				fail();
			if ((a[i - 1][j] || a[i + 1][j]) && (a[i][j - 1] || a[i][j + 1]))
				fail();
		}

	cout << "YES";

}
