#include <iostream>
#include <algorithm>

using namespace std;

constexpr int NMAX = 10010;

int a1[NMAX]{}, a2[NMAX]{};
int t1[NMAX]{}, t2[NMAX]{};
int f1[NMAX]{}, f2[NMAX]{};

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a1[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> a2[i];
	}

	for (int i = 1; i <= n - 1; i++)
	{
		cin >> t1[i];
	}

	for (int i = 1; i <= n - 1; i++)
	{
		cin >> t2[i];
	}

	int e1 = 0, e2 = 0;
	cin >> e1 >> e2;

	int x1 = 0, x2 = 0;
	cin >> x1 >> x2;

	f1[1] = a1[1] + e1;
	f2[1] = a2[1] + e2;

	for (int i = 2; i <= n; i++)
	{
		f1[i] = min(f1[i - 1] + a1[i], f2[i - 1] + t2[i - 1] + a1[i]);
		f2[i] = min(f2[i - 1] + a2[i], f1[i - 1] + t1[i - 1] + a2[i]);
	}

	cout << min(f1[n] + x1, f2[n] + x2);

	return 0;
}
