//Rafal Pacut
#include <iostream>
#include <istream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define p(a) 

int n;
int k;
stack<int> black;
queue<int> white;
char sequence[1000001];
stack<int> answer;


void read()
{
	cin >> n;
	cin >> k;
	for( int i = 0 ; i < n ; i++ )
	{
		cin >> sequence[i];
	}
}

void push_answer()
{
	int index;
	index = black.top();
	black.pop();
	answer.push( index );
	for( int j = 0 ; j < k ; j++ )
	{
		index = white.front();
		answer.push( index );
		white.pop();
	}
}

void algorithm()
{
	int il_black = 0;
	int il_white = 0;
	for( int i = 0 ; i < n ; i++)
	{
		if( il_white == k && il_black > 0)
		{
			push_answer();
			il_white -= k;
			il_black --;
		}
		if( sequence[i] == 'b' )
		{
			white.push( i );
			il_white ++;
		}
		else
		{
			black.push( i );
			il_black ++;
		}
	}
	push_answer();
	while( !answer.empty() )
	{
		for( int i = 0 ; i < k+1 ; i++ )
		{
			int a = answer.top();
			answer.pop();
			cout <<a+1<<" ";
		}
		cout<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	algorithm();
	return 0;
}
