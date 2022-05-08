#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int NMAX = 1010, MMAX = 20010, INF = 0x3f3f3f3f;

int head[NMAX], v[MMAX], nxt[MMAX], idx = 0, w[MMAX];
int n, m;
bool st[NMAX];
int dist[NMAX];

int bfs()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	queue<int> q;
	q.push(1);
	st[1] = true;

	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = head[t]; i != -1; i = nxt[i])
		{
			int j = v[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return dist[n];
}

bool dfs(int s, int t, int cost, int mincost)
{
	if (s == t && cost == mincost) return true;

	st[s] = true;
	for (int i = head[s]; ~i; i = nxt[i])
	{
		int ver = v[i];
		if (!st[ver])
		{
			if (dfs(ver, t, cost + w[i], mincost))
			{
				w[i] = w[i ^ 1] = INF;
				return true;
			}
		}
	}
	st[s] = false;

	return false;
}

int spfa()
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	dist[n] = 0;

	queue<int> q;
	q.push(n);
	st[n] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = head[t]; i != -1; i = nxt[i])
		{
			int j = v[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return dist[1];
}

void add(int a, int b, int c)
{
	v[idx] = b;
	nxt[idx] = head[a];
	w[idx] = c;
	head[a] = idx++;
}

int main()
{
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);

	}

	int t1 = bfs();
	memset(st, 0, sizeof(st));
	dfs(1, n, 0, dist[n]);

	int t2 = spfa();
	cout << t1 + t2 << endl;

	return 0;
}