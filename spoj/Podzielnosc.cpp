#include <iostream>
#include <vector>
using namespace std;

int x,y,n;
vector <int> wynik;

void read()
{
	cin >> n;
	cin >> x;
	cin >> y;
}

void print()
{
	for( int i = 0 ; i < wynik.size() ; i++ )
	{
		cout <<wynik[i]<<" ";
	}
	cout <<'\n';
	wynik.erase(wynik.begin(),wynik.end());
}

void search()
{
	for( int i = 1 ; i < n ; i++ )
	{
		if( i % x == 0 && i % y != 0 )
			wynik.push_back(i);
	}
	print();
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >>t;
	while( t > 0 )
	{
		read();
		search();
		t--;
	}
}
