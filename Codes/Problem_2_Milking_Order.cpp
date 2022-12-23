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



int main()
{
//#ifndef ONLINE_JUDGE
    freopen("milkorder.in", "r", stdin);
    
    freopen("milkorder.out", "w", stdout);
//#endif

    boost
    //---------------------------------
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> pos(n+1,0),mark(n+1,0);
    vector<ll> h(m);
    bool ok=false;
    for(auto &i: h) 
    {
        cin >> i;
        if(i==1) ok=true;

    }
    while (k--)
    {
        ll u,v;
        cin >> u >> v;
        pos[v]=u;
        mark[u]=v;
    }
    if(mark[1]!=0) 
    {
        cout << mark[1] <<  endl;
    }
    else if(ok)
    {
        for(int i=0;i<m;i++)
        {
            if(mark[h[i]]==0)
            {
                if(i==0)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(pos[j]==0)
                        {
                            pos[j]=h[i];
                            mark[h[i]]=j;
                            break;
                        }
                    }
                }
                else 
                {
                    for(int j=mark[h[i-1]]+1;j<=n;j++)
                    {
                        if(pos[j]==0)
                        {
                            pos[j]=h[i];
                            mark[h[i]]=j;
                            break;
                        }
                    }
                }
            }
        }
        cout << mark[1] << endl;
    }
    else
    {
        for(int i=m-1;i>=0;i--)
        {
            if(mark[h[i]]==0)
            {
                if(i==m-1)
                {
                    for(int j=n;j>=1;j--)
                    {
                        if(pos[j]==0)
                        {
                            pos[j]=h[i];
                            mark[h[i]]=j;
                            break;
                        }
                    }
                }
                else 
                {
                    for(int j=mark[h[i+1]]-1;j>=1;j--)
                    {
                        if(pos[j]==0)
                        {
                            pos[j]=h[i];
                            mark[h[i]]=j;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(pos[i]==0)
            {
                cout << i << endl;
                break;
            }
        }

    }
    
    
    //---------------------------------
    
    return 0;
}