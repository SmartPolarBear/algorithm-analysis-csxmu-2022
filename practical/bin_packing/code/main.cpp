#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class plane
{
 public:
	struct board
	{
		int area()
		{
			return width * length;
		}

		board() = default;
		board(int w, int h)
			: width(w), length(h)
		{
		}

		int width;
		int length;
	};

	plane(int length, int width)
	{
		boards_.emplace_back(width, length);
	}

	void from_keyboard()
	{
		cin >> n_;
		for (int i = 0; i < n_; i++)
		{
			board b{};
			cin >> b.length >> b.width;
			samples_.push_back(b);
		}
		sort(samples_.begin(), samples_.end(), board_comparer);
	}

	void solve()
	{
		cut(0, boards_);
	}

	[[nodiscard]] int best() const
	{
		return best_;
	}

 private:
	int bound(int idx)
	{
		int sum = 0;
		for (int i = idx + 1; i < n_; i++)
			sum += samples_[i].area();
		return sum + current_area_;
	}

	void cut(int idx, vector<board> boards)
	{
		bool flag = false;
		vector<board> copy(boards);
		if (idx > n_ - 1)
		{
			if (current_area_ > best_)
				best_ = current_area_;
		}
		else
		{
			if (samples_[idx].width < boards[0].width && samples_[idx].length == boards[0].length)
			{
				// case1 :
				current_area_ += samples_[idx].area();
				boards.push_back(board{ boards[0].width - samples_[idx].width, samples_[idx].length });
				vector<board>::iterator k = boards.begin();
				boards.erase(k);
				sort(boards.begin(), boards.end(), board_comparer);
				cut(idx + 1, boards);
				current_area_ -= samples_[idx].area();
				flag = true;
			}
			else if (samples_[idx].width == boards[0].width && samples_[idx].length < boards[0].length)
			{
				//case 2
				current_area_ += samples_[idx].area();
				boards.push_back(board{ boards[0].width, boards[0].length - samples_[idx].length });
				vector<board>::iterator k = boards.begin();
				boards.erase(k);
				sort(boards.begin(), boards.end(), board_comparer);
				cut(idx + 1, boards);
				current_area_ -= samples_[idx].area();
				flag = true;
			}
			else if (samples_[idx].width == boards[0].width && samples_[idx].length == boards[0].length)
			{
				// case 3
				current_area_ += samples_[idx].area();
				vector<board>::iterator k = boards.begin();
				boards.erase(k);
				sort(boards.begin(), boards.end(), board_comparer);
				cut(idx + 1, boards);
				current_area_ -= samples_[idx].area();
				flag = true;
			}
			else if (samples_[idx].width < boards[0].width && samples_[idx].length < boards[0].length)
			{
				//case 4
				current_area_ += samples_[idx].area();
				boards.push_back(board{ boards[0].width, boards[0].length - samples_[idx].length });
				boards.push_back(board{ boards[0].width - samples_[idx].width, boards[0].length });
				vector<board>::iterator k = boards.begin();
				boards.erase(k);
				sort(boards.begin(), boards.end(), board_comparer);
				cut(idx + 1, boards);
				current_area_ -= samples_[idx].area();
				flag = true;
			}
			if (bound(idx) > best_)
			{
				if (!flag)
				{
					cut(idx + 1, boards);
				}
				else
				{
					cut(idx + 1, copy);
				}
			}
		}

	}

	static bool board_comparer(board a, board b)
	{
		return a.area() > b.area();
	}

	int n_;// total # of boards
	int best_;
	int current_area_ = 0;

	vector<board> boards_;
	vector<board> samples_;
};

int main()
{
	plane bd{ 20, 10 };
	bd.from_keyboard();
	bd.solve();
	cout << bd.best();
	return 0;
}

