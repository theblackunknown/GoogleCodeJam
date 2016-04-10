
#include <set>
#include <string>
#include <cstddef>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	int T;
	cin >> T;
	for (decltype(T) idx_test_case(1); idx_test_case <= T; ++idx_test_case)
	{
		/// Input
		long long N;
		cin >> N;

		std::set<long long> seens;

		/// Algorithm
		long long i( 1LL );
		long long previous_number( 0LL );
		for( ; ;)
		{
			long long number( i * N );

			if( number == previous_number )
			{
				break;
			}

			previous_number = number;

			do
			{
				long long probe( number % 10LL );
				seens.insert( probe );

				number = number / 10LL;
			}
			while( number > 0 );

			if (seens.size() == 10) break;
			if (i > 10e6) break;
			++i;
		}

		/// Output
		if( seens.size( ) == 10 )
 			cout << "Case #" << idx_test_case << ": "<< ( i * N ) << endl;
 		else
 			cout << "Case #" << idx_test_case << ": "<< "INSOMNIA" << endl;
	}
	return 0;
}