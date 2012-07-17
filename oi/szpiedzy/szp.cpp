#include <iostream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define D(a)
#define E(a) a

struct node
{
	node():mission(false), traced_by(0){}
	bool mission;
	int traced; // indeks
	int traced_by;
};

typedef map<int,node>::iterator n_it;

map<int,node> nodes;
int licznik = 0;

void read()
{
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ )
	{
		int a;
		cin >> a;
		nodes[i+1].traced = a;
		nodes[a].traced_by++;
	}
}

void flag( int start )
{
	cout << "aatempt to erase " << start << endl;
	nodes.erase(start);
	nodes[nodes[start].traced].traced_by--;
	
	if(!nodes[nodes[start].traced].mission)
	{
		nodes[nodes[start].traced].mission = true;
		nodes.erase(nodes[start].traced);
		nodes[nodes[nodes[start].traced].traced].traced_by--;
		licznik++;
	}
}

int get_not_traced()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		if( it->second.traced_by == 0 && !it->second.mission)
		{
			return it->first;
		}
	}
	return 0;
}

int get_from_cycle()
{
	if(nodes.empty())
		return 0;
	else
		return nodes.begin()->first;
}

void flag_cycle( int start )
{
	int vertices = 1;
	int actual = nodes[start].traced;
	while( actual != start )
	{
		vertices++;
		actual = nodes[actual].traced;
		nodes.erase(actual);
	}
	licznik += vertices / 2;
}

void process_cycles()
{
	while(true)
	{
		int start = get_from_cycle();
		if( start != 0 )
		{
			flag_cycle( start );
		}
		else
			break;
	}
}

void algorithm()
{
	while(true)
	{
		int start = get_not_traced();
		if( start != 0 )
		{
		cout << "flag from: " << start  << '\n';
			flag( start );
			cout << nodes.size() << endl;
		}
		else
		{
		E(cout << "PROCESS_CYCLES\n";)
			process_cycles();
			break;
		}
	}
	cout<<licznik<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
//	print();
//	r_print();
	algorithm();
	return 0;
}
