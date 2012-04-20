#include <iostream>
#include <cmath>
using namespace std;

int x[4],y[4];
int dx[2],dy[2];
int l,k;
int tmin[2];
int tmax[2];
int odlk, odll;
int v1,v2;
const int plac = pow(10,5);
void porownaj_czasy()
{
	if( k*odlk > plac || l*odll > plac )
	{
		cout<<"NIE\n";
	}
        else if(tmin[1] <= tmax[0] && tmin[1] >= tmin[0])
        {
                cout <<"TAK\n";
        }
        else if( tmax[1] <= tmax[0] && tmax [1] >= tmin[1] )
        {
                cout <<"TAK\n";
        }
        else if ( tmin[1] <= tmin[0] && tmax[1] >= tmax[0] )
        {
                cout <<"TAK\n";
        }
        else
                cout <<"NIE\n";

}

void oblicz_czasy()
{
        odlk = sqrt( (dx[0]*dx[0])+( dy[0]*dy[0] ));        
        odll = sqrt(  ( dx[1]*dx[1] )+( dy[1]*dy[1]) );
        tmin[0] = (k*odlk )/ v1;
        tmin[1] = (l*odll)/v2;
        tmax[0] = ((k+1)*odlk)/v1;
        tmax[1] = ((l+1)*odll)/v2;
        porownaj_czasy();
}

void obl_l_k()
{
        l = (dx[0]*( y[0] - y[1] )) - ( dy[0]*( x[1] - x[0] ) ) / ((dx[0]*dy[1])- ( dx[1]*dy[0] ));
        k = ( dy[0]*( x[0]-x[1] )-( dx[1]*( y[1] - y[0] ) ) ) / (( dx[0]*dy[1] ) - ( dx[1]*dy[0] ));
}


void obl_dx_dy()
{
        dx[0] = x[1] - x[0];
        dx[1] = x[3] - x[2];
        dy[0] = y[1] - y[0];
        dy[1] = y[3] - y[2];
}


void read()
{
	for( int i = 0; i < 4; i++ )
	{
		cin >> x[i]
		    >> y[i];
		if( i == 1 )
		{
			cin >> v1;
		}
		if( i == 3 )
		{
			cin >> v2;
		}
		
	}
}

int main()
{
	int t;
	cin >> t;
	while ( t > 0 )
	{
        	read();
        	obl_dx_dy();
        	if ( dx[0]*dy[1] -dx[1]*dy[0] != 0 )
        	{
               	 	obl_l_k();
               	 	oblicz_czasy();
        	}
       	 	else
       	 	{
         	       cout <<"NIE\n";
        	}
        	t--;
        }
}
