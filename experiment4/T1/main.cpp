#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

constexpr int NMAX = 110;

pair<int, int> seg[NMAX]{};

int main()
{
	while (true)
	{
		int n = 0;
		cin >> n;
		if (!n)break;

		for (int i = 0; i < n; i++)
		{
			cin >> seg[i].first >> seg[i].second;
		}

		sort(seg, seg + n, [](const auto& a, const auto& b)
		{
		  return a.second < b.second;
		});

		int r = seg[0].second, cnt = 1;
		for (int i=1;i<n;i++)
		{
			if (seg[i].first >= r)
			{
				cnt++;
				r = seg[i].second;
			}
		}

		cout << cnt;
	}
	return 0;
}
