
#include <set>
#include <array>
#include <vector>
#include <cstddef>
#include <iostream>
#include <algorithm>

using namespace std;

constexpr         char K(2);
constexpr std::size_t  N(32);
constexpr std::size_t  J(500);

typedef std::array<char, N>     jamcoin_type;
typedef std::set<long long>     divisor_set_type;
typedef std::vector<long long>  divisor_collection_type;

void combination_N( char k, std::size_t n, jamcoin_type& jamcoin, std::size_t& j );

bool isPrime( long long num, divisor_collection_type& array_divisors, divisor_set_type& set_divisors ) {
    if( num == 1 ) {
        return false;
    } else if( (set_divisors.find( 2 ) == set_divisors.end( ) ) && (num % 2 == 0 ) ) {
		set_divisors.insert(2);
		array_divisors.push_back( 2 );
        return false;
    } else if( (set_divisors.find( 3 ) == set_divisors.end( ) ) && (num % 3 == 0) ) {
		set_divisors.insert( 3 );
		array_divisors.push_back(3);
		return false;
    } else {
        for (long long i = 5; i * i <= num; i += 6) {
            if( (set_divisors.find( i ) == set_divisors.end( ) ) && ( num % i == 0 ) ) {
				set_divisors.insert( i );
				array_divisors.push_back(i);
				return false;
            }
            else if( (set_divisors.find( i + 2 ) == set_divisors.end( ) ) && (num % (i + 2) == 0) ) {
				set_divisors.insert( i + 2 );
				array_divisors.push_back(i+2);
				return false;
            }
        }
        return true;
    }
}

void combination_N( char k, std::size_t n, jamcoin_type& jamcoin, std::size_t& j )
{
	if( j > 0 )
	{
		if( n > 0 )
		{
			for (char k(0); k < K; ++k)
			{
				jamcoin[n - 1] = '0' + k;
				combination_N( K, n - 1, jamcoin, j );	
			}
		}
		else
		{
			// first/last digit
			if( jamcoin[0   ] != '1' ) return;
			if( jamcoin[N- 1] != '1' ) return;

			char *end;
			divisor_collection_type array_divisors;
			divisor_set_type set_divisors;
			for( int base( 2 ); base <= 10; ++ base )
			{
				const auto number( std::strtoll( &jamcoin[0], &end, base ) );

				if( isPrime( number, array_divisors, set_divisors ) )
				{
					return;
				}
			}

			for (auto&& c : jamcoin) cout << c;

			for( auto&& divisor : array_divisors ) cout << " " << divisor;

			cout << endl;

			--j;
		}
	}
}

void combination( char K, std::size_t n, jamcoin_type& jamcoin, std::size_t& j )
{
	combination_N( K, n, jamcoin, j );
}

int main(int argc, char* argv[])
{
	cout << "Case #1:" << endl;

	std::size_t j( J ); 
	jamcoin_type jamcoin;
	combination( K, N, jamcoin, j );

	return 0;
}