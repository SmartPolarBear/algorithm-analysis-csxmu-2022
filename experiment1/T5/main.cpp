#include <iostream>
#include <vector>

using namespace std;

constexpr auto N = 55;

int g[N][N]{ 0 };
vector<int> path{}, ans{};
bool vis[N]{ false };
int min_w = 0x7fffffff;

void dfs(const int n, const int w, int r)
{
	if (w > min_w)
	{
		return;
	}

	if (path.size() == n && w < min_w)
	{
		min_w = w;
		ans.assign(path.begin(), path.end());
		return;
	}

	int next = -1, nextval = 0x7fffffff;
	for (int i = 0; i < n; i++)
	{
		if (i != r && !vis[i] && g[r][i] < nextval)
		{
			nextval = g[r][i];
			next = i;
		}
	}

	if (next >= 0)
	{
		vis[next] = true;
		path.push_back(next);
		dfs(n, w + g[r][next], next);
		path.pop_back();
		vis[next] = false;
	}
}

int main()
{
	int t = 0, n = 0;
	cin >> t >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}

	for (int i = 0; i < n - 1; i++)
	{
		vis[i] = true;
		path.push_back(i);
		dfs(n, 0, i);
		path.pop_back();
		vis[i] = false;
	}


	cout << t << "\n";
	for (const auto& p: ans)
	{
		cout << p + 1 << " ";
	}

	return 0;
}
