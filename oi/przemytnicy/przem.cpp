#include<iostream>
#include <set>
#include <vector>
#include<climits>
using namespace std;

#define D(a) 
#define E(a) 

struct node;

struct edge
{
	node* ngb;
	int weight;
};

struct node
{
	node():summary_weight(INT_MAX){}
	unsigned long long summary_weight;
	unsigned long long total;	
D(	int number;)
	int clo;
	vector<edge> edges;
	vector<edge> r_edges;
};

struct node_cmp
{
	bool operator()( node* a, node* b )
	{
		if(a->summary_weight == b->summary_weight)
			return a < b; 
		return a->summary_weight < b->summary_weight;
	}
};

typedef vector<node>::iterator n_it;
typedef vector<node*>::iterator np_it;
typedef vector<edge>::iterator e_it;
typedef set<node*,node_cmp>::iterator s_it;

vector<node> nodes;
set<node*,node_cmp> s;

void read()
{
	int n;
	cin >> n;
	nodes.resize( n );
	D(for( int i = 0; i < n; i++)nodes[i].number = i+1;)
	for( int i = 0 ; i < n ; i++ )
	{
		int a;
		cin >> a;
		a /= 2;
		nodes[i].clo = a;
	}
	int m;
	cin >> m;
	for( int i = 0 ; i < m ; i++ )
	{
		int a;
		int b;
		int weight;
		cin >> a >> b >> weight;
		a--;
		b--;
		edge e;
		e.ngb = &nodes[b];
		e.weight = weight;
		nodes[a].edges.push_back( e );
		
		edge r_e;
		r_e.ngb = &nodes[a];
		r_e.weight = weight;
		nodes[b].r_edges.push_back( r_e );
	}
}

D(void set_print()
{
	for( s_it it = s.begin() ; it != s.end() ; it++ )
	{
		cout <<"number "<<(*it)->number<<" of total weight:" <<(*it)->summary_weight<<'\n';
	}
	cout<<endl;
})

void shortest_paths()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it ++ )
	{
		s.insert( &(*it) );
	}
	D(set_print();)
	(*s.begin())->summary_weight = 0;
	while( !s.empty() )
	{
		node* start = (*s.begin());
		s.erase( start );
		D(cout <<"przetwarzamy wierzcholek: "<<start->number<<'\n';)
		for( e_it edg = start->edges.begin() ; edg != start->edges.end() ; edg++ )
		{
			s_it e_ngb = s.find( (*edg).ngb );
			if( e_ngb != s.end())
			{
				s.erase(e_ngb);
				if( edg->ngb->summary_weight > start->summary_weight + (*edg).weight )
				{
					edg->ngb->summary_weight = start->summary_weight + (*edg).weight;
					s.insert( (*edg).ngb );
				}
			}
		}
		D(set_print();)
	}
	D(
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
		cout <<"number: "<<it->number<<"  summary weight: "<<it->summary_weight<<endl;
	)
}

void write_total()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		it->total = it ->summary_weight + it->clo;
	}
}

void r_shortest_paths()
{
	s.clear();
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
		it->summary_weight = INT_MAX;
	for( n_it it = nodes.begin() ; it != nodes.end() ; it ++ )
	{
		s.insert( &(*it) );
	}
	E(set_print();)
	(*s.begin())->summary_weight = 0;
	while( !s.empty() )
	{
		node* start = (*s.begin());
		s.erase( start );
		D(cout <<"przetwarzamy wierzcholek: "<<start->number<<'\n';)
		for( e_it edg = start->r_edges.begin() ; edg != start->r_edges.end() ; edg++ )
		{
			s_it e_ngb = s.find( (*edg).ngb );
			if( e_ngb != s.end())
			{
				s.erase(e_ngb);
				if( edg->ngb->summary_weight > start->summary_weight + (*edg).weight )
				{
					edg->ngb->summary_weight = start->summary_weight + (*edg).weight;
					s.insert( (*edg).ngb );
				}
			}
		}
		E(set_print();)
	}D(
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
		cout <<"number: "<<it->number<<"  summary weight: "<<it->summary_weight<<endl;
	)
}

void print_answer()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		it->total += it->summary_weight;
	}
	int min = INT_MAX;
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		if( it->total < min )
			min = it->total;
	}
	cout <<min<<'\n';
}

void algorithm()
{
	shortest_paths();
	write_total();
	r_shortest_paths();
	print_answer();
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	algorithm();
	return 0;
}
