#include <iostream>
using namespace std;

int i;
int j;
int k; // current result
int n = 1; // maximum cycle lenght between i and j

void read()
{
	cin >> i;
	cin >> j;
}


void print()
{
	cout << i <<" "<<j<<" "<<n<<'\n';
}

int main()
{
	read();
	k = i;
	while( k != j )
	{
		if( k % 2 == 0 )
		{
			k /= 2;
			n++;
		}
		else
		{
			k *= 3;
			k += 1;
			n++;
		}
	}
	print();
}
