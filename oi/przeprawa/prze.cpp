//notes: -jak posortowac po jednej ze zmiennych vector  <struct>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define d(a) cout<<#a<<a<<endl
#define p(a) cout<<#a<<endl

vector<int> times;
vector<int> weights;
vector<bool> visited;

int bridge_strenght;
int n;// the number of all hikers
int total_time = 0;

void read()
{
	cin >> bridge_strenght;
	cin >> n;
	times.resize( n );
	weights.resize( n );
	visited.resize( n );
	for( int i = 0 ; i < n; i++ )visited[i] = false;
	for( int i = 0 ; i < n ; i++ )
	{
		int a; cin >> a;
		int b; cin >> b;
		times[i] = a;
		weights[i] = b;
	}
}

void print()
{
	for( int i = 0 ; i  < times.size() ; i++ )
	{
		cout <<"number: "<<i<<" weight: "<<weights[i]<<" time: "<<times[i]<<endl;
	}
}

void algorithm()
{
	sort(times.begin(),times.end());
	p(sorted print: );
	print();
	int visited_nr = 0; // how many are grouped up
	while( visited_nr <= n )
	{
		d(visited_nr);
		int group_weight = 0;
		bool slowest = true;
		bool running = true;
		for( int i = times.size() ; running ; i-- )
		{
			d(i);
			d(group_weight);
			d(bridge_strenght);
			if( group_weight < bridge_strenght ) // tu bydzie zle bo moze przekroczyc bridge_strenght
			{
				if( !visited[i] )
				{
					visited[i] = true;
					group_weight += weights[i];
					if( slowest )
					{
						total_time += times[i];
					}
					visited_nr++;
				}
				slowest = false;
			}
			else
			{
				running = false;
			}
			slowest = true;
		}
	}
}

int main()
{
	read();
	print();
	algorithm();
	cout <<total_time<<'\n';
}
