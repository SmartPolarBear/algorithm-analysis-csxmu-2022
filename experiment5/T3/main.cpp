#include <iostream>
#include <bitset>
#include <cstdint>
#include <array>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

using state = array<bitset<5>, 5>;

uint32_t hashing(const state& st)
{
	uint32_t ret = 0;
	for (int i = 4; i >= 0; i--)
	{
		ret = ((ret << 5) | st[i].to_ulong());
	}
	return ret;
}

constexpr int dr[] = { 0, 0, -1, 1 };
constexpr int dc[] = { -1, 1, 0, 0 };

state turn(state& st, int r, int c)
{
	state copy{ st };
	copy[r].flip(c);

	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i], nc = c + dc[i];
		if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5)
		{
			copy[nr].flip(nc);
		}
	}

	return copy;
}

state full()
{
	state st{};
	for (auto& i : st)
	{
		i.set();
	}
	return st;
}

template<>
struct std::hash<state>
{
	std::size_t operator()(const state & s) const noexcept
	{
		return hashing(s);
	}
};

unordered_map<state, int> steps{};

void bfs()
{
	state s = full();
	queue<state> q;
	q.push(s);
	steps[s] = 1;
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();

		if (steps[t] > 6)
		{
			break;
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				auto f = turn(t, i, j);
				if (steps[f] > 0)
				{
					continue;
				}

				steps[f] = steps[t] + 1;
				q.push(f);
			}
		}
	}
}

int main()
{
	bfs();
	int T = 0;
	cin >> T;
	while (T-- > 0)
	{
		state s{};
		for (int i = 0; i < 5; i++)
		{
			string line{};
			cin >> line;
			for (int j = 0; j < 5; j++)
			{
				s[i].set(j, line[j] == '1');
			}
		}
		cout << steps[s] - 1 << "\n";
	}
	return 0;
}
