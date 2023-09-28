#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC optimize("no-stack-protector")
// #define ll __int128
#define ll long long
// #define ll int
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
// #define mod 998244353 
#define mp make_pair
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define ff first
#define ss second
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define pf printf
#define sz(a) (int)(a.size())
#define psf push_front
#define ppf pop_front
#define ppb pop_back
#define pb push_back
#define pq priority_queue
#define all(s) s.begin(),s.end()
#define sp(a) setprecision(a)
#define rz resize
#define ld long double
#define inf (ll)1e15
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define eb emplace_back
const double pi = acos(-1);
ll binpow(ll a, ll b){ll res=1;while(b!=0){if(b&1)res*=a;a*=a;b>>=1;}return res;}
// ll binpow(ll a, ll b, ll md){ll res=1;a%=mod;while(b!=0){if(b&1)res*=a,res%=md;a*=a,a%=md;b>>=1;}return res%md;}
 
using namespace std;

ll h,g,dp[1001][1001][2];
vector<vector<pair<ll,ll> > > v;

ll dist(pair<ll,ll> &a, pair<ll,ll> &b)
{
    return (abs(a.ff-b.ff)*abs(a.ff-b.ff)+abs(a.ss-b.ss)*abs(a.ss-b.ss));
}

ll fn(ll i, ll j, ll k)
{
    if(i>h || j>g)
        return inf;
    if(i==h && j==g)
    {
        if(k)
            return inf;
        return 0;
    }
    ll &ans=dp[i][j][k];
    if(ans==-1)
    {
        ans=inf;
        pair<ll,ll> cur;
        if(k)
            cur=v[1][j];
        else
            cur=v[0][i];
        ans=min({ans,dist(cur,v[0][i+1])+fn(i+1,j,0),dist(cur,v[1][j+1])+fn(i,j+1,1)});
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    int z=1;
    // cin>>z;
    f(i,1,z+1)
    {
        //cout<<"Case #"<<i<<": ";
        memset(dp,-1,sizeof(dp));
        cin>>h>>g;
        v.rz(2);
        v[0].rz(h+2),v[1].rz(g+2);
        f(i,1,h+1)
            cin>>v[0][i].ff>>v[0][i].ss;
        f(i,1,g+1)
            cin>>v[1][i].ff>>v[1][i].ss;
        cout<<fn(1,0,0)<<"\n";
    }
} 