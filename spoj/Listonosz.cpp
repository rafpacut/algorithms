// listonosz, LISTFRAN
#include <iostream>
#include <vector>
using namespace std;

int poczatek;
int liczba_ulic;

struct vertex
{
	vector<int> ngb;
};

vector<vertex> graf;

void print()
{
	for( int i = 0 ; i < graf.size() ; i++ )
	{
		for( int j = 0 ; j < graf[i].ngb.size() ; j++ )
		{
			cout <<graf[i].ngb[j]<<" ";
		}
		cout <<'\n';
	}
}

void read()
{
	int a;
	int b;
	cin >> liczba_ulic >> poczatek;
	graf.reserve(liczba_ulic);	//kurde sam nie wiem ;]
	while ( liczba_ulic > 0 )
	{
		cin >> a;
			cout <<"costam2\n";		
		cin >> b;
		cout <<"a: "<<a<<" "<<"b: "<<b<<'\n';
		graf[a].ngb.push_back(b);
		cout <<graf[a].ngb[0]<<'\n';
		graf[b].ngb.push_back(a);
		liczba_ulic--;		
	}
	cout <<"costam";
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	print();
}
