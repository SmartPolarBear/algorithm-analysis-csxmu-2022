#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	priority_queue<int, vector<int>, std::greater<int>> pq{};
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		cin >> k;
		pq.push(k);
	}

	int cost = 0;
	while (pq.size() > 1)
	{
		int t1 = pq.top();
		pq.pop();
		int t2 = pq.top();
		pq.pop();
		int new_dump = t1 + t2;
		pq.push(new_dump);
		cost += new_dump;
	}
	cout << cost;
	return 0;
}
