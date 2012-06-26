#include <iostream>
#include <vector>
using namespace std;

struct node
{
	node(bool _visited = false):visited(_visited){}
	bool visited;
	int value;
};

vector<node> grid;
int grid_side;

node* get_node(int x, int y)
{
	if( x < 0 || x > grid_side )
		return 0;
	if( y < 0 || y > grid_side )
		return 0;
	return &grid[x * y + x];
}

void read()
{
	cin >> grid_side;
	grid.resize( grid_side*grid_side );
	for( vector<node>::iterator it = grid.begin() ; it != grid.end() ; it++ )
	{
		int c;
		cin >> c;
		(*it).value = c;
	}
}

void print()
{
	for( int y = 0 ; y <grid_side ; y++ )
	{
		for( int x = 0 ; x < grid_side ; x++ )
		{
			cout <<get_node(x,y)->value;
		}
		cout <<'\n';
	}
}

void get_ngb(int x, int y)// to JEST CHUJOWY POMYSL
{
	node* n;
	node* actual = get_pos(x,y);
	if( get_pos( x-1,y-1 ) )
	{
		if(! get_pos(x-1,y-1)->visited )
		{
			if(  )			
		}
	}
}

void get_same_valuated_fields()
{
	for( int y = 0 ; y < grid_side ; y++ )
	{
		for( int x = 0 ; x < gris_side ; x++ )
		{
			node* n = get_node(x,y)
			if(! n->visited)
			{
				n->visited = true;
				get_ngb(x,y);
			}
		}
	}
}

void algorithm()
{
	get_same_valued_fields(); // & mark them as visited, rate whether it's a valley or a hill
	
}

int main()
{
	read();
	print();
	algorithm();
}
