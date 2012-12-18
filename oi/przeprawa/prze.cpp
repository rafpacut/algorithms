//notes: -jak posortowac po jednej ze zmiennych vector  <struct>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define d(a) cout<<#a<<a<<endl
#define p(a) cout<<#a<<endl

struct hiker
{
	hiker(bool _visited = false ) : visited( _visited ) {}
	bool visited;
	int time;
	int weight;
	bool compare( const hiker& h1, const hiker& h2)  const
	{
		return h1.weight < h2.weight
	}
};

vector <hiker> hikers;
typedef vector<hiker>::iterator it_h;
typedef vector<hiker*>::iterator it_hp;

int bridge_strenght;
int n;// the number of all hikers
int total_time = 0;

void read()
{
	cin >> bridge_strenght;
	cin >> n;
	hikers.resize ( n );
	for( int i = 0 ; i < n ; i++ )
	{
		int a; cin >> a;
		int b; cin >> b;
		hikers[i].time = a;
		hikers[i].weight = b;
	}
}

void print()
{
	for( it_h it = hikers.begin() ; it < hikers.end() ; it++ )
	{
		cout<<"time: "<<it->time<<" weight: "<<it->time<<endl;
	}
}

void algorithm()
{
	sort(times.begin(),times.end(),compare);
	print();
	int visited_nr = 0; // how many are grouped up
	while( visited_nr <= n )
	{
		int group_weight = 0;
		bool slowest = true;
		bool running = true;
		for( int i = times.size() ; running ; i-- )
		{
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
