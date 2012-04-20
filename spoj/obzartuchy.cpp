#include <iostream>
#include <vector>
using namespace std;

vector<int> obzartuch;
int pudelka;
int n;
int ilosc_pudelek;
int ciastka;

void ilosc_ciastek()
{
	for( int i = 0 ; i < obzartuch.size() ; i++ )
	{
		ciastka += 86400/obzartuch[i];
	}
}

void read()
{
	cin >> n;
	cin >> pudelka;
	int g;
	for( int i = 0 ; i < n ; i++ )
	{
		cin >> g;
		obzartuch.push_back(g);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >>t;
	while( t != 0 )
	{
		read();
		ilosc_ciastek();
		if( ciastka % pudelka > 0 )
			cout<<((ciastka / pudelka)+1) << '\n';
		else
			cout<< (ciastka/pudelka)<< '\n';
		obzartuch.erase(obzartuch.begin(),obzartuch.end());
		ciastka = 0;
		t--;
	}
}
