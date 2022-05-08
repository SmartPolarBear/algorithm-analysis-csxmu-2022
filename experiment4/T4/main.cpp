#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

struct node
{
	int from, to, cap, flow;
};

vector<int> G[20000];
vector<node> edge;

void add(int from, int to, int cap)
{
	edge.push_back((node){ from, to, cap, 0 });
	edge.push_back((node){ to, from, 0, 0 });
	int m = edge.size();
	G[from].push_back(m - 2);
	G[to].push_back(m - 1);
}

int s, t;
bool vis[20000];
int d[20000], cur[20000];

bool bfs()
{
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(s);
	d[s] = 0;
	vis[s] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < G[x].size(); i++)
		{
			node& e = edge[G[x][i]];
			if (!vis[e.to] && e.cap > e.flow)
			{
				vis[e.to] = 1;
				d[e.to] = d[x] + 1;
				q.push(e.to);
			}
		}
	}
	return vis[t];
}

int dfs(int x, int a)
{
	if (x == t || a == 0) return a;
	int flow = 0, f;
	for (int& i = cur[x]; i < G[x].size(); i++)
	{
		node& e = edge[G[x][i]];
		if (d[x] + 1 == d[e.to] && (f = (dfs(e.to, min(a, e.cap - e.flow)))) > 0)
		{
			e.flow += f;
			edge[G[x][i] ^ 1].flow -= f;
			flow += f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

int dinic()
{
	int flow = 0;
	memset(d, 0, sizeof d);
	while (bfs())
	{
		memset(cur, 0, sizeof cur);
		flow += dfs(s, 0x3f3f3f3f);
	}
	return flow;
}

int main()
{

	int n, m;
	cin >> n;
	s = n + 1;
	t = n + 2;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int a = 0;
		cin >> a;
		sum += a;
		add(s, i, a);
	}
	for (int i = 1; i <= n; i++)
	{
		int b = 0;
		cin >> b;
		sum += b;
		add(i, t, b);
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int num;
		int c1, c2;
		cin >> num >> c1 >> c2;
		int v1 = n + 10 + i, v2 = n + 100 + i;
		add(s, v1, c1);
		add(v2, t, c2);
		sum += c1 + c2;
		for (int j = 1; j <= num; j++)
		{
			int u;
			cin >> u;
			add(v1, u, 0x3f3f3f3f);
			add(u, v2, 0x3f3f3f3f);
		}
	}

	cout << sum - dinic();
	return 0;
}