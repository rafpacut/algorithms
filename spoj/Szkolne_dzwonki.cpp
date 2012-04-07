#include <iostream>
using namespace std;
int hour;
char delimiter;
int minute;
int s;

void convert_into_hhmm()
{
	while( minute >= 60 )
	{
		minute -= 60;
		hour ++;
	}
}


void print()
{
	convert_into_hhmm();
	if( hour < 10 )
		cout<<0;
	cout <<hour<<':'<<minute;
	if( minute == 0 )
		cout <<0;
	cout <<',';
}

void read()
{
	cin >> hour >> delimiter >> minute;
}

int main()
{	
	ios_base::sync_with_stdio(0);
	read();
	print();
	minute += 45;
	print();
	while( cin >> s )
	{
		minute += s;
		print();
		minute += 45;
		print();
	}
}
