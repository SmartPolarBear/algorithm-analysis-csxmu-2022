#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

constexpr int NMAX = 110;

vector<int> edges[NMAX]{};
int indeg[NMAX]{};
int topo[NMAX]{};

struct node
{
	int id;
	int w;
};

void reset()
{
	for (auto& edge : edges)
	{
		edge.clear();
	}

	memset(indeg, 0, sizeof(indeg));
	memset(topo, 0, sizeof(topo));
}

void toposort(map<int, int>& weights, int n = 0)
{
	int cnt = 0;
	priority_queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++)
	{
		if (!indeg[i])
		{
			q.emplace(weights[i], i);
		}
	}

	while (!q.empty())
	{
		auto t = q.top();
		q.pop();

		topo[cnt++] = t.second;
		for (const auto& v : edges[t.second])
		{
			indeg[v]--;
			if (!indeg[v])
			{
				q.emplace(weights[v], v);
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
		int n = 0;
		cin >> n;
		map<int, int> weights{};
		for (int i = 0; i < n; i++)
		{
			int w = 0;
			cin >> w;
			weights[i + 1] = w;
		}

		for (int i = 1; i <= n; i++)
		{
			int k = 0;
			cin >> k;
			indeg[i] = k;
			for (int j = 0; j < k; j++)
			{
				int id = 0;
				cin >> id;
				edges[id].push_back(i);
			}
		}

		toposort(weights, n);
		for (int i = 0; i < n; i++)
		{
			cout << topo[i] << (i == n - 1 ? "" : " ");
		}
		cout << endl;
	}
	return 0;
}
