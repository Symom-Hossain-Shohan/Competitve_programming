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
vector<ll> adj[200005];
vector<ll> cost[200005];

ll dist[200005];
ll parent[200005];

int n,m;

void bfs(int s)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();
        for(int i = 0 ; i < adj[u].size() ; i++ )
        {
            ll v=adj[u][i] ;
            if(dist[u]+cost[u][i]<dist[v])
            {
                dist[v]=dist[u]+cost[u][i];
                pq.push({dist[v],v});
                parent[v]=u;
            }
        }
    }
}

int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        ll u,v,c ;
        cin >> u >> v >> c; 
        adj[u].pb(v);
        adj[v].pb(u);
        cost[u].pb(c);
        cost[v].pb(c);
    }

    for(int i=1;i<=n;i++) dist[i]=1e11;

    bfs(1);
    parent[1]=1;

    vector<ll> path;
    path.pb(n);
    
    if(dist[n]==1e11) cout << -1 << endl;
    else 
    {
        //path.push_back(n);
        ll p=parent[n];
        while(n!=1)
        {
            path.push_back(p);
            if(p==1) break;
            p=parent[p];
        }
        reverse(all(path));
        for(auto i: path) cout << i << ' ';
        cout << endl;

    }

    
    //---------------------------------
    
    return 0;
}