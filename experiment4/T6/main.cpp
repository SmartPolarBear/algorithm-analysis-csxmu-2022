#include <iostream>
#include <cstdint>

constexpr int MOD = 1000000007;

using namespace std;

uint64_t partition(int n, int m)
{
	if (n == 1 || m == 1)
	{
		return 1;
	}
	else if (n < m)
	{
		return partition(n, n) % MOD;
	}
	else if (n == m)
	{
		return 1 + partition(n, n - 1) % MOD;
	}
	else
	{
		return (partition(n, m - 1) % MOD + partition(n - m, m) % MOD) % MOD;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	cout << partition(n, n);
	return 0;
}
