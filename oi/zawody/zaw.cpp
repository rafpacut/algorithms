#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define D(a)

struct edge;

struct node
{
	node():time(INT_MAX){}
	int time;	
	int number;
	vector<edge> ngb;
	node* parent;
};

struct edge
{
	node* ngb;
	int weight;
};

struct node_cmp
{
	bool operator()( node* a,node* b )
	{
		if( a->time == b->time )
			return a < b;
		else
			return a->time < b->time;
	}
};

typedef vector<node>::iterator n_it;
typedef set<node*,node_cmp>::iterator s_it;
typedef vector<edge>::iterator e_it;

vector<node> nodes;
set<node*,node_cmp> s;

void read()
{
	int n;
	int m;
	cin >> n >> m;
	nodes.resize( n );
	for( int i = 0 ; i < n ; i++ ) nodes[i].number = i+1;
	for( int i = 0 ; i < m ; i++ )
	{
		int a;
		int b;
		int c;
		int d;
		cin >> a >>b >>c >>d;
		a--;
		b--;
		edge e;
		e.ngb = &nodes[b];
		e.weight = c;
		nodes[a].ngb.push_back( e );
		edge e1;
		e1.ngb = &nodes[a];
		e1.weight = d;
		nodes[b].ngb.push_back( e1 );
	}
}

void print()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		cout <<"node: "<<it->number<<'\n';
		for( e_it it2 = it->ngb.begin() ; it2 != it->ngb.end() ; it2++ )
		{
			cout <<" with  "<<it2->ngb->number<<"  of weight  "<<it2->weight<<'\n';
		}
	}
}

void write_nodes_to_set()
{
	for(n_it it = nodes.begin()  ; it != nodes.end() ; it++ )
	{
		s.insert( &(*it) );
	}
}


void print_times()
{
	for( n_it it = nodes.begin() ; it != nodes.end()  ; it ++ )
	{
		cout <<"node: "<<it->number<<"  with time: "<<it->time<<endl	;
	}
	cout <<endl;
}

void set_print()
{
	cout<<"-------------------------------------\nSET PRINT\n";
	for( s_it it = s.begin() ; it != s.end() ; it++ )
		cout<<(*it)->number<<" ";
	cout<<endl<<"-------------------------------------"<<endl;
}

void algorithm()
{
	write_nodes_to_set();
	node* start = &nodes[0];
	start->time = 0;
	while( !s.empty() )
	{
		node* actual = (*s.begin());
		s.erase( actual );
		D(cout<<"aktualnie przetwarzany wierzcholek: "<<actual->number<<endl;)
		for( e_it it = actual->ngb.begin() ; it != actual->ngb.end() ; it++ )
		{
			if( it->ngb != actual->parent )
			{
				it->ngb->parent = actual;
				D( cout <<"przetwarzam: "<<it->ngb->number<<endl; )
				s_it erase_it = s.find( (*it).ngb );
				if( erase_it != s.end() )
				{
					s.erase( erase_it );
					if( actual->time + it->weight < it->ngb->time )
					{
						it->ngb->time = actual->time + it->weight;
						s.insert( it->ngb );
					//	print_times();					
					}
					else
					{
						D( cout << it->ngb->time<<" < "<<actual->time + it->weight<<endl; )
						s.insert( it->ngb );
					}
				}
			}
		//	set_print();
		}
	}
	int min = INT_MAX;	
	for(n_it it = nodes.begin()  ; it != nodes.end() ; it++ )
	{
		D(cout<<"node: "<<it->number<<'\n';)
		for( e_it ngb = it->ngb.begin() ; ngb != it->ngb.end() ; ngb++) 
		{
			if( ngb->ngb == &nodes[0] )
			{
				D(cout<<"has 1 in ngb's\n";)
				if( ngb->weight + it->time < min )
				{
					D(cout<<"and shorter distance: "<<ngb->weight + it->time<<" than : "<<min<<'\n';)
					min = ngb->weight + it->time;
				}
			}
		}
	}
	cout <<min<<'\n';
}

void a2()
{
	write_nodes_to_set();
	nodes[0].time = 0;
	while( !s.empty() )
	{
		node* actual = (*s.begin());
		s.erase( actual );
		D(cout<<"aktualnie przetwarzany wierzcholek: "<<actual->number<<endl;)
		for( e_it it = actual->ngb.begin() ; it != actual->ngb.end() ; it++ )
		{
			if( it->ngb != actual->parent )
			{
				s_it erase_it = s.find( (*it).ngb );
				if( erase_it != s.end() )
					s.erase( erase_it );
				it->ngb->parent = actual;
				D( cout <<"przetwarzam: "<<it->ngb->number<<endl; )
				if( actual->time + it->weight < it->ngb->time )
				{
					it->ngb->time = actual->time + it->weight;
					s.insert( it->ngb );
					print_times();
				}
				else
				{
					D( cout << it->ngb->time<<" < "<<actual->time + it->weight<<endl; )
					s.insert( it->ngb );
				}				
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
//	print();
	algorithm();
//	a2();
	return 0;
}
