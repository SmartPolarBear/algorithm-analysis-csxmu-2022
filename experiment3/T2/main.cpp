#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

struct edge
{
	int u, v, w, next;
};

constexpr int MMAX = 1010, QMAX = 100010;

int heads[MMAX]{}, ecnt = 0;
edge edges[QMAX << 1]{};

void reset()
{
	memset(heads, -1, sizeof(heads));
	memset(edges, 0, sizeof(edges));
	ecnt = 0;
}

void add(int u, int v, int w)
{
	edges[ecnt].v = v;
	edges[ecnt].u = u;
	edges[ecnt].w = w;
	edges[ecnt].next = heads[u];
	heads[u] = ecnt++;
}

int dis[MMAX]{};
bool vis[MMAX]{};

void dijkstra(int s)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));

	dis[s] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.emplace(0, s);

	while (!q.empty())
	{
		auto t = q.top();
		q.pop();

		if (vis[t.second])continue;

		vis[t.second] = true;

		for (int i = heads[t.second]; ~i; i = edges[i].next)
		{
			if (dis[edges[i].v] > dis[edges[i].u] + edges[i].w)
			{
				dis[edges[i].v] = dis[edges[i].u] + edges[i].w;
				q.emplace(dis[edges[i].v], edges[i].v);
			}
		}
	}
}

int main()
{
	int T = 0;
	cin >> T;
	while (T-- > 0)
	{
		reset();
		vector<int> dests{};
		int n = 0, m = 0, p = 0, q = 0;
		cin >> n >> m >> p >> q;
		for (int i = 0; i < n; i++)
		{
			int c = 0;
			cin >> c;
			dests.push_back(c);
		}

		for (int i = 0; i < p; i++)
		{
			int u = 0, v = 0, w = 0;
			cin >> u >> v >> w;
			add(u, v, w);
			add(v, u, w);
		}

		dijkstra(q);

		int minimum = 0x7fffffff;
		for (const auto& d : dests)
		{
			if (dis[d] < minimum)
			{
				minimum = dis[d];
			}
		}

		cout << minimum << endl;
	}
	return 0;
}
