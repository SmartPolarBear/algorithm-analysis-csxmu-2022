#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
constexpr int N = 10;

int w[N][N]{};
int f[1 << N][N]{};

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}

	memset(f, 0x3f, sizeof(f));

	f[1][0] = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
			{
				for (int k = 0; k < n; k++)
				{
					if (k != j && ((i >> k) & 1))
					{
						f[i][j] = min(f[i - (1 << j)][k] + w[k][j], f[i][j]);
					}
				}
			}
		}
	}
	cout << f[(1 << n) - 1][n - 1];
	return 0;
}
