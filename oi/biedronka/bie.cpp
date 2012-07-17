//TO DO: all_disabled za pomoca count_disabled
// zmiana ukorzenienia zamiast bfs'a
//zdebaguj
#include <iostream>
#include <vector>
#include<climits>
#include <queue>
using namespace std;

#define t(a) cout << '(' << __LINE__ << ") "<< #a << ": " << a << endl
#define p(a) cout << a << endl

struct node
{
	int visited;
	node* r_parent;
	node* parent;
	vector<node*> ngb;
	int number;
};

struct ant
{
	int odgonione;
	bool disabled;
	node* placement;
};

typedef vector<node>::iterator n_it;
typedef vector<node*>::iterator np_it;
typedef vector<ant>::iterator a_it;

vector<node> nodes;
vector<ant> ants;
vector<node*> bied;


void read()
{
	int n;
	cin >> n;
	nodes.resize( n );
	for( int i = 0 ; i < n ; i++ )nodes[i].number = i+1;
	for( int i = 0 ; i < n-1 ; i++ )
	{
		int a;
		int b;
		cin>> a>> b;
		a--;
		b--;
		nodes[a].ngb.push_back( &nodes[b] );
		nodes[b].ngb.push_back( &nodes[a] );
	}
	int k;
	cin >> k;
	ants.resize(k);
	for( int i = 0 ; i < k ; i++ )
	{
		int placement;
		cin >> placement;
		placement--;
		nodes[placement].visited = 0;
		ants[i].placement = &nodes[placement];
	}
	int l;
	cin >> l;
	bied.resize(l);
	for( int i = 0 ; i < l ; i++ )
	{
		int a;
		cin >> a;
	 	a--;
	 	bied[i] = &nodes[a];
	 }
}

void print()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		cout<<"node: "<<it->number<<endl;
		for( np_it ngb = it->ngb.begin() ; ngb != it->ngb.end() ; ngb++ )
		{
			cout<<(*ngb)->number<<" ";
		}
		cout <<endl;
	}
	cout <<endl;
	for( a_it it = ants.begin() ; it != ants.end() ; it++ )
	{
		cout <<it->placement->number<<endl;
	}
}

void print_parent()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{	
		if( it->parent != 0 )
			cout <<"node: "<<it->number<<" parent: "<<it->parent->number<<endl;
		else
			cout <<"node: "<<it->number<<endl;
	}
	cout<<endl;
}

void make_parent(node* start)
{
	start->parent = 0;
	queue<node*> q;
	q.push( start );
	
	while( !q.empty() )
	{
		node* actual = q.front();
		q.pop();
		for( np_it it = actual->ngb.begin() ; it != actual->ngb.end() ; it++ )
		{
			if( (*it) != actual->parent )
			{
				(*it)->parent = actual;
				q.push( (*it) );
			}
		}
	}
}

node* go_back( int t, node* actual )
{
	for( int i = 0 ; i < t ; i++ )
	{
		if( actual->r_parent == 0 )
		{
			cout << "GO_BACK - ZA DUZO KROKOW" << endl;
		}
		actual = actual->r_parent;
	}
	return actual;
}

int t = 0;

void ant_print()
{
	cout<<"printing ants\n";
	for( a_it it = ants.begin() ; it != ants.end() ; it++ )
	{
		cout<<it->placement->number<<endl;
	}
}

void print_visited()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		cout <<"node: "<<it->number<<" visited: "<<it->visited;
		if(it->r_parent)
			cout << ", r_parent: " << it->r_parent->number;
		else
			cout << ", no r_parent"; 
		cout << endl;
	}
}


void step()
{
	++t;
	cout << "TIME IS " << t << endl;
	for( a_it it = ants.begin() ; it != ants.end() ; it++)
	{
		if(!it->disabled)
		{
			if( it->placement->parent != 0 )
			{
				node* actual = it->placement;
				node* next = actual->parent;
				if(next->visited != INT_MAX)
				{
					cout<<"powrot z "<<actual->number<<" o "<<t - it->placement->parent->visited - 1<<endl;
					actual= go_back( t - it->placement->parent->visited -1 , actual);
					cout<<" do "<<actual->number<<endl;
					it->disabled = true;
				}
				else
				{
					actual->parent->r_parent = actual;
					actual = actual->parent;
					actual->visited = t;
				}
				it->placement = actual;
				
/*				
				it->placement->parent->r_parent = it->placement;
				it->placement = it->placement->parent;
				if( it->placement->visited != INT_MAX )
				{
					cout<<"powrot o " <<  (t - it->placement->visited +1 ) <<" z: "<<it->placement->number<< endl;
					if(t - it->placement->visited +1 > 0)
						cout << "pierwszy krok do " << it->placement->r_parent->number << endl;;
					it->placement = go_back( t - it->placement->visited +1 , it->placement );
					it->disabled = true;
					cout<<"powrot do: " << it->placement->number<<endl;
				}
				else
				{
					it->placement->visited = t;
					//ant_print();
				}*/
			}
			else
			{
				//cout << "JESTESMY W KORZENIU MROWKA A CHCEMY ISC WYZEJ" << endl;
				//odgonila biedronke
				it->odgonione += 1;
				it->disabled = true;
				cout<<" biedronka odgoniona z : "<<it->placement->number<<endl;
			}
		ant_print();
		print_visited();
		}
	}
}

void reset()
{
	for( n_it it = nodes.begin() ; it !=nodes.end() ; it++ )
	{
		it->visited = INT_MAX;
		it->r_parent = 0;
	}
	for( a_it it = ants.begin() ; it != ants.end() ; it++ )
	{
		it->disabled = false;
	}
	t= 0;
	for( a_it it = ants.begin() ; it != ants.end() ; it++ )
	{
		it->placement->r_parent = 0;
		it->placement->visited = t;
	}
}

bool bied_na_mrowce( node* start )
{
	for( a_it it = ants.begin() ; it != ants.end() ; it++ )
	{
		if( it->placement == start )
		{
			it->odgonione += 1;
			return true;
		}
	}
	return false;
}

bool all_disabled()
{
	for( a_it it = ants.begin() ; it != ants.end() ; it++ )
	{
		if( !it->disabled )
			return false;
	}
	return true;
}


void algorithm()
{
	for( np_it it = bied.begin() ; it != bied.end() ; it++ )
	{
		cout<<"BIEDRONKA LADUJE w "<<(*it)->number<<endl;
		if( !bied_na_mrowce( (*it) ) )
		{
			reset();
			make_parent( (*it) );
			while( !all_disabled() )
				step();
		}
		else
			cout<<"skip step"<<endl;
	}
	int i = 0;
	for( a_it it = ants.begin() ; it != ants.end() ; it++ )
	{
		i++;
		cout<<"mrowka ("<<i<<") "<<"jest w "<<it->placement->number<<" i odgonila "<<it->odgonione<<" biedronek "<<endl;
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
