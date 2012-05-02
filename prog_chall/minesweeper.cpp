#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define pb push_back

int n;
int m;
int t = 0;
vector<int> vec;


bool read()
{
	char input;
	cin >> n >> m;
	if( n == 0 && m == 0 )
	{
		return false;
	}
	for( int i = 1 ; i <= n ; i++ )
	{
		for( int j = 1 ; j <= m ; j++ )
		{
			cin >> input;
			if ( input == '*' )
			{
				vec.pb(j);
				vec.pb(i);
			}
		}
	}
	return true;
}

int count(int i, int j)
{
	int v = 0;
	for( int u = 0; u < vec.size() ; u += 2 )
	{
		if( abs( j - vec[u] ) <= 1 && abs( i - vec[u+1] ) <= 1 )
			v ++;
	}
	return v;
}

void form()
{
	cout <<"Field #"<<t<<":\n";
	for( int i = 1 ; i <= n ; i++ )
	{
		for( int j = 1 ; j <= m ; j++ )
		{
			for( int z = 0 ; z < vec.size() ; z+=2 )
			{
				if( j == vec[z] && i == vec[z+1] )
				{
					cout <<'*'<<" ";
					j++;
				}
			}
				cout <<count(i,j)<<" ";
		}
		cout <<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	while( read() )
	{
		form();
		t++;
		vec.erase(vec.begin(),vec.end());
	}
}
