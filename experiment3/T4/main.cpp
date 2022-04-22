#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int NMAX = 210, MMAX = 210;

struct edge
{
	int v, w, next;
};

int heads[NMAX]{}, ecnt = 0; //!
edge edges[MMAX << 1]{};

void add(int u, int v, int w)
{
	edges[ecnt].v = v;
	edges[ecnt].w = w;
	edges[ecnt].next = heads[u];
	heads[u] = ecnt++;
}

constexpr int INF = 0x3f3f3f3f;

int level[NMAX]{}, cur[NMAX]{};

bool bfs(const int N)
{
	memset(level, -1, sizeof(level));
	level[1] = 0;
	memcpy(cur, heads, sizeof(heads));

	queue<int> q{};
	q.push(1);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();

		for (int i = heads[t]; ~i; i = edges[i].next)
		{
			int v = edges[i].v, vol = edges[i].w;
			if (vol > 0 && level[v] == -1)
			{
				level[v] = level[t] + 1;
				q.push(v);
			}
		}
	}

	return level[N] != -1;
}

int dfs(const int p, const int N, int flow = INF)
{
	if (p == N)
	{
		return flow;
	}

	int remaining = flow;
	for (int i = heads[p]; ((~i) && remaining); i = edges[i].next)
	{
		cur[p] = i;
		int v = edges[i].v, vol = edges[i].w;
		if (vol > 0 && level[v] == level[p] + 1)
		{
			int c = dfs(v, N, min(vol, remaining));
			remaining -= c;

			edges[i].w -= c;
			edges[i ^ 1].w += c;
		}
	}

	return flow - remaining;
}

int dinic(const int N)
{
	int ret = 0;
	while (bfs(N))
	{
		ret += dfs(1, N);
	}

	return ret;
}

int main()
{
	memset(heads, -1, sizeof(heads));
	int m = 0, n = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		int u = 0, v = 0, w = 0;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, 0);
	}

	int value = dinic(n);
	cout << value;
	return 0;
}