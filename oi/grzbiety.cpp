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
int hill;
int valley;
int hill_total;
int valley_total;

node* get_node(int x, int y)
{
	if( x < 0 || x > grid_side )
		return 0;
	if( y < 0 || y > grid_side )
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
				valley++;
			else
				hill++;
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
				valley++;
			else
				hill++;
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
				valley++;
			else
				hill++;
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
				valley++;
			else
				hill++;
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
				valley++;
			else
				hill++;
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
				valley++;
			else
				hill++;
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
				valley++;
			else
				hill++;
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
				valley++;
			else
				hill++;
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
		get_ngb(start_x,start_y);
	}
	cout <<hill<< " "<<valley<<'\n';
	//a hill or a valley ?
	if( hill > valley )
		hill_total += 1;
	else if( valley < hill )
		valley_total += 1;
	else if( valley = hill )
	{
		valley_total +=1;
		hill_total += 1;
	}
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
	cout <<"fields: "<<count<<'\n';
	cout <<"hill: "<<hill_total<<'\n';
	cout <<"valley: "<< valley_total <<'\n'; 
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	print();
	algorithm();
}
