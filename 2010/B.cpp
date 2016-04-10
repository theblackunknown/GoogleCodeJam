
#include <vector>
#include <iostream>

using namespace std;

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
		std::vector<std::string> words;

		std::vector<char> accumulator;
		std::string word;

		bool eof(false);
		do
		{
			cin.get( probe );
			eof = cin.eof();
			if( probe == ' ' || probe == '\n' || eof )
			{
				std::string word( accumulator.begin( ), accumulator.end( ) );
				words.push_back( word );
				accumulator.clear( );
			}
			else
			{
				accumulator.push_back( probe );
			}
		}
		while( probe != '\n' && !eof );


		/// Output
		cout << "Case #" << idx_test_case << ":";
		for( auto it( words.rbegin( ) ), end( words.rend( ) ); it !=end; ++it )
		{
			const auto& word( *it );
			cout << " ";
			for( auto&& character : word )
			{
				cout << character;
			}
		}
		cout << endl;
	}
	return 0;
}