/*************************************************************************
    > File Name: Bubble_Sort.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-30 13:39:57
 ************************************************************************/

#include<iostream>
using namespace std;
void Swap(int& x,int& y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
void BubbleSort(int p[],int size)
{
    for (int i = 0 ; i < size-1 ; i++)
        for (int j = size-1 ; j > i ; j--)
            if (p[j] < p[j-1])
                Swap(p[j],p[j-1]);
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
    BubbleSort(a,10);
    Show(a,10);
    return 0;
}

