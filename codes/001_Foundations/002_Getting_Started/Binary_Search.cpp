/*************************************************************************
    > File Name: Binary_Search.cpp
    > Author: yqnku
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-27 16:22:09
 ************************************************************************/

#include<iostream>
using namespace std;
//Ex 2.3-5
int BinarySearch(int p[],int start,int end,int elem)
{
    if (start >= end)
        return -1;
    int mid = (start+end) / 2;
    if (p[mid] == elem)
        return mid;
    else if (p[mid] > elem)
        return BinarySearch(p,start,mid,elem);
    else
        return BinarySearch(p,mid+1,end,elem);
}
int Binary_Search(int p[],int size,int elem)
{
    return BinarySearch(p,0,size-1,elem);
}
int main()
{
    int a[] = {2,4,6,8,10,12,14,16,18,20};
    cout<<"Search 10,index:"<<Binary_Search(a,10,10)<<endl;
    cout<<"Search 5,index:"<<Binary_Search(a,10,5)<<endl;
    return 0;
}

