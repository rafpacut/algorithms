#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int d;
int n;
double odl;
int ciecia;

void read()
{
	cin >> d;
	cin >> n;
}

void tnij()
{
	if( n % 2 == 0 )
		ciecia = n/2;
	else
	{
		ciecia = n;
	}
	odl = (M_PI*d)/ (ciecia*2);
	printf ("%.3f %d\n",odl,ciecia);
}

int main()
{
	
	int t;
	scanf( "%d", &t );
	for( ; t > 0 ; t-- )
	{
		read();
		tnij();
	}
}
