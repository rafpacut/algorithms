#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node
{
	node(bool _visited = false):visited(_visited){}
	bool visited;
	int value;
	int x;
	int y;
};

vector<node> grid;
stack<int> s;
int grid_side;
bool hill = false;
bool valley = false;
int hill_total;
int valley_total;

node* get_node(int x, int y)
{
	if( x < 0 || x >= grid_side )
		return 0;
	if( y < 0 || y >= grid_side )
		return 0;
	return &grid[grid_side * y + x];
}


void read()
{
	cin >> grid_side;
	grid.resize( grid_side*grid_side );
	for( int y = 0 ; y < grid_side ; y++)
	{
		for( int x = 0 ; x < grid_side ; x++)
		{
			node* actual = get_node(x,y);
			int c;
			cin >> c;
			actual->value = c;
			actual->x = x;
			actual->y = y;
		}
	}
}

void print()
{
	for( int y = 0 ; y < grid_side ; y++)
	{
		for( int x = 0 ; x < grid_side ; x++)
		{
			cout <<get_node(x,y)->value;
		}
		cout <<'\n';
	}
}

void get_ngb( int x, int y )
{
	//rozpatrz wielkosci noda i wepchnij do stosu x i y noda
	//zrob z tego 1 funcje i przekazuj x i y zmienione ...
	node* start = get_node(x,y);
	node* actual;
	if( get_node(x-1,y-1) )
	{	
		actual = get_node(x-1,y-1);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
	if( get_node(x,y-1) )
	{
		actual = get_node(x,y-1);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
	if( get_node(x+1,y-1) )
	{
		actual = get_node(x+1,y-1);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
	if( get_node(x-1,y) )
	{
		actual = get_node(x-1,y);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
	if( get_node(x+1,y) )
	{
		actual = get_node(x+1,y);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
	if( get_node(x-1,y+1) )
	{
		actual = get_node(x-1,y+1);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
	if( get_node(x,y+1) )
	{
		actual = get_node(x,y+1);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}	
	if( get_node(x+1,y+1) )
	{
		actual = get_node(x+1,y+1);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
}


void get_ngb_2(int start_x, int start_y, int x, int y)
{
	node* start = get_node(start_x,start_y);
	node* actual;
	if( get_node(x,y) )
	{	
		actual = get_node(x,y);
		if( actual->value == start->value && !actual->visited)
		{
			actual->visited = true;
			s.push(actual->x);
			s.push(actual->y);
		}
		else
		{
			if( actual->value > start->value )
				valley = true;
			else if( actual->value < start->value )
				hill = true;
		}
	}
}

void make_a_field(int start_x, int start_y)
{
	get_node(start_x,start_y)->visited = true;
	get_ngb(start_x,start_y);
	while( !s.empty() )
	{
		start_y = s.top();
		s.pop();
		start_x = s.top();
		s.pop();
//		get_ngb(start_x,start_y);
		int x = start_x;
		int y = start_y;
		get_ngb_2(start_x,start_y,x-1,y+1);
		get_ngb_2(start_x,start_y,x,y+1);
		get_ngb_2(start_x,start_y,x+1,y+1);
		get_ngb_2(start_x,start_y,x-1,y);
		get_ngb_2(start_x,start_y,x+1,y);
		get_ngb_2(start_x,start_y,x-1,y-1);
		get_ngb_2(start_x,start_y,x,y-1);
		get_ngb_2(start_x,start_y,x+1,y-1);
	}
	//a hill or a valley ?
	
/*	if( hill != valley )
	{
		if( valley )
			valley_total += 1;
		else
			hill_total += 1;
	}
*/	
	if ( !valley && !hill )
	{
		valley_total += 1;
		hill_total += 1;
	}
	if( !valley && hill )
		hill_total += 1;
	if( valley && !hill )
		valley_total += 1;
		
	
	hill = 0;
	valley = 0;
}

void algorithm()
{
	int count = 0;
	for( int y = 0 ; y < grid_side ; y++ )
	{
		for( int x = 0 ; x < grid_side ; x++ )
		{
			if( !get_node(x,y)->visited )
			{
				make_a_field(x,y);
				count++;
			}
		}
	}
	cout <<hill_total<<" "<<valley_total<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
//	print();
	algorithm();
}
