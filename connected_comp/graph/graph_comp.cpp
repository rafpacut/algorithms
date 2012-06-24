//dla drzew
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	node() : visited(false) {}
	bool visited;
	int number;
	vector<node*> ngb;
};

typedef vector<node>::iterator vn_it;
typedef vector<node>::iterator vnp_it;

vector<node> v;
int comp = 0;

void read()
{
	int n;
	int m;
	cin >> n;
	cin >> m;
	v.reserve(n);
	for( int i = 0 ; i < n ; i ++ )
	{
		node nd;
		nd.number = i+1;
		v.push_back( nd );
	}
	for( int i = 0 ;i < m  ; i++ )
	{
		int a;
		int b;
		cin >> a;
		cin >>b;
		a--;
		b--;
		v[a].ngb.push_back( &v[b] );
		v[b].ngb.push_back( &v[a] );
	}
}

void print()
{
	for( vn_it it1 = v.begin(); it1 < v.end()  ; it1++ )
	{
		cout <<"node: "<<it1->number<<'\n';
		for( vector<node*>::iterator it = it1->ngb.begin() ;it != it1->ngb.end() ; it++ )
		{
			cout <<(*it)->number<<" ";
		}
		cout <<'\n';
	}
}

void count_comp(node* start)
{
	int visited = 0;
	queue<node*> q;
	q.push( start );
	while( !q.empty() )
	{
		node* n = q.front();
		if( !n->visited )
		{
			n->visited = true;
			visited++;
		}
		q.pop();
		for( vector<node*>::iterator ngbit = n->ngb.begin() ; ngbit != n->ngb.end() ; ngbit ++ )
		{
			if( !(*ngbit)->visited )
				q.push( *ngbit );
		}
	}
	cout <<"vertices: "<<visited<<'\n';
	comp++;
}

int main()
{
	read();
//	print();
	for( vector<node>::iterator it = v.begin() ;it != v.end()  ; it++ )
	{
			if(  !it->visited )
				count_comp( &(*it) );
	}
	cout <<"components: "<<comp<<'\n';
}
