/*************************************************************************
    > File Name: Sum_X.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-30 14:04:38
 ************************************************************************/

//Ex2.3-7
#include<iostream>
using namespace std;
void Merge(int a[],int p,int q,int r)
{
    int *L = new int[q-p+2];
    int *R = new int[r-q+1];
    for (int i = 0 ; i < q-p+1 ; i++)
        L[i] = a[p+i];
    for (int j = 0 ; j < r-q ; j++)
        R[j] = a[q+1+j];
    L[q-p+1] = 65535;
    R[r-q] = 65535;
    int i = 0;
    int j = 0;
    for (int k = p ; k < r+1 ; k++)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}
void Sort(int a[],int p,int r)
{
    if (p < r)
    {
        int q = (p+r) / 2;
        Sort(a,p,q);
        Sort(a,q+1,r);
        Merge(a,p,q,r);
    }
}
void MergeSort(int a[],int size)
{
    Sort(a,0,size-1);
}
void Sum_X(int a[],int size,int x)
{
    MergeSort(a,size);
    int i = 0;
    int j = size-1;
    while (i < j)
    {
        if (a[i]+a[j] == x)
        {
            cout<<a[i]<<"+"<<a[j]<<"="<<x<<endl;
            return;
        }
        else if (a[i]+a[j] > x)
            j--;
        else
            i++;
    }
    cout<<"No two elements whose sum is exactly "<<x<<"!\n";
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
    int b[] = {10,4,32,29,8,19,11,44,67,89};
    Show(b,10);
    Sum_X(b,10,61);
    Sum_X(b,10,27);
    Sum_X(b,10,1);
    Sum_X(b,10,180);
    return 0;
}

