/*************************************************************************
    > File Name: The_Maximum_Subarray_Problem.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-30 14:46:43
 ************************************************************************/

#include<iostream>
using namespace std;
//normal O(n^2)
void SumOfMaximumSubarray(int p[],int size)
{
    int max = p[0];
    for (int i = 0 ; i < size ; i++)
    {
        int tmp = p[i];
        for (int j = i+1 ; j < size ; j++)
        {
            tmp += p[j];
            if (tmp > max)
                max = tmp;
        }
    }
    cout<<"The sum of MaximumSubarray is "<<max<<endl;
}

//Devide and Conquer O(nlgn)
int Max(int a,int b,int c)
{
    if (a < b)
        a = b;
    if (a < c)
        return c;
    else
        return a;
}
int SumOfMaximumSubarray_DevideAndConquer(int p[],int start,int end)
{
    if (start == end)
        return p[end];
    else if (start > end)
        return -65535;
    int mid = (start+end) / 2;
    int MaxIncludeMid = p[mid];
    int MaxIncludeMidLeft = p[mid];
    int MaxIncludeMidRight = p[mid];
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = mid; i >= start ; i--)
    {
        tmp1 += p[i];
        if (tmp1 > MaxIncludeMidLeft)
            MaxIncludeMidLeft = tmp1;
    }
    for (int j = mid ; j <= end ; j++)
    {
        tmp2 += p[j];
        if (tmp2 > MaxIncludeMidRight)
            MaxIncludeMidRight = tmp2;
    }
    MaxIncludeMid = MaxIncludeMidLeft + MaxIncludeMidRight - p[mid];
    return Max(MaxIncludeMid,SumOfMaximumSubarray_DevideAndConquer(p,start,mid-1),SumOfMaximumSubarray_DevideAndConquer(p,mid+1,end));
}
void SumOfMaximumSubarray_DevideAndConquer(int p[],int size)
{
    int max = SumOfMaximumSubarray_DevideAndConquer(p,0,size-1);
    cout<<"The sum of MaximumSubarray is "<<max<<endl;
}

//Dynamic Programming O(n)
void SumOfMaximumSubarray_DynamicProgramming(int p[],int size)
{
    int max = p[0];
    int tmp = p[0];
    for (int i = 1 ; i < size ; i++)
    {
        tmp += p[i];
        if (tmp > max)
            max = tmp;
        else if (tmp < 0)
            tmp = 0;
    }
    cout<<"The sum of MaximumSubarray is "<<max<<endl;
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
    int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    Show(a,15);
    SumOfMaximumSubarray(a,15);
    SumOfMaximumSubarray_DevideAndConquer(a,15);
    SumOfMaximumSubarray_DynamicProgramming(a,15);
    int b[] = {-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
    Show(b,12);
    SumOfMaximumSubarray(b,12);
    SumOfMaximumSubarray_DevideAndConquer(b,12);
    SumOfMaximumSubarray_DynamicProgramming(b,12);
    return 0;
}
