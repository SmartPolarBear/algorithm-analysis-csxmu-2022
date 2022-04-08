#include <iostream>
#include <cstring>

using namespace std;

constexpr int NMAX = 10100;
constexpr int WMAX = 1010;

int p[WMAX]{};
int f[NMAX][NMAX]{};

int main()
{
	int n = 0;
	cin >> n;
	cin >> p[0] >> p[1];
	for (int i = 1; i < n; i++)
	{
		int discard = 0;
		cin >> discard >> p[i + 1];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			f[i][j] = 0x3f3f3f3f;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		f[i][i] = 0;
	}

	for (int i = n; i > 0; i--)
	{
		for (int j = i; j <= n; j++)
		{
			if (i == j)
			{
				f[i][j] = 0;
			}
			else
			{
				for (int k = i; k <= j; k++)
				{
					f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + p[i - 1] * p[j] * p[k]);
				}
			}
		}
	}

	cout << f[1][n];

	return 0;
}
