#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define D(a) ;
struct node
{
	node():mission(false),visited(false){}
	bool mission;
	bool visited;	
	int number;
	node* traced;
	vector<node*> traced_by;
};

typedef vector<node>::iterator n_it;
typedef vector<node*>::iterator np_it;

vector<node> nodes;
int licznik = 0;

void read()
{
	int n;
	cin >> n;
	nodes.resize( n );
	for( int i = 0 ; i < n ; i++ ) nodes[i].number = i+1;
	for( int i = 0 ; i < n ; i++ )
	{
		int a;
		cin >> a;
		a--;
		nodes[i].traced = &nodes[a];
		nodes[a].traced_by.push_back( &nodes[i] );
	}
}

void print()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		cout << "node : "<<it->number<<"traces: "<<it->traced->number<<'\n';
	}
}

void r_print()
{
	cout <<"r print\n";
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		cout <<"node: "<<it->number<<'\n';
		for(np_it it2 = it->traced_by.begin() ; it2 != it->traced_by.end() ; it2++ )
		{
			cout <<(*it2)->number<<" ";
		}
		cout <<'\n';
	}
}



void flag( node* start )
{
	queue<node*> q;
	start->visited = true;
	q.push( start->traced );
	node* previous = start;
	while( !q.empty() )
	{
		node* actual = q.front();
		D(cout <<"teraz przetwarzany: "<< actual->number<<'\n' )
		q.pop();
		if( !actual->visited )
		{
			if( !previous->mission )
			{
				D( cout << "mission: "<<actual->number<<'\n')
				actual->visited = true;
				actual->mission = true;
				previous = actual;
				q.push( actual->traced );
			}
			else
			{
				actual->visited = true;
				previous = actual;
				q.push( actual->traced );
			}								
		}
	}
}

node* get_not_traced()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		if( it->traced_by.empty() && !it->visited)
		{
			D(cout<<"zaczynamy z: "<<it->number<<'\n')
			return &(*it);
		}
	}
	return &(*nodes.end());
}

void algorithm()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		node* start = get_not_traced();
		if( start != &(*nodes.end()) )
		{
			flag( start );
		}
		else
		{
			flag( &(*it) );
		}
	}
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		if( it->mission )
		{
			D( cout <<"mission node: "<<it->number<<endl )
			licznik++;
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
