#include<iostream>
#include<vector>
using namespace std;


int BinarySearch(vector<int> &A,int target)
{
	int lo=0;
	int hi=A.size()-1;
	
	while(lo<=hi)
	{
		int mid=(lo+hi) >> 1;
		if(A[mid]==target)
			return mid;
		else if(A[mid]<target)
			lo=mid+1;
		else
			hi=mid-1;
	}
	return -1;
}
int BinarySearchAdvanced(vector<int> &A,int target)
{
	target-=0.01;
	int lo=0,hi=A.size();
	while(lo!=hi)
	{
		int mid=(lo+hi) >> 1;
		if(A[mid]<=target)
			lo=mid+1;
		else
			hi=mid;
	}
	return lo;
}

int main()
{
	int a[]={5,8,12,15,16,17,18};
	vector<int> A(a,a+7);
	cout << BinarySearch(A,15) << endl;
	cout << BinarySearchAdvanced(A,15) << endl;
}
