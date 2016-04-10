
#include <queue>
#include <cstddef>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int N, C, I;
	cin >> N;
	for (decltype(N) idx_test_case(1); idx_test_case <= N; ++idx_test_case)
	{
		/// Input
		cin >> C;
		cin >> I;

		std::vector<std::pair<int, int>> items(I);
		for (decltype(I) idx_item(0); idx_item < I; ++idx_item)
		{
			items[idx_item].first = idx_item + 1;
			cin >> items[idx_item].second;
		}

		/// Algorithm
		/// 1. Sort item by price
		/// 2. Iterate over all items
		/// 2.a for each item, find remaining money
		/// 2.b compute optimal paired candidate
		/// 2.c stop when pair candidate cost more than what you got
		
		/// 1.
		std::sort( items.begin( ), items.end( ), []( const auto& lhs, const auto& rhs ){
			return lhs.second < rhs.second;
		});

		std::pair<int, int> best( std::make_pair( 1, 2 ) );

		int best_final_remaining( C );

		for (int i(0); i < I; ++i)
		{
			const auto& item_a(items[i]);

			int remaining_money(C - item_a.second);
			if (remaining_money < 0)
			{
				break;
			}
			else
			{
				if (remaining_money >= item_a.second)
				{
					for (int j(i + 1); j < I; ++j)
					{
						const auto& item_b(items[j]);

						int final_remaining(remaining_money - item_b.second);
						if (final_remaining < 0)
						{
							break;
						}
						else if (final_remaining < best_final_remaining)
						{
							best.first = item_a.first;
							best.second = item_b.first;
							best_final_remaining = final_remaining;
						}
					}
				}
				else
				{
					for (int j( I - 1); j > -1; --j)
					{
						const auto& item_b(items[j]);

						int final_remaining(remaining_money - item_b.second);
						if (final_remaining < 0)
						{
							break;
						}
						else if (final_remaining < best_final_remaining)
						{
							best.first = item_a.first;
							best.second = item_b.first;
							best_final_remaining = final_remaining;
						}
					}
				}
			}
		}

		/// Output
		if (best.first > best.second)
		{
			cout << "Case #" << idx_test_case << ": " << best.second << " " << best.first << endl;
		}
		else
		{
			cout << "Case #" << idx_test_case << ": " << best.first << " " << best.second << endl;
		}
	}
	return 0;
}