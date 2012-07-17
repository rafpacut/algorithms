#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#define p(a)
#define d(a)

struct tree
{
	int number;
	int wsp;
	int height;
};

typedef vector<tree>::iterator t_it;

vector<tree> t;
int total;
int previous_total;

void read()
{
	int n; cin >> n;
	t.resize( n );
	for( int i = 0 ; i < n ; i++ )t[i].number = i+1;
	for( int i = 0 ; i < n ; i++ )
	{
		int a;
		cin >> a;
		t[i].height = a;
	}
}

void print()
{
	for( t_it it = t.begin() ; it != t.end() ; it++ )
	{
		cout<<it->height<<endl;
	}
	cout <<endl;
}

void set_wsp()
{
	total = 0;
	for( t_it it = t.begin() ; it != t.end() ; it++ )
	{
		if( (it+1) != t.end() )
		{
			total += abs((it->height) - ((it+1)->height));
			d(cout<<(it)->height<<" - "<<(it+1)->height<<" = "<<abs((it->height) - ((it+1)->height))<<endl)
		}
	}
	d(cout<<"total: "<<total<<endl)
}

void print_wsp()
{
/*	for( t_it it = t.begin() ; it != t.end() ; it++ )
	{
		cout<<it->wsp<<endl;
	}
	cout<<endl;*/
}

void compute_optimal()
{
	for( int it = 0; it != t.size(); it ++ )
	{
		for( int i = 0 ; i != t.size() ; i++ )
		{
			if( it != i )
			{
				d(cout<<"zamieniam: "<<t[it].height<<" z "<<t[i].height<<endl)
				int a;
				a = t[it].height;
				t[it].height = t[i].height;
				t[i].height = a;
				set_wsp();
				if( total < previous_total )
				{
					previous_total = total;
					t[it].wsp = total;
				}
				//zamien spowrotem
				int b;
				a = t[it].height;
				t[it].height = t[i].height;
				t[i].height = a;
				print_wsp();				
			}
		}
		d(cout<<"setting new previous total: "<<endl)
		set_wsp();
		previous_total = total;
	}
}

void algorithm()
{
	set_wsp();
	for( t_it it = t.begin() ; it != t.end() ; it++ )
	{
		it->wsp = total;
	}
	previous_total = total;
	compute_optimal();
	print_wsp();
	for( t_it it = t.begin() ; it != t.end() ; it++ )
	{
		cout<<it->wsp<<'\n';
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
