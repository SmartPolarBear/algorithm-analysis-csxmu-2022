#include <iostream>
#include <algorithm>
using namespace std;

constexpr int NMAX = 1010;
constexpr int WMAX = 110;

int f[NMAX][WMAX]{}, vi[NMAX]{}, wi[NMAX]{};

int main()
{
	int n = 0, v = 0;
	cin >> n >> v;

	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> wi[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (j < vi[i])
			{
				f[i][j] = f[i - 1][j];
			}
			else
			{
				f[i][j] = max(f[i - 1][j - vi[i]] + wi[i], f[i - 1][j]);
			}

		}
	}

	cout << f[n][v];

	return 0;
}
