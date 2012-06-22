#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


struct point
{
	int x;
	int y;
	
	point(int _x = 0, int _y = 0) : x(_x), y(_y)
	{
	}
	/*	
	bool operator<(const point& p) const
	{
		if(p.x == x)
			return p.y < y;
		return p.x < x;
	}
	*/
	friend ostream& operator<<(ostream& os, const point& p)
	{
		return os << p.x << " " << p.y << '\n';
	}
	friend istream& operator>>(istream& is, point& p)
	{
		return is >> p.x >> p.y;
	}
};

point center;

struct point_comparator
{
	bool operator()(const point a, const point b)
	{
		int d1 = (a.x - center.x ) * ( a.x - center.x ) + ( a.y - center.y )*( a.y - center.y );
		int d2 = ( b.x - center.x )*( b.x - center.x ) + ( b.y - center.y )*( b.y - center.y );
		return d1 < d2;
	}
};


void algorithm()
{
	multimap<point, string, point_comparator> s;
	cin >> center;
	int m;
	int x;
	int y;
	cin >> m;
	for( int i = 0 ;i < m; i++ )
	{
		point p;
		string str;
		cin >> p >> str;
		s.insert(pair<point, string>(p, str));
	}
	
	point lower_point(center.x + 3, center.y);
	point upper_point(center.x + 7, center.y);
	multimap<point, string,point_comparator>:: iterator lower = lower_bound(s.begin(),s.end(),lower_point, point_comparator());
	multimap<point, string,point_comparator>:: iterator upper = upper_bound(s.begin(),s.end(),upper_point, point_comparator());
	for(multimap<point, string,point_comparator>:: iterator it = lower ; it != upper ; ++it)
	{
		cout <<(*it).first << ' ' << (*it).second << endl;
	}
}


int main()
{
	algorithm();
}
