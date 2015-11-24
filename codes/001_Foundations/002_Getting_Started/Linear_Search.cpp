/*************************************************************************
    > File Name: Linear_Search.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-24 09:51:10
 ************************************************************************/

#include<iostream>
using namespace std;
int Linear_Search(int p[],int size,int num)
{
    for (int i = 0 ; i < num ; i++)
    {
        if (p[i] == num)
            return i;
    }
    return -1;
}
int main()
{
    int a[] = {10,4,32,2,8,19,20,44,67,89};
    cout<<Linear_Search(a,10,20)<<endl;
    cout<<Linear_Search(a,10,1)<<endl;
    return 0;
}

