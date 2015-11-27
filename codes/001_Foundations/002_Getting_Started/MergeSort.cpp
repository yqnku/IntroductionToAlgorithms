/*************************************************************************
    > File Name: MergeSort.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-27 09:19:38
 ************************************************************************/

#include<iostream>
using namespace std;
void Merge1(int a[],int p,int q,int r)
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
void Sort1(int a[],int p,int r)
{
    if (p < r)
    {
        int q = (p+r) / 2;
        Sort1(a,p,q);
        Sort1(a,q+1,r);
        Merge1(a,p,q,r);
    }
}
void MergeSort1(int a[],int size)
{
    Sort1(a,0,size-1);
}


//Ex 2.
void Merge2(int a[],int p,int q,int r)
{
    int *L = new int[q-p+1];
    int *R = new int[r-q];
    for (int i = 0 ; i < q-p+1 ; i++)
        L[i] = a[p+i];
    for (int j = 0 ; j < r-q ; j++)
        R[j] = a[q+1+j];
    int i = 0;
    int j = 0;
    for (int k = p ; k < r+1 ; k++)
    {
        if (i == q-p+1)
        {
            a[k] = R[j];
            j++;
        }
        else if (j == r-q)
        {
            a[k] = L[i];
            i++;
        }
        else if (L[i] < R[j])
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
void Sort2(int a[],int p,int r)
{
    if (p < r)
    {
        int q = (p+r) / 2;
        Sort2(a,p,q);
        Sort2(a,q+1,r);
        Merge2(a,p,q,r);
    }
}
void MergeSort2(int a[],int size)
{
    Sort2(a,0,size-1);
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
    int b[] = {10,4,32,2,8,19,20,44,67,89};
    Show(b,10);
    MergeSort1(b,10);
    Show(b,10);
    int c[] = {10,4,32,2,8,19,20,44,67,89};
    Show(c,10);
    MergeSort2(c,10);
    Show(c,10);
    return 0;
}
