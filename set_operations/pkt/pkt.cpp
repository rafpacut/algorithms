#include <iostream>
#include <set>
using namespace std;

struct point
{
	int x;
	int y;
};

struct pt_cmp
{
	bool operator()( const point& a, const point& b ) const
	{
		return (a.x*a.x)+(a.y*a.y) < (b.x*b.x)+(b.y*b.y);
	}
};

multiset<point,pt_cmp> s;

void read()
{
	point p1;
	point p2;
	point p3;
	point p4;
	point p5;
	p1.x = 1;
	p1.y = 1;
	p2.x = 4;
	p2.y = 10;
	p3.x = 6;
	p3.y = 12;
	p4.x = 22;
	p4.y = 4;
	p5.x = 9;
	p5.y = 9;
	s.insert( p1 );
	s.insert( p2 );
	s.insert( p3 );
	s.insert( p4 );
	s.insert( p5 );
}

void print()
{
	for( multiset<point,pt_cmp>::iterator it = s.begin() ; it != s.end() ; it++ )
	{
		cout <<(*it).x<<" "<<(*it).y<<endl;
	}
}

int main()
{
	read();
	print();
}
