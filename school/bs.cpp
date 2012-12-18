//Rafal Pacut
// To jest caly program, razem z konwersjami itp, glownie chodzi o funkcje sum() gdzie jest dodawanie liczb
//dla dodatnich dziala, dla ujemnych dobrze konwertuje ale wyniku dodawania nie chce mi sie sprawdzac ; ]
#include <iostream>
#include <string>
using namespace std;


string bin1;// do wczytania pierwszej liczby binarnej
string bin2;// do wczytanie drugiej liczby binarnej

int b1[8];//int'owa reprezentacja binarnej liczby
int b2[8];// - || -


void read()
{
	cin >> bin1;
	cin>> bin2;
}

void print()
{
	cout<<"bin1: "<<bin1<<" bin2: "<<bin2<<endl;
}

void convert_to_int()
{
	for( int i = 0 ; i < 8 ; i++ )
	{
		b1[i] = int(bin1[i])-48;
		b2[i] = int(bin2[i])-48;
	}
}

void print_int()
{
	cout<<"b1: "<<endl;
	for( int i = 0 ; i < 8 ; i++ )
	{
		cout<<b1[i]<<" ";
	}
	cout<<"\nb2: "<<endl;
	for( int i = 0 ; i < 8 ; i++ )
	{
		cout<<b2[i]<<" ";
	}
	cout<<endl;
}

void sum()// dodawanie liczb
{
	int przejscie = 0;
	for( int i = 7 ; i >= 1 ; i-- )
	{
		b1[i] += przejscie + b2[i];
		if( b1[i] >= 2 )
		{
			przejscie  = 1;
			b1[i] -= 2;
			
		}
		else
		{
			przejscie = 0;
		}
//		cout<<"b1: "<<b1[i]<<" przejscie: "<<przejscie<<" b2: "<<b2[i]<<endl;
		cout<<i<<" "<<b1[i]<<endl;
	}
}

void algorithm()
{
	bool neg1 = false;// czy pierwszy jest ujemny?
	bool neg2 = false;//czy 2gi jest ujemny?
	if( b1[0] )
		neg1 = true;
	if( b2[0] )
		neg2 = true;
	if( neg1 && neg2 )//jezeli oba ujemne
	{
		cout<<"oba ujemne\n";
		sum();
	}
	if( neg1 && ! neg2 )// itd 
	{
		cout<<"1: ujemny, 2: dodatni\n";
		bool change = false;//konwersja na U2-------------
		for( int i = 7 ; i >= 0 ; i-- )
		{
			if( change )
			{
				if( b1[i] == 1 )
					b1[i] = 0;
				else
					b1[i] = 1;
			}
			if( b1[i] == 1 )
				change = true;
		}
		cout<<"po konwersji na U2: \n";//------------------
		print_int();
		sum();
	}
	if( !neg1 && neg2 )//itd
	{
		cout<<"1:dodatni, 2:ujemny\n";
		bool change = false;//konwersja na U2--------------
		for( int i = 7 ; i >= 0 ; i-- )
		{
			if( change )
			{
				if( b2[i] == 1 )
					b2[i] = 0;
				else
					b2[i] = 1;
			}
			if( b2[i] == 1 )
				change = true;			
		}//-----------------------
		cout<<"po konwersji na U2: \n";
		print_int();		
		sum();
	}
	if( !neg1 && !neg2 )
	{
		cout<<"oba dodatnie\n";
		sum();
	}
}

int main()
{
	read();
	print();
	convert_to_int();
	print_int();
	algorithm();
	for( int i = 0 ; i < 8 ; i++ )
	{
		cout<<b1[i];
	}
	cout<<endl;
}
