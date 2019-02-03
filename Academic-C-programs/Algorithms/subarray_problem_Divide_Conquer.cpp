#include<bits/stdc++.h>
#define sd(mark) scanf("%d",&mark)
#define slld(mark) scanf("%lld",&mark)
#define ss(mark) scanf("%s",mark)
#define pd(mark) printf("%d",mark)
#define plld(mark) printf("%lld",mark)
#define pdd(mark1,mark2) printf("%d %d",mark1,mark2)
#define pn() printf("\n")
#define ps(mark) printf("%s",#mark)
#define debugd(val) printf("%s : %d\n",#val,val)
#define debuglld(val) printf("%s : %lld\n",#val,val)
#define ford(itr,start,end) for(int itr=start;itr<end;itr++)
#define fsd(mark) fscanf(in,"%d",&mark)
#define fslld(mark) fscanf(in,"%lld",&mark)
using namespace std;
typedef long long ll;
FILE *in = fopen("new","r");

ll cross(vector<ll> a,ll low,ll mid,ll high)
{
    ll left_sum=LONG_MIN;
    ll sum=0;
    ll right_sum=LONG_MIN;
    for(ll i=mid;i>=low;i--)
    {
        sum+=a[i];
        if(sum>left_sum)
            left_sum=sum;
    }
    sum=0;
    for(ll i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if(right_sum<sum)
            right_sum=sum;
    }
    return left_sum+right_sum;
}
ll subarray(vector<ll> a,ll low, ll high)
{
    if(low==high)
        return a[low];
    ll mid=(low+high)/2;
    return max(max(subarray(a,low,mid),subarray(a,mid+1,high)),cross(a,low,mid,high));
}

int main()
{
    ll n;
    slld(n);
	vector<ll> a(n);
   
    ford(i,0,n)
        slld(a[i]);
        
    cout <<  subarray(a,0,n-1) << endl;
    
    return 0;
}

