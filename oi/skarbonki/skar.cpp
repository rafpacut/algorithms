#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//#define D(a) cout<<__LINE__ << ": " << #a << " = " <<  a<<endl;
#define D(a)

struct node
{
	node(): visited(false),marked(false){}
	bool visited;
	bool marked;
//	int number;
	node* where_my_key_is;
	vector<node*> i_open;
};
typedef vector<node>::iterator  n_it;
typedef vector<node*>::iterator  np_it;

vector <node> nodes;
int rozbicie = 0;

void read()
{
	int n;
	cin >> n;
	D(n)
	nodes.resize(n);
//	for( int i = 0 ; i < n ; i++ )nodes[i].number = i+1;
	for( int i = 0 ; i < n ; i++ )
	{
		int key_nr;
		cin >> key_nr;
		D(key_nr)
		key_nr --;
		nodes[i].where_my_key_is = &nodes[key_nr];//reverse read for looking for cycles
		nodes[key_nr].i_open.push_back( &nodes[i] );//normal read for marking back
	}
}

/*void print()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		if( it->visited )
			cout<<"(V) ";
		cout <<it->number<<" my key is in: "<<it->where_my_key_is->number<<'\n';
		cout<<"i open: ";
		for( np_it it2 = it->i_open.begin() ; it2 != it->i_open.end() ; it2++ )
		{
			cout <<(*it2)->number<<" ";
		}
		cout <<'\n';
	}
}*/

void mark_back(node* actual)
{
	queue<node*> q;
	q.push(actual);
	actual->marked = true;
	while( !q.empty() )//zle napisane
	{
		actual = q.front();
		q.pop();
		for( np_it r_it = actual->i_open.begin() ; r_it != actual->i_open.end(); r_it++ )
		{
			if( !(*r_it)->marked )
			{
				(*r_it)->marked= true;
				q.push( *r_it );
			}
		}
	}
}

void find_cycles( node* actual )
{
	while( !actual->visited )
	{
		actual->visited = true;
		actual = actual->where_my_key_is;
	}
	rozbicie++;
	mark_back(actual);
}

void algorithm()
{
	for( n_it it = nodes.begin(); it != nodes.end(); it++ )
	{
		if( !it->marked )
			find_cycles(&(*it));
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	read();
//	print();
	algorithm();
	cout<<rozbicie<<'\n';
	return 0;
}
