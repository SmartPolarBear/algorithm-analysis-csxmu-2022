#include <iostream>
#include <algorithm>

using namespace std;

constexpr int NMAX = 1005;
int a[NMAX], b[NMAX];

int main()
{
	int n = 0;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + n);

		int res = 0;

		for (int l1 = 0, r1 = n - 1, l2 = 0, r2 = n - 1; l1 <= r1 && l2 <= r2;)
		{
			if (a[r1] > b[r2])
			{
				res += 10;
				r1--, r2--;
			}
			else if (a[r1] < b[r2])
			{
				res -= 10;
				l1++, r2--;
			}
			else
			{
				if (a[l1] > b[l2])
				{
					l2++, l1++;
					res += 10;
				}
				else if (a[l1] < b[l2])
				{
					l1++, r2--;
					res -= 10;
				}
				else
				{
					if (a[l1] < b[r2]) res -= 10;
					l1++, r2--;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}