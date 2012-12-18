/*
-wczytywanie,
	· ilosc kajakow,
	· wypornosci kajakow,
	· ilosc bagazy,
	· wagi bagazy,
-algorytm,
	· posortowac kajaki,
	· posortowac bagaze,
	· przeiterowac po bagazach ustawiajac kajaki,
-wypisanie,
	· wypisac ilosc kajakow,

-testy:
	· wczytywania,
		× wypisz kajaki i ich wagi, bagaze i ich wagi;
	· algorytmu,
		× wypisz po sortowaniu kajakow i bagazy
		× jakie bagaze do jakiego kajaka
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//wypisywanie
#define W(a)  // wczytywania
#define S(a)  //sortowania
#define A(a)  // algorytmu

vector<int> kajaki;
vector<int> bagaze;


void read()
{
	int n; cin >> n;//ilosc kajakow
	W( cout << "n: "<< n << endl; )
	kajaki.resize( n );
	for( int i = 0 ; i < n ; i++ )
	{
		int a; cin >> a;
		kajaki[i] = a;
		W(cout << "kajaki["<<i<<"]: "<< kajaki[i]<<endl;)
	}
	int m; cin >> m;// ilosc bagazy
	bagaze.resize( m );
	W( cout << "m: " << m << endl; )
	for( int i = 0 ; i < m ; i++ )
	{
		int a; cin >> a;
		bagaze[i] = a;
		W(cout << " bagaze["<<i<<"]: "<<bagaze[i]<<endl;)
	}
}

void sorting()
{
	sort( kajaki.begin(), kajaki.end() );
	sort( bagaze.begin(), bagaze.end() );
	S
	(
		cout <<"kajaki sorted: "<<endl;
		for( int i = 0 ; i < kajaki.size() ; i++ )
			cout<< kajaki[i]<<endl;
		cout<<"bagaze sorted: "<<endl;
		for( int i = 0 ; i < bagaze.size() ; i++ )
			cout<<bagaze[i]<<endl;
	)
}


int group()
{
	int current_kajak = kajaki.size()-1;
	int ilosc_kajakow = 0;
	for( int i = bagaze.size()-1 ; i >= 0 ; i-- )
	{
		if( bagaze[i] != -1 )
		{
			A
			(
				cout <<" kajak nr :"<<current_kajak<<" o wypornosci: "<<kajaki[current_kajak]<<" " ;
				cout << " bagaz o nr: "<<i<<" i wadze: "<<bagaze[i]<<endl;
			)
			int current_weight = bagaze[i];
			for( int j = i-1 ; j >= 0 ; j-- )
			{
				A
				(
					cout << " bagaz o nr: "<<j<<" o wadze: "<<bagaze[j]<<endl;
					cout << " i lacznej wadze:  "<<current_weight+bagaze[j]<<endl;
				)
				//jezeli jeszcze nie byl uzyty i miesci sie w wypornosci
				if( bagaze[j] != -1 && current_weight + bagaze[j] <= kajaki[current_kajak] )
				{
					A( cout << " spelnil wszystkie warunki "<< endl; )
					current_weight += bagaze[j];
					bagaze[j] = -1;
				}
			}
			current_weight = 0;
			current_kajak --;
			ilosc_kajakow ++;
		}
	}
	return ilosc_kajakow;
}

void compute()
{
	//a) posortuj
	//b) przeiteruj
	//c) wypisz wynik
	sorting();
	int answer = group();
	cout << answer<<'\n';
}

int main()
{
	read();
	compute();
}
