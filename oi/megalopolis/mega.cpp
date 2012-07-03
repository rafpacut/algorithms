#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define D(a) 
#define E(a) cout << a << '\n'

struct node
{
	int number;
	map<node*,bool> edges_map;
	node* parent;
};

vector<node> nodes;


void autostrada(int start, int end)
{
	{
		map<node*,bool>::iterator it = nodes[start].edges_map.find( &nodes[end] );
		if( it !=  nodes[start].edges_map.end() )
		{
			it->second = true;
		}
	}
	
	{
		map<node*,bool>::iterator it = nodes[end].edges_map.find( &nodes[start] );
		if( it !=  nodes[end].edges_map.end() )
		{
			it->second = true;
		}
	}
}

void print()
{
	for( int i = 0 ; i < nodes.size() ; i++ )
	{
		cout <<i+1<<" : ";
		for( map<node*,bool>::iterator it1 = nodes[i].edges_map.begin() ; it1 != nodes[i].edges_map.end(); it1 ++ )
		{
			cout <<(*it1).first->number<<" ";
			if( it1->second )
				cout <<"(A) ";
			else
				cout << "(D) ";
		}
		cout <<'\n';
	}
}

void wroc( node* end )
{
	node* it = end;
	int road = 0;
	D(cout << "poczatek powrotu do 1 z " << end->number << endl);
	while( it->parent != 0 )
	{
		D(cout << "idziemy z " << it->number << " do " << it->parent->number);
		if(! it->edges_map.find( it->parent )->second )
		{
			road ++;
			D(cout << " (R)");
		}
		it = it->parent;
		D(cout << endl);
	}
	D(cout <<"road: ");
	cout<<road<<'\n';
}

void wyprawa( int end )
{
	if( end == 0 )
	{
		cout <<"0"<<'\n';
		return;
	}
	nodes[0].parent = 0;
	queue<node*> q;
	q.push(&nodes[0]);
	while( !q.empty() )
	{
		node* front = q.front();
		q.pop();
		D(cout << "przeszukujemy " << front->number << endl);
		for( map<node*,bool>::iterator it = front->edges_map.begin() ; it != front->edges_map.end() ; it++ )
		{
			if( it->first != front->parent )
			{
				it->first->parent = front;
				if( it->first == &nodes[end] )
				{
					wroc(&nodes[end]);
					return; 
				}
				q.push( it->first );
			}
		}
	}
	D(cout << "nie znaleziono end = " << end + 1 << endl);
}

void read()
{
	int n;
	cin >> n;
	nodes.resize(n);
	for( int i = 0 ; i <  n ; i++ )nodes[i].number = i+1;
	for( int i = 0 ; i < n-1 ; i++ )
	{
		int a;
		int b;
		cin >> a >> b;
		a--;
		b--;
		pair<node*,bool> p;
		p.first = &nodes[b];
		p.second = false;
		nodes[a].edges_map.insert( p );
		
		pair<node*,bool> p2;
		p2.first = &nodes[a];
		p2.second = false;
		nodes[b].edges_map.insert( p2 );
	}
	
	int m;
	cin >> m;
	for( int i = 0 ; i < n+m-1 ; i++ )
	{
		//E('c');
		char type;
		cin >> type; 
		if( type == 'A' )
		{
			int n1, n2;
			cin >> n1 >> n2;
			D(cout <<"tworze autostrade z "<<n1<<" do "<<n2<<'\n');
			autostrada(n1 - 1,n2 - 1);
			D(print());
		}
		else if (type == 'W')
		{
			int n_end;
			cin >> n_end;
			D(cout <<"arg: "<<n_end<<" !wyprawa!\n");
			wyprawa(n_end-1);
		}
		else
			D(cout << "blad typu.\n");
	}
	
	
}



int main()
{
	ios_base::sync_with_stdio(0);
	read();
	return 0;
}
