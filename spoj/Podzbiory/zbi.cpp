#include <iostream>
#include <vector>
using namespace std;

#define p(a) 


int t; // ilosc testow
int n; // najwiekszy element ciagu
int k; // ilosc elementow podzbioru
vector< int > podzbior;


void change_digit( int cell_number )
{
	if( podzbior[cell_number] != n )
	{
		podzbior[cell_number] += 1;
	}
}


void read()
{
	cin >> n;
	cin >> k;
	p(cout<<"max element w zbiorze: "<<n<<endl;)
	p(cout<<"max ilosc elementow w podzbiorze: "<<k<<endl;)
}

void fill_podzbior()
{
	for( int i = 0 ; i < n ; i++ )
	{
		podzbior[i] = i+1;
	}
}

void print()
{
	for( int i = 0 ; i < podzbior.size() ; i++ )
	{
		cout <<podzbior[i]<<" ";
	}
	cout<<'\n';	
}

void algorithm()
{
	cin >> t;
	p(cout<<"ilosc testow: "<<t<<endl;)
	for( int i = 0  ; i < t ; i++ )
	{
		read();
		podzbior.resize( k );
		fill_podzbior();
		print();
		while( (n - podzbior[0]) >= k )
		{
			for( int cell_number = k ; cell_number >= 0 ; cell_number-- )
			{

				while( podzbior[cell_number] != n )
				{
					change_digit( cell_number );
					print();
				}
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	algorithm();
	return 0;
}
