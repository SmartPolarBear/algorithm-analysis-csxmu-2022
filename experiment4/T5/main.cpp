#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

constexpr int NMAX = 1010;

int base[NMAX], pre[NMAX], match[NMAX], inque[NMAX], inpath[NMAX], inblossom[NMAX];
int n, x[NMAX], y[NMAX], L, g[NMAX][NMAX];

queue<int> q;

int findancestor(int u, int v)
{
	memset(inpath, 0, sizeof(inpath));
	while (1)
	{
		u = base[u];
		inpath[u] = 1;
		if (match[u] == -1) break;
		u = pre[match[u]];
	}
	while (1)
	{
		v = base[v];
		if (inpath[v]) return v;
		v = pre[match[v]];
	}
}
void reset_trace(int u, int anc)
{
	while (u != anc)
	{
		int v = match[u];
		inblossom[base[u]] = 1;
		inblossom[base[v]] = 1;
		v = pre[v];
		if (base[v] != anc) pre[v] = match[u];
		u = v;
	}
}
void contract(int u, int v)
{
	int anc = findancestor(u, v);
	memset(inblossom, 0, sizeof(inblossom));
	reset_trace(u, anc);
	reset_trace(v, anc);
	if (base[u] != anc) pre[u] = v;
	if (base[v] != anc) pre[v] = u;
	for (int i = 1; i <= n; ++i)
		if (inblossom[base[i]])
		{
			base[i] = anc;
			if (!inque[i])
			{
				inque[i] = 1;
				q.push(i);
			}
		}
}
bool bfs(int st)
{
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 1; i <= n; ++i) pre[i] = -1, inque[i] = 0, base[i] = i;
	q.push(st);
	inque[st] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; ++v)
			if (g[u][v] && base[u] != base[v] && match[u] != v)
			{
				if (v == st || (match[v] != -1 && pre[match[v]] != -1)) // circle
					contract(u, v);
				else if (pre[v] == -1)
				{
					pre[v] = u;
					if (match[v] != -1)
						q.push(match[v]), inque[match[v]] = 1;
					else
					{
						u = v;
						while (u != -1)
						{
							v = pre[u];
							int w = match[v];
							match[u] = v;
							match[v] = u;
							u = w;
						}
						return true;
					}
				}
			}
	}
	return false;
}
int sizes[NMAX], sz, dfn[NMAX], counts[NMAX];
void dfs(int u)
{
	dfn[u] = sz;
	sizes[sz]++;
	for (int i = 1; i <= n; ++i)
		if (g[u][i] && !dfn[i])
			dfs(i);
}
bool solve()
{
	for (int i = 1; i <= n; ++i)
		if (match[i] == -1)
			bfs(i);
	for (int i = 1; i <= n; ++i)
		if (match[i] != -1)
			counts[dfn[i]]++;
	for (int i = 1; i <= sz; ++i)
		if (counts[i] != sizes[i])
			return false;
	return true;
}

int main()
{
	int T;
	cin >> T;

	while (T-- > 0)
	{
		memset(g, 0, sizeof(g));
		memset(match, -1, sizeof(match));

		cin >> n;

		for (int i = 1; i <= n; ++i)
		{
			cin >> x[i] >> y[i];
		}
		cin >> L;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= L)
				{
					g[i][j] = g[j][i] = 1;
				}
			}
		}

		memset(sizes, 0, sizeof(sizes));
		memset(dfn, 0, sizeof(dfn));
		memset(counts, 0, sizeof(counts));
		sz = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!dfn[i])
			{
				sz++;
				dfs(i);
			}
		}
		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}