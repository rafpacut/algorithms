#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int strings_num = 0;
int longest_string = 0;

struct node
{
	int number;
	node* parent;
	int distance;
	vector<node*> ngb;
	node(int _number = 0):number(_number){}
	
	bool isLeaf()
	{
		 return ngb.size() == 1;
	}
};

vector<node*> v;

void read()
{
	int m;
	cin >> m;
	v.resize(m);
	for( int i = 0 ; i < m ; i++ )
	{
		v[i] = new node();
		v[i]->number = i + 1;
	}
	for( int i = 0 ; i < m-1 ; i++ )
	{
		int a;
		int b;
		cin >>a;
		cin >> b;
		v[a-1]->ngb.push_back(v[b-1]);
		v[b-1]->ngb.push_back(v[a-1]);
	}
}

void print()
{
	for( int i = 0 ; i < v.size() ; i++ )
	{
		node* n = v[i];
		cout <<" node: "<<n->number<<'\n';
		for( int j = 0 ; j < n->ngb.size() ; j++ )
		{
			cout <<n->ngb[j]->number<<'\n';
		}
	}
}

node* find_leaf()
{
	for( int i = 0 ; i < v.size() ; i++ )
	{
		if( v[i]->isLeaf( ) )
			return v[i];
	}
	return 0;
}

node* find_closest_leaf(node* start)
{
	queue<node*> s;
	s.push( start );
	start->distance = 0;
	start->parent = 0;
	while( !s.empty() )
	{
		node* actual = s.front();
		s.pop();
		
		
		
		for( vector<node*>::iterator i = actual->ngb.begin(); i != actual->ngb.end() ; i++ )
		{
			node* ngb = *i;
			if( ngb != actual->parent )
			{
				ngb->distance = actual->distance +1;
				ngb->parent = actual;
				
				if( ngb->isLeaf() )
				{
					return ngb;
				}
				s.push(ngb);
			}
		}
		
	}
}

bool there_are_leafs()
{
	if(find_leaf() == 0)
		return false;
	return true;
}

void algorithm()
{
	while(there_are_leafs())
	{
		node* best_start = 0;
		node* best_closest = 0;
		int min_dist = INT_MAX;
	
		for(vector<node*>::iterator it = v.begin(); it != v.end(); ++it)
		{
			node* start = *it;
			if(start->isLeaf())
			{
				node* closest = find_closest_leaf(start);
				if(closest->distance < min_dist)
				{
					min_dist = closest->distance;
					best_start = start;
					best_closest = closest;
				}
			}
		}
	
		best_start->parent = 0;
		node* it = best_closest;
		find_closest_leaf(best_start);
			
		while( it->parent != 0 )
		{
			it->ngb.erase(find(it->ngb.begin(), it->ngb.end(), it->parent));
			it->parent->ngb.erase(find(it->parent->ngb.begin(),it->parent->ngb.end(),it));
			it = it->parent;
		}
		strings_num++;
		longest_string = max(longest_string, best_closest->distance);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
//	print();
	
	algorithm();
	cout <<strings_num<<" "<<longest_string<<'\n';
	return 0;
}
