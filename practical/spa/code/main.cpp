#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAXN = 210, MAXM = 5010;

struct Edge
{
	int to, next, cap, rc;
} edge[MAXM << 1];
int cnt = 1;
int head[MAXN];
void add_edge(int u, int v, int w)
{
	cnt++;
	edge[cnt].to = v;
	edge[cnt].cap = w;
	edge[cnt].rc = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

int n = 0, m = 0, s = 0, t = 0;
bool vis[MAXN];
int dis[MAXN], pre[MAXN];
int bfs(int s, int t)
{
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(s);
	vis[s] = true;
	dis[s] = 0x7fffffff;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (edge[i].rc == 0 || vis[v]) continue;
			dis[v] = min(dis[u], edge[i].rc);
			pre[v] = i;
			q.push(v);
			vis[v] = true;
			if (v == t) return 1;
		}
	}
	return 0;
}

unsigned long long EdmondsKarp()
{
	unsigned long long max_flow = 0;
	while (bfs(s, t))
	{
		int cur = t;
		while (cur != s)
		{
			int v = pre[cur];
			edge[v].rc -= dis[t];
			edge[v ^ 1].rc += dis[t];
			cur = edge[v ^ 1].to;
		}
		max_flow += dis[t];
	}
	return max_flow;
}

int main()
{
	cin >> n >> m >> s >> t;

	for (int i = 0; i < m; ++i)
	{
		int from, to, cap;
		cin >> from >> to >> cap;
		add_edge(from, to, cap);
		add_edge(to, from, 0);
	}

	unsigned long long max_flow = EdmondsKarp();
	cout << max_flow << endl;

	return 0;
}