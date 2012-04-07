//dla 3 i 567 nie dziala (za dlugo nie wiem czy daje rozwiazanie) ma wyjsc 7 i 61, chyba mialo byc jednak rekurencyjnie ;]

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int wynik;
	int n = 0;
	cin >> wynik;
	while( wynik != 1 )
	{
		if( (wynik % 2) == 0 )
			wynik /= 2;
		else
			3*wynik+1;
		n++;
	}
	cout <<n<<'\n';
}
