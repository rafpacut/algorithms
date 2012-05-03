#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define pb push_back
int n; // number of all students
double average = 0.0; // the average of all student's expences
vector<double> expences; // all student's expences


bool read()
{
	double h;
	cin >> n;
	if ( n != 0 )
	{
		for( int i = 0 ; i < n ; i++ )
		{
			cin >> h;
			expences.pb(h);
		}
		return true;
	}
	return false;
}

void count_average()
{
	for ( int i = 0 ; i < expences.size() ; i++ )
	{
		average += expences[i];
	}
	average /= n;
}

double count_min()
{
	double min;
	for( int i = 0 ; i < expences.size() ; i++ )
	{
		if( expences[i] >= average )
			break;
		min += ( average - expences[i] );
		min *= 100;
		min = int(min);
		min /= 100;
	}
	return min;
}

int main()
{
	ios_base::sync_with_stdio(0);
	while( read() )
	{
		count_average();
		sort(expences.begin(),expences.end());
		cout.precision(2);
		cout << fixed 
			<< count_min() <<'\n';
		expences.erase(expences.begin(),expences.end());
	}
}
