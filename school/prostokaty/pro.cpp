//przyjete ze dostajemy matryce 10x10 bo nie wiem jak wyglada wejscie
#include <iostream>
#include <vector>
using namespace std;

struct cell
{
	cell( bool _worthy=false ): worthy(_worthy){}
	bool worthy;
	int value;
};

cell t[10][10];
int points[4];
vector<int> results;

void read()
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		for( int j = 0 ; j < 10 ; j++ )
		{
			int a;
			cin >> a;
			t[i][j].value = a;
		}
	}
}

void print()
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		for( int j = 0 ; j < 10 ; j++ )
		{
			cout<<t[i][j].value<<" ";
		}
		cout<<'\n';
	}
}

bool is_worthy( int value )
{
	return value < 0;
}

void fill_boolean()
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		for( int j = 0 ; j < 10 ; j++ )
		{
			
			if( is_worthy( t[i][j].value ) )
				t[i][j].worthy = true;
			else
				t[i][j].worthy = false;
		}
	}
}

void widen_the_rectangle( int x, int y )// zmniejszac obszar!
{
	for( int i = y ; i < points[1] ; i++ )
	{
		for( int j = x ; j < points[0] ; j++ )
		{
			if( !t[i][j].worthy )
			{
				points[2] = i;
				points[3] = j;
			}
		}
	}
}

void go_down( int x, int y, bool one )
{
	for( int i = y+1 ; i < 10 ; i++ )
	{
		if( !t[x][i].worthy )
		{
			if( i != y )// nie 1x1
			{
				if( !one ) // szerokosc > 1
				{
					widen_the rectangle( x,i );
				}
				else // szerokosc == 1
				{
					for( int j = y ; j < i ; j++ )
					{
						results[current] += t[x][j];//current zainicjalizuj !!!
					}
				}
			}
		}
	}
}

void go_right( int x, int y )// w razie znalezienia wejscia do programu tutaj modyfikowac!
{
	bool one = false; // is only 1 cell wide
	points[0] = x;
	points[1] = y;
	for( int i = x+1 ; i < 10 ; i++ )
	{
		if( !t[i][y].worthy )
		{
			results.push_back( t[i][j].value );
			if( i == x )
				one = true;
			go_down( x,y,one );
		}
	}
}

void make_a_rectangle()
{
	for( int i = 0 ; i < 10 ; i++ )
	{
		for( int j = 0 ; j < 10 ; j++ )
		{
			if( t[i][j].worthy )
				//zacznij tworzyc
				go_right( i,j );
		}
	}
}

int main()
{
	ios_base::syn_with_stdio(0);
	//wczytaj matryce
	read();
	print();
	//wypelnij matryce boolami
	fill_boolean();
	//stworz prostokaty
	make_a_rectangle();
}
