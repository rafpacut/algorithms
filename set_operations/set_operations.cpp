#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

set<int> s1;
set<int> s2;
set<int> s3;
vector<int> intersection;

void read()
{
  int m;
  int n;
  int u;
  cin >> m;
  cin >> n;
  for(int i = 0  ;i < m  ; i++ )
    {
      cin >> u;
      s1.insert(u);
    }
  for( int i = 0 ;i < n  ;i++  )
    {
      cin >> u;
      s2.insert(u);
    }
}

void print()
{
  set<int>::iterator it;
  for(it = s1.begin()  ;it != s1.end()  ; it++ )
    {
      cout<<" "<<*it;
    }
  cout <<'\n';
  for(it = s2.begin()  ; it != s2.end() ; it++ )
    {
      cout <<" "<<*it;
    }
  cout <<'\n';
}

void inter()
{
  intersection.reserve(max(s1.size(), s2.size()));
  set_intersection( s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
}

void remove_even()
{
  set<int>::iterator it;
  for(it = s3.begin()  ;it != s3.end()  ;it++  )
    {
      if(*it % 2 == 0)
	s3.erase(it);
    }
  copy(s3.begin(), s3.end(), ostream_iterator<int>(cout, "\n"));
}

int main()
{
  ios_base::sync_with_stdio(0);
  read();
  print();
  inter();
  remove_even();
  return 0;
}
