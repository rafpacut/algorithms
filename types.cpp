#define NDEBUG

#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

typedef int position;
typedef int digit;
typedef int number;

int sum;

// 1121231234
// ...101112
struct orig_seq
{
  number n; // ostatnia liczba w oryginalnym ciągu to 4, 12
  number suma; // suma cyfr do tej pory  
}n;

// 12345678910
struct monotonic_seq
{
  monotonic_seq(int n, int p) : n(n), p(p)  {}
  int n; // ostatnia liczba w ciagu (w przykladzie jest to 10
  int p;
};

int len(int n)
{
  int i = 1;
  while ( n >= 10 )
    {
      n /= 10;
      i++;
    }
  return i;
}

void test_len()
{
  assert(len(10) == 2);
  assert(len(5) == 1);
  assert(len(199) == 3);
}

monotonic_seq f( position p) // z oryginalnego ciagu tworzymy monotoniczny
{
  int dl = 1;
  number c1= 0,c2= 1;
  int i;
  while(0==0)
  {
    if( c1 <= p && p <= c2 )
      break;
    
    i = c2;    
    c2 += (c2 - c1) + 1;
    c1 = i;
     dl++;
   
  }
  p-=c1;//pozycja w monotonicznym ciagu
  cout <<"pozycja w monotonicznym ciagu: "<<p<<'\n';
  cout << "ostatnia liczba w monotonicznym ciagu: "<<c2-c1<<'\n';
  return monotonic_seq(c2-c1,p);
}

int number_longitude(int p)
{
  int i = 1;
  int sum = 9*pow(10,i-1);
  while(sum < p)
    {
      i++;
      sum += 9*pow(10,i-1);
    }
  //  p-= sum;
  p -= 9*pow(10,i-2);
  cout <<"dlugosc liczb wsrod ktorych znajduje sie argument: "<<i<<'\n';
  cout <<"pozycja wsrod liczb i-dlugich: "<<p<<'\n';
  return i;
}

void test_number_longitude()
{
  assert(number_longitude(10) == 2);
  assert(number_longitude(9) == 1);
  assert(number_longitude(99) == 2);
  assert(number_longitude(175) == 3);
  assert(number_longitude(8923) == 4);
}

int get_number(int p,int i)
{
  if(i == 1)
    return floor(p/i);
  else
    return floor(p/i) + pow(10,i-1);
}

void test_get_number()
{
  assert(get_number(8,2) == 14);
  assert(get_number(6,1) == 6);
  assert(get_number(2,3) == 100);
}


int read()
{
  int p;
  cin >> p;
  return p;
}

int main()
{
  test_number_longitude();
  test_get_number();
  test_len();

  
  int p = read();
  monotonic_seq ms = f(p);
  int i = number_longitude(ms.p);
  cout <<  get_number(ms.p,i)<<'\n';;
  
  return 0;
}
