#include <iostream>

using namespace std;

constexpr int NMAX = 210;
constexpr int MMAX = 210;

int mat[NMAX][MMAX]{ 0 }, len[NMAX][MMAX]{ 0 };

constexpr int dx[] = { -1, 1, 0, 0 };
constexpr int dy[] = { 0, 0, -1, 1 };
int n = 0, m = 0;

int dfs(int x, int y)
{
	if (len[x][y] != 0)
	{
		return len[x][y];
	}

	len[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] > mat[x][y])
		{
			len[x][y] = max(len[x][y], dfs(nx, ny) + 1);
		}
	}
	return len[x][y];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ret = max(ret, dfs(i, j));
		}
	}

	cout << ret;

	return 0;
}
