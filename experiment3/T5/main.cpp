#include <iostream>
#include <cstring>

using namespace std;

constexpr int NMAX = 510;
bool g[NMAX][NMAX]{}, vis[NMAX];
int p[NMAX]{};

void reset()
{
	memset(g, 0, sizeof(g));
	memset(vis, 0, sizeof(vis));
	memset(p, 0, sizeof(p));
}

bool match(int i, const int N)
{
	for (int j = 1; j <= N; j++)
	{
		if (g[i][j] && !vis[j])
		{
			vis[j] = true;
			if (!p[j] || match(p[j], N))
			{
				p[j] = i;
				return true;
			}
		}
	}
	return false;
}

int hungarian(const int M, const int N)
{
	int ret = 0;
	for (int i = 1; i <= M; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (match(i, N))
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	int k = 0, m = 0, n = 0;
	while (cin >> k >> m >> n)
	{
		reset();
		for (int i = 0; i < k; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			g[a][b] = true;
		}

		cout << hungarian(m, n) << endl;

	}
	return 0;
}