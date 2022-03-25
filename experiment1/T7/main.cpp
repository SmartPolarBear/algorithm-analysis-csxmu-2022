#include <iostream>
#include <string>

using namespace std;

constexpr int N = 1010;

int f[N][N]{ 0 };

int main()
{
	int n = 0;
	cin >> n;

	string a{}, b{};
	cin >> a >> b;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				f[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	cout << f[n][n];
	return 0;
}
