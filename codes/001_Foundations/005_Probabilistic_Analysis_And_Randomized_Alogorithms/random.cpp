/*************************************************************************
    > File Name: random.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-12-04 15:35:08
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
double random(double start,double end)
{
    return start+(end-start)*rand()/(RAND_MAX+1.0);
}
int main()
{
    srand(unsigned(time(0)));
    for (int i = 0 ; i < 10 ; i++)
        cout<<"No:"<<i+1<<":"<<int(random(0,10))<<endl;
    return 0;
}

