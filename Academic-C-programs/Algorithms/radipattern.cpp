#include <bits/stdc++.h>
using namespace std;
#define ford(i,s,e) for(int i=s;i<e;i++)
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define sz(a) int(a.size())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define rall(c) c.rbegin(),c.rend()
#define vpresent(c,elt) (find(all(c),elt)!=c.end())
#define present(c,elt) (c.find(elt) != c.end())
#define optimize ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define debug(i) cout << "here at position " <<  i;
#define traceone(x) cout << x << endl;
#define tracetwo(x,y) cout << x << " " << y << endl;
#define tracethree(x,y,z) cout << x << " " << y << " " << z << endl;
#define tracefour(x,y,z,w) cout << x << " " << y << " " << z << " " << w << endl;
#define TT() cout << float(clock())/CLOCKS_PER_SEC
#define mod(x) x%=1000000007;
#define time_taken cout << float(clock())/CLOCKS_PER_SEC << endl
typedef int64_t ll;

typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
template <typename T> 
string to_string(T a)
{
    ostringstream os;
    os << a;
    return os.str();
}
template <typename T> inline bool fmax(T a,T b){return (a>b) ? 1 : 0;}
template <typename T> inline bool fmin(T a,T b){return (a<b) ? 1 : 0;}
const int N=10;
int d[]={-1,0,1};
int a[N][N];
int vis[N][N];

bool check(int i,int j)
{
    return (i>=0&&i<N&&j>=0&&j<N) ? 1 : 0;
}

int main()
{
    int n,m;
    cin >> n >> m;n--;m--;
    a[n][m]=0;
    queue<pii> q;
    q.push(mp(n,m));
    vis[n][m]=1;
    while(!q.empty())
    {
        int i=q.front().fi;
        int j=q.front().se;
        ford(k,0,3)
        {
            int x=i+d[k];
            ford(l,0,3)
            {
                int y=j+d[l];
                if(check(x,y)&&!vis[x][y])
                {
                    a[x][y]=a[i][j]+1;
                    vis[x][y]=1;
                    q.push(mp(x,y));
                }
            }
        }
        q.pop();
    }
    ford(i,0,N)
    { 
        ford(j,0,N)
            cout << a[i][j]; 
        cout << endl;
   }
    return 0;
}
