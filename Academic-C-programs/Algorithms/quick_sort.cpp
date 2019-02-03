#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void swap(ll *a,ll *b)
{ll tmp=*a;*a=*b;*b=tmp;}

ll partition(vector<ll> &a,ll l,ll h)
{
	ll x = a[h];
	ll i = l-1;
	for(ll j = l;j<h;j++)
		if(a[j]<=x)
		{
			i++;
			ll tmp=a[j];
			a[j]=a[i];
			a[i]=tmp;
		}
	swap(a[++i],a[h]);
	return i;
}

void quick_sort(vector<ll> &a,ll l,ll h)
{
	if(l<h)
	{
		ll pivot = partition(a,l,h);
		quick_sort(a,l,pivot-1);
		quick_sort(a,pivot+1,h);
	}
}

int main()
{
	ll n=10;
	
	vector<ll> a(n);
	for( ll i=0;i<n;i++)
		a[i]=rand()%10;
	
	clock_t t;
	quick_sort(a,0,n-1);
	t = clock();
	for(ll i=0;i<n;i++)
		cout << a[i] << endl;
	 cout << endl << "*****TOTAL TIME= "<< ((float)t/CLOCKS_PER_SEC);
	return 0;
}
