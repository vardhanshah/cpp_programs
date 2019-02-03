#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void merge(vector<ll> &a,ll l,ll mid,ll h)
{
	vector<ll> temp;
	ll i=l;ll j=mid+1;
	while( i<mid+1 && j<=h )
	{
		
		if(a[i]>a[j])
			temp.push_back(a[j++]);
		else
			temp.push_back(a[i++]);
	}

	while(i<mid+1)
		temp.push_back(a[i++]);
	while(j<=h)
		temp.push_back(a[j++]);
		
	for(ll p = l;p<=h;p++)
		a[p]=temp[p-l];
}
void merge_sort(vector<ll> &a,ll l,ll h)
{
	if(l<h)
	{
		
		ll mid=(l+h)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}
int main()
{
	ll n=10000000;
	
	vector<ll> a(n);
	for( ll i=0;i<n;i++)
		a[i]=n-i;
	
	clock_t t;
	merge_sort(a,0,n-1);
	t = clock();
	
	 cout <<endl << "*****TOTAL TIME= "<< ((float)t/CLOCKS_PER_SEC);
	return 0;
}
