#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int m; // liczba krawedzi
int n; // liczba wierzcholkow

struct vertex
{
  vertex(int n) : no(n) {}
  vector<int> ngb; // sasiedzi
  int no;
};

vector<vertex> vs;

int main()
{
  ios_base::sync_with_stdio(0);

  cin >> n >> m;

  vs.reserve(n);
  for(int i = 0; i < n; ++i)
  {
    vs.push_back(vertex(i + 1));
  }

  const bool symmetric = false;
  
  for(int i = 0; i < m; ++i)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;

    vs[a].push_back(b);

    if(symmetric)
      vs[b].push_back(a);
  }

  vertex& first = vs[0];

  for(int i = 0; i < first.ngb.size(); ++i)
    cout << i->no << '\n';
  
  return 0;
}
