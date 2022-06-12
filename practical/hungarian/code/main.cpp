#include<iostream>

using namespace std;

constexpr int NMAX = 1010;
constexpr int EMAX = 1000010;
int n = 0, m = 0, e = 0, ans = 0;

int edge[EMAX], head[NMAX], nxt[EMAX], tot = 0;
int dfn[NMAX << 1], match[NMAX], x = 0, y = 0, ti = 0;

void add(int x, int y)
{
	edge[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}

int hungrain(int x, int ti)
{
	for (int i = head[x]; i; i = nxt[i])
	{
		int j = edge[i];
		if (dfn[j] != ti)
		{
			dfn[j] = ti;
			if (!match[j] || hungrain(match[j], ti))
			{
				match[j] = i;
				return 1;
			}
		}

	}
	return 0;
}

int main()
{
	cin >> n >> m >> e;
	for (int i = 1; i <= e; i++)
	{
		cin >> x >> y;
		if (x > n || y > m)
		{
			continue;
		}
		add(x, y);
	}

	for (int i = 1; i <= n; i++)
	{
		if (hungrain(i, ++ti))
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}