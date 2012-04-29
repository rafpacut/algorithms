#include <iostream>

using namespace std;

int wynik;
int n = 0;
void algorithm()
{
	cin >> wynik;
	while( wynik != 1 )
	{
		if( (wynik % 2) == 0 )
			wynik /= 2;
		else
			wynik = 3*wynik+1;
		n++;
	}
	cout <<n<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while ( t > 0 )
	{
		algorithm();
		n = 0;
		t --;
	}
}
