/*************************************************************************
    > File Name: Select_Sort.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-30 13:49:40
 ************************************************************************/

#include<iostream>
using namespace std;
void Swap(int& x,int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
void SelectSort(int p[],int size)
{
    for (int i = 0 ; i < size-1 ; i++)
    {
        int min = i;
        for (int j = i ; j < size ; j++)
            if (p[j] < p[min])
                min = j;
        Swap(p[i],p[min]);
    }
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
    int a[] = {10,4,32,2,8,19,20,44,67,89};
    SelectSort(a,10);
    Show(a,10);
    return 0;
}

