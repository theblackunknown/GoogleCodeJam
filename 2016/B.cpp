
#include <vector>
#include <iostream>

using namespace std;

namespace
{
	void reverse( std::vector<char>& l, int start, int end )
	{
		std::vector<char> copy( l );
		for( int i( start ); i < end; ++i )
		{
			copy[i] = l[end - 1 - i] == '-' ? '+' : '-';
		}
		l = copy;
	}	
}

int main(int argc, char* argv[])
{
	int N;
	char probe;
	cin >> N;
	cin.unsetf(std::ios_base::skipws);

	/// skip first \n
	cin >> probe;

	for (decltype(N) idx_test_case(1); idx_test_case <= N; ++idx_test_case)
	{
		/// Input / Algorithm
		std::vector<char> pancakes;

		do
		{
			cin.get( probe );
			if (probe != '\n' && !cin.eof())
			{
				pancakes.push_back(probe);
			}
		}
		while( probe != '\n' && !cin.eof( ) );

		std::size_t flip_count( 0u );
		
		for( auto i( 0u ); i < pancakes.size( ); /*++i*/ )
		{
			switch (pancakes[i])
			{
			case '+':
			{
				// ++i;
				++i;
			}
			break;
			case '-':
			{
				if (i > 0 && pancakes[i - 1] == '+')
				{
					reverse(pancakes, 0, i);
					++flip_count;
					i = 0;
				}
				else
				{
					// - streak
					auto j(i);
					while (j < pancakes.size() && pancakes[j] == '-')
					{
						++j;
					}

					reverse(pancakes, 0, j);
					++flip_count;
					i = 0;
				}
			}
			break;
			}
		}

		/// Output
		cout << "Case #" << idx_test_case << ": " << flip_count << endl;
	}
	return 0;
}