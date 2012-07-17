#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define d(a) 
#define p(a) 

struct employee
{
	employee():visited(false){}
	bool visited;
	int number;
	vector<employee*> co_workers;
};

typedef vector<employee>::iterator e_it;
typedef vector<employee*>::iterator ep_it;

vector<employee> v;
vector<int> biura;

void read()
{
	int n; cin >> n;
	int m; cin>> m;
	v.resize( n );
	for( int i = 0 ; i < n ; i++ ) v[i].number = i+1;
	for( int i = 0 ; i < m ; i++ )
	{
		int a; cin>>a;
		int b;cin>>b;
		a--;
		b--;
		d(cout << i+1 << " - " << a << ' ' << b << '\n')
		v[a].co_workers.push_back( &v[b] );
		v[b].co_workers.push_back( &v[a] );
	}
	d( cout<<"read"<<endl )
}

void find_non_co_workers( employee* start )
{
	int licznik = 0;
	queue<employee*> q;
	q.push( start );
	while( !q.empty() )
	{
		employee* actual = q.front();
		q.pop();
		d(cout<<"przegladamy sasiadow "<<actual->number<<endl)
		for(e_it all = v.begin(); all != v.end(); ++all)
		{
			d(cout<<"szukamy: "<<all->number<<endl)
			if( !all->visited )
			{
				d(cout<<"nie odwiedzony "<<endl)
				employee* to_find = &(*all);
				if(!binary_search(actual->co_workers.begin(), actual->co_workers.end(), to_find))
				{
					d(cout<<"znaleziony"<<endl)
					q.push( &(*all) );
				licznik++;
					all->visited = true;
				}
			}
		}
	}
	biura.push_back( licznik );
}

void algorithm()
{
	for( e_it it1 = v.begin() ; it1 != v.end() ; it1++ )sort( it1->co_workers.begin(),it1->co_workers.end() );
	d( cout<<"sorted"<<endl )
	for( e_it it = v.begin() ; it != v.end() ; it++ )
	{
		if( !it->visited )
		{
			find_non_co_workers( &(*it) );
		}
	}
	sort( biura.begin(),biura.end() );
	d(cout<<"buira size"<<endl;)
	cout<<biura.size()<<'\n';
	for( int i = 0 ;i < biura.size()  ; i++ )
	{
		cout<<biura[i]<<" ";
	}
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	algorithm();
	return 0;
}
