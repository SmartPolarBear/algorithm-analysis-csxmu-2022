#include <iostream>

using namespace std;
constexpr int N = 10;

char g[N][N]{};
bool vis[N][N]{};
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
		if (g[x][i] == 'X')
			break;
		if (vis[x][i])
			available = false;
	}

	for (int i = x - 1; i >= 1; i--)
	{
		if (g[i][y] == 'X')
			break;
		if (vis[i][y])
			available = false;
	}

	int next_x = x, next_y = y + 1;
	if (next_y > n)
	{
		next_x++;
		next_y = 1;
	}

	if (available)
	{
		vis[x][y] = true;
		dfs(n, next_x, next_y, cnt + 1);
		vis[x][y] = false;
	}

	dfs(n,next_x, next_y, cnt);
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