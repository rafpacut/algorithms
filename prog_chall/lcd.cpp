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
				cout<<" "
				    <<" "
				    <<" ";
			}
			if( t[int(str[i])-int('0')][j] == " |")
			{
				cout<<" ";
				cout<<" ";
				cout<<"|";
			}
			if( t[int(str[i])-int('0')][j] == "| ")
			{
				cout<<'|';
				cout<<" ";
				cout<<" ";
			}
			if( t[int(str[i])-int('0')][j] == "| |")
			{
				cout<<'|';
				cout<<" ";
				cout<<'|';
			}
			if( t[int(str[i])-int('0')][j] == "|")
			{
				cout<<" ";
				cout<<'|';
				cout<<" ";
			}
		}
		cout<<'\n';
	}

}
