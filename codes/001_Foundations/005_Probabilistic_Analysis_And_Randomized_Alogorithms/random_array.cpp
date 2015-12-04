/*************************************************************************
    > File Name: random_array.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-12-04 15:31:41
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
double Random(double start,double end)
{
    return start+(end-start)*rand()/(RAND_MAX+1.0);
}
void Swap(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void Random_array(int p[],int size)
{
    for (int i = 0 ; i < size ; i++)
        Swap(p[i],p[int(Random(i,size))]);
}
void Show(int p[],int size)
{
    cout<<"-------------------------------------------------\n";
    for (int i = 0 ; i < size ; i++)
        cout<<p[i]<<"   ";
    cout<<endl;
    cout<<"-------------------------------------------------\n";
}
int main()
{
    srand(unsigned(time(0)));
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    Show(a,10);
    for (int i = 1 ; i < 10 ; i++)
    {
        Random_array(a,10);
        Show(a,10);
    }
    return 0;
}

