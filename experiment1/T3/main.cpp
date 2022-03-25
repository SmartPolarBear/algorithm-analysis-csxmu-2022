#include <iostream>

using namespace std;
constexpr int N = 10;
char g[N][N];
bool vis[N][N];
int ans = 0;

void dfs(const int n, int x, int y, int cnt)
{
	if (x > n)
	{
		ans = max(ans, cnt);
		return;
	}

	bool available = true;
	if (g[x][y] == 'X')
	{
		available = false;
	}

	for (int i = y - 1; i >= 1; i--)
	{
		if (g[x][i] == 'X')break;
		if (vis[x][i])available = false;
	}

	for (int i = x - 1; i >= 1; i--)
	{
		if (g[i][y] == 'X')break;
		if (vis[i][y])available = false;
	}


	if (y + 1 > n)
	{
		if (available)
		{
			vis[x][y] = true;
			dfs(n, x + 1, 1, cnt + 1);
			vis[x][y] = false;
		}

		dfs(n, x + 1, 1, cnt);

	}
	else
	{
		if (available)
		{
			vis[x][y] = true;
			dfs(n, x, y + 1, cnt + 1);
			vis[x][y] = false;
		}

		dfs(n, x, y + 1, cnt);

	}
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> g[i][j];
		}
	}
	dfs(n, 1, 1, 0);
	cout << ans;
	return 0;
}