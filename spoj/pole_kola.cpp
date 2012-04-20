#include <iostream>
#include <cmath>
using namespace std;

float d;
float r;
float r_sz;
void read()
{
	cin >> r >> d;
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	cout.precision(2);
	cout.setf( ios::fixed );
	r_sz = pow(r,2) - pow(d/2,2);
	r_sz = sqrt(r_sz);
	cout <<M_PI*pow(r_sz,2)<<'\n';
}
