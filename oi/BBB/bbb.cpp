/*
	- ustalic sposob zmiany w przypadku roznych bilansow : chwilowego i właściwego,
	- przy wczytywaniu liczyc bilans chwilowy,
	- zamienic,
*/
#include <iostream>
using namespace std;

#define p(a) a;

int n;
int p;
int q;
int x;
int y;
int bilans_tmp;
int delayed_operatons = 0;
int po_number = 0;
int zz_number = 0;

void read()
{
	cin >> n >> p >> q >> x >> y;
}

void change_balance( int difference, bool negative, bool delay_operation )
{
	if( delay_operation )
	{
		p(cout<<"difference: "<<difference<<endl;)
		while( difference )
		{
			p(cout<<"rotfl"<<endl;)
			if( po_number > 0 )
				po_number --;
			zz_number ++;
			difference--;
		}
	}
	else
	{
		if( (2*x < y) && !negative )
		{
			while( difference )
			{
				zz_number ++;
				difference --;
			}
		}
		else
		{
			if( negative )
			{
				while( difference )
				{
					zz_number --;
					po_number ++;
					difference --;
				}
			}
			else
			{
				while( difference )
				{
					if( po_number > 0 )
						po_number --;
					zz_number ++;
					difference--;
				}	
			}
		}
	}
}

void keep_above_zero( bool delay_operation )
{
	if( delay_operation )
	{
		delayed_operatons ++;
		po_number ++;
		p(cout<<"przeniosłem!"<<endl;)
	}
	else
	{
		bilans_tmp++;
		zz_number ++;
		p(cout<<"zmieniłem!"<<endl;)
	}
}

int compute_time()
{
	return (y*po_number) + (x*zz_number);
}
void algorithm()
{
	//ustalenie sposobu zmiany w przypadku roznych bilansow ( 'po' na 'zz' ) lub roznie
	bool delay_operation = ( x > y )? true : false;
	p(cout<<"delay_operation: "<<(( delay_operation )?"true":"false")<<endl;)
	
	bilans_tmp = p;
	for( int i = 0 ; i < n ; i++ )
	{
		char a;
		cin >> a;
		p(cout<<a<<endl;)
		if( a == '-' )
		{
			if( (bilans_tmp -1 ) < 0)
			{
				// zmiana (warunek pierwszy - chwilowy stan konta nie moze byc mniejszy od zera)
				keep_above_zero(delay_operation);
			}
			else
			{
				bilans_tmp--;
			}
		}
		else
		{
			bilans_tmp ++;
		}
		p(cout<<"bilans_tmp: "<<bilans_tmp<<" zz_number: "<<zz_number<<" po_number "<<po_number<<endl;)
	}
	//(warunek drugi - ostateczny bilans musi rownac sie właściwemu)
	int difference = q - bilans_tmp - delayed_operatons;
	bool negative = false;
	if( difference < 0 )
	{
		negative = true;
		difference *= -1;
	}
	p(cout<<"negative: "<<(( negative )?"true":"false")<<endl;)
	change_balance( difference, negative, delay_operation );
	cout << compute_time()<<'\n';
}


int main()
{
	ios_base::sync_with_stdio(0);
	read();
	p(cout <<"n: "<<n<<" p: "<<p<<" q: "<<q<<" x: "<<x<<" y: "<<y<<endl;)
	algorithm();
	return 1;
}
