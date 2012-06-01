#include<iostream>
#include <cassert>
#include <cmath>
using namespace std;

int position;


void read()
{
  cin >> position;
}

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

int mon(int p)
{
  int dl = 2;
  int c1 = 0;
  int c2 = 1;
  int i;
  while(0 == 0)
  {
    if( c1 <= p && p <= c2)
        break;
    i = c2;
    c2 += (c2 - c1) + len(dl);
    c1 = i;
    dl++;
  }
  position -= c1; // position in monotonic sequence
  return c2-c1;// number of digits in -||-
}

void test_mon()
{
  assert(mon(10) == 4);
  assert(mon(4) == 3);
  assert(mon(44)== 9);
  assert(mon(45)==9);
  assert(mon(55)==11);
}

int get_length(int p)
{
  int m = 1;
  int digit_nr = 1;
  int length = 0;
    while (length < position)
      {
        length = length + 9 * m * digit_nr;
        digit_nr++;
        m = 10 * m;
      }
  return digit_nr-1;
}

int get_number(int length)
{
  position -= pow(10,length-1)-1;
  cout <<"position: "<<position<<'\n';
  cout <<position/length<<" number"<<'\n';
  cout <<"and the number is: "<< (position/length) + pow(10,length-1)-1<<'\n';
}

int main()
{
  test_mon();
  int last_digit;
  int length;
  read();
  cout <<"position before monotonic seq: "<< position<<'\n';
  last_digit = mon(position);
  cout <<"position in monotonic seq: "<<position<<'\n';
  length = get_length(position);
  cout <<length<<'\n';
  get_number(length); 
  
}
