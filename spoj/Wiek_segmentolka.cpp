#include <iostream>
using namespace std;

int wynik = -1;
void read()
{
	int segmenty;
	int nozki;
	cin >> segmenty;
	wynik += segmenty;
	while( segmenty > 0 )
	{
		cin >> nozki;
		wynik += nozki;
		segmenty --;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while( t > 0 )
	{ 
		read();
		cout << wynik<< " ";
		wynik = -1;
		t--;
	}
	
}
