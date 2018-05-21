#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include <cstdio>
using namespace std;
vector<vector<bool> > used;
vector<vector<int> > g;
int n, m, ans = 0;
vector<int> dx = { 0, 0, 1, -1 };
vector<int> dy = { 1, -1, 0, 0 };
bool onf(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}
void dfs(int x, int y)
{
	used[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int to_x = x + dx[i];
		int to_y = y + dy[i];
		if (onf(to_x, to_y) && !used[to_x][to_y] && g[to_x][to_y] != g[x][y])
			dfs(to_x, to_y);
	}
}
int main()
{
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	cin >> n >> m;
	used.assign(n, vector<bool>(m, false));
	g.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			cin >> a;
			g[i][j] = (a == '.') ? 1 : 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!used[i][j])
			{
				ans++;
				dfs(i, j);
			}
		}
	}

	cout << ans;
	return 0;
}
