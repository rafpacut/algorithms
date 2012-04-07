#include <iostream>
using namespace std;

int k1,k2,lr1,lr2;

void read()
{
	cin >> k1;
	cin >> lr1;
	cin >> k2;
	cin >> lr2;
}

int main()
{
	read();
	k1 *= lr1;
	k2 *= lr2;
	k2 +=k1;
	cout << k2;
}
