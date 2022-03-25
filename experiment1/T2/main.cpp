#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> cols{}, diag1{}, diag2{};

int dfs(const int n, int row)
{
	if (row == n)
	{
		return 1;
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (cols.find(i) != cols.end())
		{
			continue;
		}

		const int d1 = row - i, d2 = row + i;
		if (diag1.find(d1) != diag1.end() || diag2.find(d2) != diag2.end())
		{
			continue;
		}

		cols.insert(i);
		diag1.insert(d1);
		diag2.insert(d2);
		ret += dfs(n, row + 1);
		cols.erase(i);
		diag1.erase(d1);
		diag2.erase(d2);
	}

	return ret;
}

int main()
{
	int n = 0;
	cin >> n;
	cout << dfs(n, 0);
	return 0;
}
