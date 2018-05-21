#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	freopen("stairs.in", "r", stdin);
	freopen("stairs.out", "w", stdout);
	int n, m, sum = 0, cnt = 0;
	scanf("%d %d", &n, &m);
	vector<vector<int> > mass(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &mass[i][j]);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + 1 < n && mass[i][j] != mass[i + 1][j])
			{
				sum += abs(mass[i][j] - mass[i + 1][j]);
				cnt++;
			}
			if (j + 1 < m && mass[i][j] != mass[i][j + 1])
			{
				sum += abs(mass[i][j] - mass[i][j + 1]);
				cnt++;
			}
		}
	}
	cout << sum << " " << cnt;
    return 0;
}

