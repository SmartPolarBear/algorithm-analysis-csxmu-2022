#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int NMAX = 70;

int len[NMAX], sum = 0;
bool vis[NMAX]{};

int n = 0;

bool dfs(int fin, int total, int start, const int target)
{
	if (fin * target == sum)
	{
		return true;
	}

	if (total == target)
	{
		return dfs(fin + 1, 0, 0, target);
	}

	for (int i = start; i < n; i++)
	{
		if (vis[i])continue;
		if (total + len[i] > target)continue;
		if (i > start && !vis[i - 1] && len[i] == len[i - 1])continue;

		vis[i] = true;

		if (dfs(fin, total + len[i], i + 1, target))
			return true;

		vis[i] = false;

		if (total == 0 || total + len[i] == target)
			return false;
	}

	return false;
}

int main()
{
	while (cin >> n, n)
	{
		sum = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			cin >> len[i];
			sum += len[i];
		}
		sort(len, len + n, [](int a, int b)
		{
		  return a > b;
		});
		for (int i = len[0]; i <= sum; i++)
		{
			if (sum % i == 0)
			{
				if (dfs(0, 0, 0, i))
				{
					cout << i << endl;
					break;
				}
			}
		}
	}
	return 0;
}
