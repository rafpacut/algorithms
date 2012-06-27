#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include <stack>
using namespace std;

struct node
{
	int weight;
	int path_length;
	node* parent;
};

node& min_node_by_path(node* a, node* b, node* c)
{//spr czy nie sa 0
	if(a.path_length < b.path_length)
	{
		if(c.path_length < a.path_length)
			return c;
		else
			return a;	
	}
	else
	{
		if(c.path_length < b.path_length)
			return c;
		else
			return b;
	}
}

vector<node> grid;

int size_x;
int size_y;
	
node* G(int x, int y)
{
	if(y < 0 || y > size_y)
		return 0;
	return &grid[y * size_x + x];
}

int paths_get(int x, int y)
{
	if( y < 0|| y >= size_y)
		return INT_MAX;
	else
		return grid[y * size_x + x].path_length;
}

void read()
{
	cin >>size_x;
	cin >> size_y;
	
	grid.resize(size_x * size_y);
	
	for( int y = 0; y < size_y; y++  )
		for( int x =  0; x < size_x ; x++ )
		{
			int c;
			cin >> c;
			G(x, y).weight = c;
		}
}

void print_paths()
{
	for(int y = 0; y < size_y; ++y)
	{
		for(int x = 0; x < size_x; ++x)
		{
			cout <<  G(x, y).path_length << ' ';
		}
		cout << '\n';
	}	
}
void print_grid()
{
	for(int y = 0; y < size_y; ++y)
	{
		for(int x = 0; x < size_x; ++x)
		{
			cout <<  G(x, y).weight << ' ';
		}
		cout << '\n';
	}	
}

void get_cost()
{
	// copy first column
	for( int y = 0 ; y <  size_y; ++y)
	{
		G(0, y).path_length = G(0, y).weight;
	}
	
	for( int x = 1  ; x < size_x ; x++ )
	{
		int actual_x = x;
		int prev_x = actual_x - 1;

		for( int y = 0 ; y < size_y ; y++ )
		{
			node& min_node = min_node_by_path(G(prev_x, y - 1), G(prev_x, y), G(prev_x, y + 1));
			G(actual_x,y).path_length = min_node.path_length + G(actual_x, y).weight;
			G(actual_x, y).parent = &min_node;
		}
	}
	int min_path = INT_MAX;
	for( int y = 0 ; y < size_y ; y++ )
	{
		min_path = min(min_path, G(size_x-1 ,y ).path_length);
	}
	cout << min_path<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	print_grid();
	get_cost();
	cout << "***\n";
	print_paths();
	return 0;
}

