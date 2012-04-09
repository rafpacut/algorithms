//cout,cin za wolne trzeba bylo uzyc printf'a 
#include <iostream>
#include <cmath>
#include <iomanip>
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
/*	cout	<<odl<<" "
		<<ciecia<<'\n';
*/
	printf ("%.3f %d\n",odl,ciecia);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int t;
	cout << setprecision (3)
		<<fixed;
	cin >> t;
	for( ; t > 0 ; t-- )
	{
		read();
		tnij();
	}
}
