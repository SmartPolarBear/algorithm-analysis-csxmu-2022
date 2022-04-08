#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr int NMAX = 1010;

int f[NMAX][NMAX]{};

int main()
{
	int n = 0;
	cin >> n;
	string s1{}, s2{};
	cin >> s1 >> s2;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}

	cout << f[n][n];

	return 0;
}
