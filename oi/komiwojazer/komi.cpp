#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//#define D(a) cout<<__LINE__ << ": " << #a << " = " <<  a<<endl;
#define D(a)
//#define T(a) cout<<__LINE__ << ": " <<  a<<endl;
#define T(a)
struct node
{
	node():visited(false){}
	bool visited;
	int distance;
//	int number;
	node* parent;
	vector<node*> ngb;
};

typedef vector<node>::iterator  n_it;
typedef vector<node*>::iterator  np_it;


vector<node> nodes;
vector<node*> cities;

void read()
{
	int il_miast;
	int m;
	cin >> il_miast;
	nodes.resize(il_miast);
	int a;
	int b;
	for( int i = 0 ; i < il_miast-1 ; i++ )
	{
		cin >> a >> b;
		a--;
		b--;
		nodes[a].ngb.push_back( &nodes[b] );
		nodes[b].ngb.push_back( &nodes[a] );
	}
	cin >> m;
	cities.resize(m);
	for( int i = 0 ; i < m ; i++ )
	{
		int a;
		cin >> a;
		a--;
		cities[i] = &nodes[a];
	}
}

void write_distance()
{
	queue<node*> q;
	node* start = &nodes[0];// losuj roota
	start->parent = 0;
	start->distance = 0;
	q.push( start );
	while( !q.empty() )
	{
		node* actual = q.front();
		q.pop();
		for( np_it ngb_it = actual->ngb.begin()  ; ngb_it != actual->ngb.end() ; ngb_it ++ )
		{
			if( (*ngb_it) != actual->parent )
			{
				(*ngb_it)->parent = actual;
				(*ngb_it)->distance = actual->distance +1;
				q.push( *ngb_it );
			}
		}
	}
}

void start_way( node* start )
{
	node* actual = start;
	while( actual != 0 )
	{
		actual->visited = true;
		D(actual->number)
		actual = actual->parent;
	}
}

node* find_lca(node* start)
{
	node* actual = start;
	while( actual != 0 )
	{
		if( actual->visited )
		{
			return actual;
		}
		D(actual->number)
		actual=actual->parent;
	}
	return 0;
}

void erase_way(node* start)
{
	node* actual = start;
	while( actual != 0 )
	{
		actual->visited =false;
		D(actual->number)
		actual = actual->parent;
	}
}

int find_way(node* start, node* end)
{
	if( start == end )
		return 0;
	start_way(start);
	node* lca = find_lca(end);
	T("wycieczka z " << start->number  << " do " << end->number <<" lca to: "<<lca->number<< " trwa " <<  (start->distance - lca->distance) + ( end->distance - lca->distance ))
	erase_way(start);
	return (start->distance - lca->distance) + ( end->distance - lca->distance );
}

void algorithm()
{
	int dis = 0;
	write_distance();
	dis += find_way(&nodes[0],cities[0]);
	for( np_it it = cities.begin()+1 ; it != cities.end() ; it++)
	{
		dis += find_way( *(it-1) , (*it ) );
	}
	cout<<dis<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	algorithm();
	return 0;
}
