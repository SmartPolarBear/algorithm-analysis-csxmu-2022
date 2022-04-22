#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int N = 110;

int fa[N]{};

void init_fu()
{
	for (int i = 0; i < N; i++)
	{
		fa[i] = i;
	}
}

int find_fu(int x)
{
	return fa[x] == x ? x : (fa[x] = find_fu(fa[x]));
}

void merge_fu(int x, int y)
{
	fa[find_fu(x)] = fa[find_fu(y)];
}

struct edge
{
	int u, v, w;
};

vector<edge> edges;

int kruskal()
{
	sort(edges.begin(), edges.end(), [](const edge& e1, const edge& e2)
	{
	  return e1.w < e2.w;
	});

	int ret = 0;
	for (const auto& e : edges)
	{
		if (find_fu(e.u) != find_fu(e.v))
		{
			merge_fu(e.u, e.v);
			ret += e.w;
		}
	}
	return ret;
}

int main()
{
	init_fu();

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int d = 0;
			cin >> d;
			if (d)
			{
				edges.push_back(edge{ i, j, d });
			}
		}
	}

	cout << kruskal();

	return 0;
}
