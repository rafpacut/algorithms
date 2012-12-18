//Rafał Pacut
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define MAX_INT 999999999
#define p(a)
#define l(a)

int source;
int rail_cost;
int fly_cost;
struct node;

struct edge
{
	edge():fly_edge(false){}
	bool fly_edge;
	node* ngb;
	int weight;
};


struct edges_cmp
{
	bool operator()(const edge& a, const edge& b) const
	{
		return a.ngb < b.ngb;
	}
};

struct node
{
	node():visited(false),distance(MAX_INT){}
	bool visited;
	int distance;
	int number;
	node* parent;
	set<edge,edges_cmp> edges;
};

struct node_cmp
{
	bool operator()( node* a, node* b )	
	{
		if( a->distance == b->distance )
			return a < b;
		else
			return a->distance < b->distance;
	}
};

typedef vector<node>::iterator n_it;
typedef vector<node*>::iterator np_it;
typedef set<node*,node_cmp>::iterator s_it;
typedef set<edge,edges_cmp>::iterator e_it;

set<node*,node_cmp> s;
vector<node> cities;

void print()
{
	for( n_it it = cities.begin() ; it != cities.end() ; it++ )
	{
		cout <<" miasto: "<<it->number<<'\n';
		for( e_it edg_it = it->edges.begin() ; edg_it != it->edges.end() ; edg_it++ )
		{
			cout <<(*edg_it).ngb->number<<" ";
		}
		cout<<'\n';
	}
}

void read()
{
	int n; cin >> n; 
	cities.resize(n);
	for( int i = 0 ; i < n ; i++ )cities[i].number = i+1;
	int m; cin >> m;
	cin >> source;
	source --;
	cin >> rail_cost;
	cin >> fly_cost;
	for( int i = 0 ; i < m ; i++ )
	{
		int a; cin >> a;
		int b; cin >> b;
		a--;
		b--;
		edge e;
		e.ngb = &cities[b];
		e.weight = rail_cost;
		cities[a].edges.insert( e );
		edge e2;
		e2.ngb = &cities[a];
		e2.weight = rail_cost;
		cities[b].edges.insert( e2 );
	}
}

void make_flight_paths()
{
	stack<node*> q;
	node* start = &cities[source];
	start->parent = 0;
	start->visited = true;
	q.push(start);
	while( ! q.empty() )
	{
		node* actual = q.top();
		actual->visited = true;
		q.pop();
		for( e_it it = actual->edges.begin() ; it != actual->edges.end() ; it++ )
		{
			if( it->ngb != actual->parent && ! it->fly_edge )
			{
				it->ngb->parent = actual;
				// zwyczajne dodawanie edge'y: 
				edge tmp;
				tmp.ngb = actual->parent;
				e_it temp_it = it->ngb->edges.find( tmp );
				if( temp_it == it->ngb->edges.end() && actual->parent != 0)// nie istnieje bezposrednia droga
				{
					//dodaj droge lotnicza
					edge flight_edge;
					flight_edge.ngb = actual->parent;
					flight_edge.weight = fly_cost;
					flight_edge.fly_edge = true;
					it->ngb->edges.insert( flight_edge );
					edge flight_edge2;
					flight_edge2.ngb = it->ngb;
					flight_edge2.weight = fly_cost;
					flight_edge2.fly_edge = true;
					actual->parent->edges.insert( flight_edge2 );
				}
				//dodawanie edg'y pomiedzy childrenami
				for( e_it ch_it = it; ch_it != actual->edges.end() ; ch_it++ )
				{
					if( ! ch_it->fly_edge )
					{
						edge tmp_edge;
						tmp_edge.ngb = ch_it->ngb;
						e_it tmp_it = it->ngb->edges.find( tmp_edge );
						if(tmp_it == it->ngb->edges.end() && ch_it != it)// nie istnieje bezposrednia droga
						{
							edge flight_edge;
							flight_edge.ngb = ch_it->ngb;
							flight_edge.weight = fly_cost;
							flight_edge.fly_edge = true;
							it->ngb->edges.insert( flight_edge );
							edge flight_edge2;
							flight_edge2.ngb = it->ngb;
							flight_edge2.weight = fly_cost;
							flight_edge2.fly_edge = true;
							ch_it->ngb->edges.insert( flight_edge2 );
						}
					}
				}
				if( ! it->ngb->visited )
					q.push( (*it).ngb );
			}
		}
	}
}

void shortest_paths()
{
	cities[source].distance = 0;
	for( n_it it = cities.begin() ; it != cities.end() ; it ++ )
	{
		s.insert( &(*it) );
	}
	while( !s.empty() )
	{
		node* start = (*s.begin());
		s.erase( start );
		for( e_it edg = start->edges.begin() ; edg != start->edges.end() ; edg++ )
		{
			s_it e_ngb = s.find( (*edg).ngb );
			if( e_ngb != s.end())
			{
				if( edg->ngb->distance > start->distance + (*edg).weight )
				{
					s.erase(e_ngb);
					edg->ngb->distance = start->distance + (*edg).weight;
					s.insert( (*edg).ngb );
				}
				p(cout<<" after: "<<edg->ngb->distance<<endl;)
			}
		}
	}
	for( n_it it = cities.begin() ; it != cities.end() ; it++ )
		cout<<it->distance<<endl;
}

void algorithm()
{
	make_flight_paths();
	shortest_paths();
}


int main()
{
	ios_base::sync_with_stdio(0);
	read();
	algorithm();
	return 0;
}

