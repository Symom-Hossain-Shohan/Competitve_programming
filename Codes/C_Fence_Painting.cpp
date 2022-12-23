#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//defines...
#define ll           long long
#define boost        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb           push_back
#define mp           make_pair
#define in           insert
#define pi           2*acos(0.0)
#define srt(s)       sort(s.begin(),s.end())
#define rsrt(s)      sort(s.rbegin(),s.rend())
#define all(x)       x.begin(),x.end()
#define mem(a, b)    memset(a, b, sizeof(a))
#define c_test       printf("Case %lld: ",t)

const ll mod=1e9+7;
const ll MX=2e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}


typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {x = 1;y = 0;return a;}
    ll x1, y1, d = ext_gcd(b, a % b, x1, y1);
    x = y1;y = x1 - y1 * (a / b);
    return d;
}

//code goes from here...
vector<ll> v[100005];

void solve()
{
    ll n,m;
    cin >> n >> m;
    for(ll i=1;i<=n;i++) v[i].clear();

    vector<ll> a(n),b(n),c(m),ans(m);

    for(auto &i: a) cin >> i;

    for(auto &i: b) cin >> i;
    for(auto &i: c) cin >> i;

    for(ll i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            v[b[i]].pb(i);
        }
    }

    ll last=-1;

    if(v[c[m-1]].size()>0)
    {
        last=v[c[m-1]].back();
        v[c[m-1]].pop_back();
    }

    if(last==-1)
    {
        for(ll i=0;i<n;i++)
        {
            if(a[i]==b[i] and b[i]==c[m-1])
            {
                last=i;
                break;
            }
        }
    }

    if(last==-1)
    {
        cout << "NO\n";
        return;
    }
    ans[m-1]=last;

    for(ll i=0;i<m-1;i++)
    {
        if(v[c[i]].size()>0)
        {
            ans[i]=v[c[i]].back();
            v[c[i]].pop_back();
        }
        else 
        {
            ans[i]=last;
        }
    }

    for(ll i=1;i<=n;i++) 
    {
        if(v[i].size()>0) 
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(auto i: ans) cout << i+1 << ' ';
    cout << endl;

}


int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    ll tc;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    
    //---------------------------------
    
    return 0;
}