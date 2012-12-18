#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define p(a)
#define s(a)a

struct node
{
	node():visited(false),visited_s(false),path_make(NULL),way(NULL){}
	bool visited; // to make a path
	bool visited_s;// to proceed a symulation
	node* path_make;
	node* way;
	int number;
	vector<node*> ngb;
};

typedef vector<node>::iterator n_it;
typedef vector<node*>::iterator np_it;

vector<node> nodes;
int n;

void read()
{
	cin >> n;
	nodes.resize(n);
	for( int i = 0 ; i < n-1 ; i++ )
	{
		int a; cin >> a;
		int b; cin >> b;
		a--; b--;
		nodes[a].ngb.push_back( &nodes[b] );
		nodes[b].ngb.push_back( &nodes[a] );
	}
	for( int i = 0 ; i < n ; i++ ) nodes[i].number = i+1;
}

void print()
{
	for( n_it it = nodes.begin() ; it != nodes.end() ; it++ )
	{
		cout<<"wierzcholek: "<<(*it).number<<endl;
		for( np_it ngb_it = it->ngb.begin() ; ngb_it != it->ngb.end()  ; ngb_it++ )
		{
			cout<<(*ngb_it)->number<<" ";
		}
		cout<<endl;
	}
}

void print_path()
{
	queue<node*> q;
	q.push( &nodes[0] );
	while( ! q.empty() )
	{
		node* actual = q.front();
		q.pop();
		cout<<actual->number<<endl;
		if( actual->way != 0 )
			q.push( actual->way );
	}
}

void reconstruct_path(node* start)
{
	queue<node*> q;
	q.push( start );
	node* predecessor = 0;
	while( ! q.empty() )
	{
		node* actual = q.front();
		q.pop();
		if( predecessor != 0 )
			actual->way = predecessor;
		predecessor = actual;
		if( actual->path_make != 0 )
			q.push( actual->path_make );
	}
}

bool make_path()
{
	queue<node*> q;
	node* end_of_path = &nodes[ n-1 ];
	end_of_path->way = 0;
	node* start = &nodes[0];
	start->path_make = 0;
	start->visited = true;
	q.push( start );
	while( !q.empty() )
	{
		node* actual = q.front();
		q.pop();
		for( np_it ngb_it = actual->ngb.begin() ; ngb_it != actual->ngb.end() ; ngb_it++ )
		{
			if( (*ngb_it) == end_of_path )
			{
				end_of_path->path_make = actual;
				reconstruct_path(end_of_path);
				return 1;
			}
			if( !(*ngb_it)->visited )
			{
				(*ngb_it)->visited = true;
				(*ngb_it)->path_make = actual;
				q.push( (*ngb_it) );
			}
		}
	}
	return 0;
}

bool belongs_to_path( node* vertex )
{
	if( vertex->way != 0 )
		return true;
	else
	{
		return false;
	}
}

bool is_crossroad( node* vertex )
{
/*	if( vertex->ngb.size() > 2 )
		return true;
	else
		return false;*/
	//lub
	
	int licznik = 0;
	for( np_it it = vertex->ngb.begin(); it != vertex->ngb.end(); it++ )
	{
		if( !(*it)->visited_s )
			licznik++;
		if( licznik > 2 )
			return true;
	}
	return false;
	
}

node* first_not_visited_ngb( node* vertex, node* predecessor )
{
	s(cout<<"vertex: "<<vertex->number<<endl;)
	for( np_it it = vertex->ngb.begin() ; it != vertex->ngb.end() ; it++ )
	{
		s(cout<<"aktualnie przetwarzany sasiad: "<<(*it)->number<<endl;)
		s(if( ! (*it)->visited_s )cout<<"nieodwiedzony"<<endl; else cout<<"odwiedzony"<<endl;)
		if( ! (*it)->visited_s && (*it) != predecessor && (*it) != vertex->way)
		{
			s(cout<<" zwracamy "<<(*it)->number<<endl;)
			return (*it);
		}
	}
	return 0;
}

node* first_ngb( node* vertex, node* predecessor )
{
	for( np_it it = vertex->ngb.begin() ; it != vertex->ngb.end() ; it++ )
	{
		s(cout<<"aktualnie przetwarzany sasiad: "<<(*it)->number<<endl;)
		if( (*it) != predecessor && (*it) != vertex->way)
		{
			s(cout<<" zwracamy "<<(*it)->number<<endl;)
			return (*it);
		}
	}
	return 0;
}

void symulate()
{
	//funkcja okreslajaca naleznosc do 'P',
	//belongs_to_path();
	//funkcja okreslajaca czy vertex jest skrzyzowaniem,
	//is_crossroad();
	//funkcja znajdujaca pierwszego nieodwiedzonego sasiada
	//first_not_visited_ngb();
	node* last_node = &nodes[ n-1 ];
	node pre_start;
	pre_start.number = 999999;
	pre_start.way = &nodes[0];
	node* predecessor = &pre_start;
	node* start = &nodes[0];
	queue<node*> q;
	q.push( start );
	while( ! q.empty() )
	{
		node* actual = q.front();
		q.pop();
		actual->visited_s = true;
		cout<<actual->number<<endl;
		if( actual->number != last_node->number )
		{
			if( belongs_to_path( actual ) )
			{
				s(cout<<"nalezy do path"<<endl;)
				if( is_crossroad( actual ) )
				{
					s(cout<<"jest skrzyzowaniem"<<endl;)
					node* next_node = first_not_visited_ngb( actual, predecessor );
					s(cout<<"next_node: "<<next_node->number<<endl;)
					predecessor = actual;
					node* to_be_visited_next_node = first_not_visited_ngb( next_node, predecessor );
					if( to_be_visited_next_node != 0 )
					{
						predecessor = actual;
						q.push( next_node );
					}
					else
					{
						predecessor = next_node;
						q.push( to_be_visited_next_node );					
					}
				}
				else
				{
					s(cout<<"nie jest skrzyzowaniem"<<endl;)
					node* next_node = actual->way;
					q.push( next_node );
				}
			}
			else
			{
				s(cout<<"nie nalezy do path"<<endl;)
				node* next_node = first_not_visited_ngb( actual,predecessor );
				if( next_node != 0 )
				{
					s(cout<<"ma nieodwiedzonego sasiada"<<endl;)
					predecessor = actual;
					node* to_be_visited_next_node = first_not_visited_ngb( next_node,predecessor );
					if( to_be_visited_next_node != 0 )
					{
						s(cout<<"ktory ma nieodwiedzonego sasiada"<<endl;)
						q.push( to_be_visited_next_node );
					}
					else
					{
						s(cout<<"ktory nie ma niedowiedzonego sasiada"<<endl;)
						//idziemy o jeden z actual czyli do next_node
						predecessor = actual;
						q.push( next_node );
					}
				}
				else
				{
					s(cout<<"nie ma niedowiedzonego sasiada"<<endl;)
					if( actual->ngb.size() < 2 )// jest ostatnim wierzcholkiem w rozgalezieniu
					{
						s(cout<<"jest ostatnim wierzcholkiem"<<endl;)
						next_node = first_not_visited_ngb( actual,0 );
						if( next_node != 0 )
						{
							s(cout<<"poprzedni byl nieodwiedzony"<<endl;)
							predecessor = actual;
							node* to_be_visited_next_node = first_not_visited_ngb(next_node, predecessor);
	//						node* to_be_visited_next_node = next_node->ngb[0];
							if( to_be_visited_next_node != 0 )
							{
								q.push( to_be_visited_next_node );
							}
							else
							{
								cout<<"NIE\n";
							}
						}
						else
						{
							s(cout<<"poprzedni byl odwiedzony"<<endl;)
							node* next_node = actual->ngb[0];
							predecessor = actual;
							s(cout<<next_node->number<<"LLLL"<<endl;)
							node* to_be_visited_next_node = first_not_visited_ngb(next_node, predecessor);
							if( to_be_visited_next_node != 0 )
							{
								q.push( to_be_visited_next_node );
							}
							else
							{
								to_be_visited_next_node = next_node->way;
								q.push( to_be_visited_next_node );
							}
						}
					}
				}
			}
		}
	}
}

void algorythm()
{
	if( make_path() )
	{
		p(cout<<endl;
		print_path();)
		symulate();
	}
	else
		cout<<"didn't find a path!"<<endl;
}


int main()
{
	ios_base::sync_with_stdio(0);
	read();
	p(print();)
	algorythm();
	return 0;
}
