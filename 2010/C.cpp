
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int N;
	cin >> N;

	const char* lut_alpha[] = {
		"2"   , // 'a'
		"22"  , // 'b'
		"222" , // 'c'
		"3"   , // 'd'
		"33"  , // 'e'
		"333" , // 'f'
		"4"   , // 'g'
		"44"  , // 'h'
		"444" , // 'i'
		"5"   , // 'j'
		"55"  , // 'k'
		"555" , // 'l'
		"6"   , // 'm'
		"66"  , // 'n'
		"666" , // 'o'
		"7"   , // 'p'
		"77"  , // 'q'
		"777" , // 'r'
		"7777",// 's'
		"8"   , // 't'
		"88"  , // 'u'
		"888" , // 'v'
		"9"   , // 'w'
		"99"  , // 'x'
		"999" , // 'y'
		"9999"  // 'z'
	};

	const int lut_alpha_bucket[] = {
		2 , // 'a'
		2 , // 'b'
		2 , // 'c'
		3 , // 'd'
		3 , // 'e'
		3 , // 'f'
		4 , // 'g'
		4 , // 'h'
		4 , // 'i'
		5 , // 'j'
		5 , // 'k'
		5 , // 'l'
		6 , // 'm'
		6 , // 'n'
		6 , // 'o'
		7 , // 'p'
		7 , // 'q'
		7 , // 'r'
		7 ,// 's'
		8 , // 't'
		8 , // 'u'
		8 , // 'v'
		9 , // 'w'
		9 , // 'x'
		9 , // 'y'
		9   // 'z'
	};

	char probe;
	int previous_bucket( -1 ); 
	
	cin.get( probe );
	for (decltype(N) idx_test_case(1); idx_test_case <= N; ++idx_test_case)
	{
		/// Input / Algorithm / Output
		cout << "Case #" << idx_test_case << ": ";
		
		previous_bucket = -1;

		do
		{
			cin.get( probe );

			if (cin.eof())
			{
				break;
			}
			if( 'a' <= probe && probe <= 'z' )
			{
				const std::size_t offset( probe - 'a' );

				const char *& sequence( lut_alpha[offset] );
				const int&    bucket  ( lut_alpha_bucket[offset] );
				if( bucket == previous_bucket )
				{
					cout << " ";
				}
				cout << sequence;
				previous_bucket = bucket;
			}
			else if( probe == ' ' )
			{
				const int bucket( 0 );
				if( bucket == previous_bucket )
				{
					cout << " ";
				}
				cout << "0";
				previous_bucket = bucket;
			}
		}
		while( !( probe == '\n' || cin.eof( ) ) );
		cout << endl;
	}
	return 0;
}