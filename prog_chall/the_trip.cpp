#include <iostream>
using namespace std;

float srednia = 0; // srednia wydatkow wycieczki
int n; // ilosc uczestnikow wycieczki
float t[20];

bool read()
{
	cin >> n;
	if ( n == 0 )
	{
		return false;
	}
	for( int i = 0 ; i < n ; i++ )
	{
		cin >> t[i];
	}
	return true;
}

void licz_srednia()
{
	for( int i = 0 ; i < n ; i++ )
		srednia += t[i];
	srednia /= n;
	cout <<"srednia: "<<srednia<<'\n';
}

void licz_roznice_od_sredniej()
{
	float roznica = 0;
	for( int i = 0 ; i < n ; i++ )
	{
		roznica += ( t[i] - srednia );
		cout <<"roznica: "<< roznica<< '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	while ( read() )
	{
		licz_srednia();
		licz_roznice_od_sredniej();
		srednia = 0;
	}
}
