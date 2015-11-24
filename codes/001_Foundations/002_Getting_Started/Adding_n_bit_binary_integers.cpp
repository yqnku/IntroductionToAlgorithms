/*************************************************************************
    > File Name: Adding_n_bit_binary_integers.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-24 10:00:02
 ************************************************************************/

#include<iostream>
using namespace std;
void Add(int p1[],int p2[],int p[],int size)
{
   int carry = 0;
   for (int i = size-1 ; i >= 0 ; i--)
   {
       int plus = p1[i]+p2[i]+carry;
       if (plus == 0)
       {
           p[i+1] = 0;
           carry = 0;
       }
       else if (plus == 1)
       {
           p[i+1] = 1;
           carry = 0;
       }
       else if (plus == 2)
       {
           p[i+1] = 0;
           carry = 1;
       }
       else 
       {
           p[i+1] = 1;
           carry = 1;
       }
   }
   p[0] = carry; 
}
void Show(int p[],int size)
{
    for (int i = 0 ; i < size ; i++)
        cout<<p[i];
    cout<<endl;
}
int main()
{
    int a[] = {1,0,1,0,0,1,0};
    int b[] = {0,1,1,0,0,1,0};
    int c[8];
    Add(a,b,c,7);
    Show(a,7);
    Show(b,7);
    Show(c,8);
    return 0;
}

