#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

constexpr int NMAX = 20;

int n = 0, w = 0;
int weights[NMAX];
int cab[NMAX];
int ans = 0x7fffffff;

void dfs(int cnt, int k)
{
	if (cnt >= ans)
	{
		return;
	}

	if (k >= n)
	{
		ans = min(ans, cnt);
		return;
	}

	for (int i = 1; i <= cnt; i++)
	{
		if (cab[i] + weights[k] <= w)
		{
			cab[i] += weights[k];
			dfs(cnt, k + 1);
			cab[i] -= weights[k];
		}
	}

	cab[cnt + 1] += weights[k];
	dfs(cnt + 1, k + 1);
	cab[cnt + 1] = 0;
}

int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	sort(weights, weights + n, [](int a, int b)
	{
	  return a > b;
	});

	dfs(0, 0);
	cout << ans;

	return 0;
}
