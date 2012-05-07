#include <iostream>
using namespace std;
string t[10][5]={
	{"-","| |"," ","| |","-"},
	{" ","|"," ","|"," "},
	{"-"," |","-","| ","-"},
	{"-"," |","-"," |","-"},
	{" ","| |","-"," |"," "},
	{"-","| ","-"," |","-"},
	{"-","| ","-","| |","-"},
	{"-"," |"," "," |"," "},
	{"-","| |","-","| |","-"},
	{"-","| |","-"," |","-"},
	};

string str;
int s;




void read()
{
	cin >> s;
	cin >> str;
}

int main()
{
	read();
	int h = s-1;
	int h2 = s-1;
	for( int j = 0 ; j < 5 ; j++ )
	{
		for( int i = 0 ; str[i] != '\0' ; i++ )
		{
			if( t[int(str[i])-int('0')][j] == "-")
			{
				cout<<" ";
				for( int g = 0 ; g < s ; g++ )cout<<'-';
				cout<<" ";
			}
			if( t[int(str[i])-int('0')][j] == " ")
			{
				cout<<" ";
				for( int g = 0 ; g < s ; g++ )cout<<" ";
				cout<<" ";
			}
			if( t[int(str[i])-int('0')][j] == " |")
			{
				cout<<" ";
				for( int g = 0 ; g < s ; g++ )cout<<" ";
				cout<<"|";
			}
			if( t[int(str[i])-int('0')][j] == "| ")
			{
				cout<<'|';
				for( int g = 0 ; g < s ; g++ )cout<<" ";
				cout<<" ";
			}
			if( t[int(str[i])-int('0')][j] == "| |")
			{
				cout<<'|';
				for( int g = 0 ; g < s ; g++ )cout<<" ";
				cout<<"|";
			}
			if( t[int(str[i])-int('0')][j] == "|")
			{
				cout<<" ";
				cout<<'|';
				for( int g = 0 ; g < s ; g++ )cout<<" ";
			}
		}
		cout<<'\n';
		if( j == 1 )
		{
			while( h != 0 )
			{
				j--;
				h--;
				break;
			}
		}
		if( j == 3 )
		{
			while ( h2 != 0 )
			{
				j--;
				h2--;
				break;
			}
		}
	}

}
