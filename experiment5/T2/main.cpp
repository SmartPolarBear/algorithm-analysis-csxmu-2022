#include <iostream>
#include <algorithm>

using namespace std;

constexpr int NMAX = 10;

int nums[NMAX]{}, permu[NMAX]{};
bool vis[NMAX]{};

void permutation(int k, const int n)
{
	if (k >= n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << permu[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			permu[k] = nums[i];
			permutation(k + 1, n);
			vis[i] = false;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		nums[i - 1] = i;
	}
	permutation(0, n);
	return 0;
}
