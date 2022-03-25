#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr auto N = 10;

int val[N]{}, vol[N]{};

int dfs(int n, int v)
{
	if (n == 0 || v == 0)
	{
		return 0;
	}

	if (vol[n - 1] > v)
	{
		return dfs(n - 1, v);
	}
	else
	{
		const auto w1 = dfs(n - 1, v - vol[n - 1]) + val[n - 1],
				w2 = dfs(n - 1, v);
		return max(w1, w2);
	}
}

int main()
{
	int n = 0, v = 0;
	cin >> n >> v;
	for (int i = 0; i < n; i++)
	{
		cin >> vol[i] >> val[i];
	}
	cout << dfs(n, v);
	return 0;
}
