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

void print()
{
	for( int j = 0 ; j < 5 ; j++ )
	{
		for( int i = 0 ; str[i] != '\0' ; i++ )
		{
			for( int u = 0 ; u < s ; u++ )
				cout <<t[int(str[i])-int('0')][j];
		}
	}	
}

int main()
{
	read();
//	print();
for( int u = 0 ; str[u] != '\0' ; u++ ){
	for( int i = 0 ; i < 5 ; i++ )
	{
			if( t[int(str[u])-int('0')][i] == "-" )
			{
				cout <<" ";
				for( int u = 0 ; u < s ; u++ ) cout <<"-";
				cout <<" \n";
			}
			else
			{
				if( t[int(str[u])-int('0')][i] == " |" )
				{
					for( int u = 0 ; u < s ; u++ ) 
					{
							for( int g = 0; g < s; g++ )
							{
								cout <<" ";
							}
							cout <<" |\n";
					}
				}
				else
				{
					if( t[int(str[u])-int('0')][i] == "| " )
					{
						for( int u = 0 ; u < s ; u++ ) 
						{
							cout <<"| ";
							for( int g = 0; g < s; g++ )
							{
								cout <<" ";
							}
							cout <<'\n';
						}
					}
					else
					{
						if( t[int(str[u])-int('0')][i] == "| |" )
						{
							for( int u = 0 ; u < s ; u++ )
							{
								cout<<'|';
								for( int g = 0 ; g < s ; g++ )
								{
									cout <<" ";
								}
								cout<<"|\n";	
								if( u == (s/2) )
								{
									
								}
							}
						}
						else
						{
							if( t[int(str[u])-int('0')][i] == "|" )
							{
								cout << " \n"; 
								for( int u = 0 ; u < s ; u++ ) cout <<" | \n";
							}
						}

					}
				}

			}
			}}

}
