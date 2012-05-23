#include <iostream>

#include <cstdio>

using namespace std;



string kod, zadanie;

const int d = int('Z')-int('A')+1;



void read()

{

	cin >> zadanie;

	cin >> kod;	

}



int main()

{

	read();

	char s;

	while( ( s = getchar() ) != '\n' );

	s = 1;

	if( zadanie == "SZYFRUJ" )

	{

		for( int p = 0 ; (s = getchar()) != '\n' ; p++ )

		{

			s += (kod[p]-48);

			if( s > 'Z' )
				s -= d;

			if( p == kod.length()-1 )

				p = -1;

			cout << s ;

		}

	}

	else

	{

		for( int p = 0; ( s = getchar() ) != '\n' ; p++ )

		{

			s -= (kod[p]-48);

			if( s < 'A' )

				s +=d;

			if( p == kod.length()-1 )

				p = -1;

			cout <<s;

		}	

	}
cout <<'\n';
}
