/*************************************************************************
    > File Name: Insertion_Sort.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-24 09:28:43
 ************************************************************************/

#include<iostream>
using namespace std;
void Insertion_Sort(int p[],int size,bool reversed = false)
{
    for (int j = 1 ; j < size ; j++)
    {
        int key = p[j];
        int i = j-1;
        if (reversed)
        {
            while ((i >= 0) && (p[i] > key))
            {
                p[i+1] = p[i];
                i--;
            }
        }
        else
        {
            while ((i >= 0) && (p[i] < key))
            {
                p[i+1] = p[i];
                i--;
            }
        }
        p[i+1] = key;
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
    int b[] = {10,4,32,2,8,19,20,44,67,89};
    Show(a,10);
    Insertion_Sort(a,10,false);
    Insertion_Sort(b,10,true);
    Show(a,10);
    Show(b,10);
    return 0;
}
