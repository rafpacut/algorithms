#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

struct edge;

struct node
{
	node():distance(-1){}
	long long distance;
	int number;
	vector<edge> edges;	
	node* parent;
};

struct edge
{
	node* ngb;
	int weight;		
};

struct node_cmp
{
	bool operator()( node* a, node* b ) const
	{
		return (a->distance) < (b->distance);
	}
};

#define D(a) cout<<a<<endl;
typedef vector<node>::iterator n_it;
typedef vector<edge>::iterator e_it;
typedef multiset<node*,node_cmp>::iterator s_it;

vector<node> nodes; 
multiset<node*,node_cmp> s;

void read()
{
	int n;
	cin >> n;
	nodes.resize(n);
	for( int i = 0 ; i < n ; i++ )nodes[i].number = i+1;
	for( int i = 0 ; i < n-1 ; i++ )
	{
		int a;
		int b;
		int weight;
		cin >> a >> b >>weight;
		a--;
		b--;
		edge e;
		e.ngb = &nodes[b];
		e.weight = weight;
		nodes[a].edges.push_back( e );
		edge e2;
		e2.ngb = &nodes[a];
		e2.weight = weight;
		nodes[b].edges.push_back( e2 );
	}
}

void print()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		cout<<it->number<<" :\n";
		for( e_it edg_it = it->edges.begin() ; edg_it != it->edges.end() ; edg_it++ )
		{
			cout <<edg_it->ngb->number<<" of weight: "<<edg_it->weight<<" ";
		}
		cout <<endl;
	}
}

void algorithm()
{
	node* start = &nodes[7];
	node* end = &nodes[1];
	start->distance = 0;
	s.insert( start );
	while( !s.empty())
	{
		node* actual = (*s.begin());
		s.erase( s.begin() );
		for( e_it ngb_it = actual->edges.begin(); ngb_it != actual->edges.end() ; ngb_it++ )
		{
			if( ngb_it->ngb->distance == -1 )
			{
				ngb_it->ngb->distance = actual->distance + ngb_it->weight;
				if( ngb_it->ngb == end )
				{
					cout << "distance koncowy = "<<ngb_it->ngb->distance<<endl;
					return ;
				}
				s.insert( ngb_it->ngb );
			}
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
//	print();
	algorithm();
	return 0;
}
