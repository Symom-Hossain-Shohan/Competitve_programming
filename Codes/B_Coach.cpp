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

//code goes from here...
vector<int> adj[50];
int vis[50];
int mark[50];
int tick[50];

void dfs(int s)
{
    vis[s]=1;
    for(auto child: adj[s])
    {
        if(!vis[child]) dfs(child);
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
    int n,m;
    cin >> n >> m;
    if(m==0)
    {
        for(int i=1;i<=n;i+=3)
        {
            cout << i << ' ' << i+1 << ' ' << i+2  << endl;
        }
        return 0;
    }

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v ;
        adj[u].pb(v);
        adj[v].pb(u);
        tick[u]=1;
        tick[v]=1;
    }

    vector<pair<int,pair<int,int>>> v;

    for(int i=1;i<=n;i++)
    {
        if(mark[i]==0 )
        {
            mem(vis,0);
            vector<int> tm;
            dfs(i);
            for(int j=1;j<=n;j++) if(vis[j]==1) tm.pb(j);

            if(tm.size()>3) return cout << -1 << endl,0;
            else if(tm.size()==3)
            {
                mark[tm[0]]=mark[tm[1]]=mark[tm[2]]=1;
                v.pb({tm[0],{tm[1],tm[2]}});
            }
            else if(tm.size()==2)
            {
                int x=-1;
                for(int j=1;j<=n;j++)
                {
                    if(tick[j]==0) 
                    {
                        x=j;
                        break;
                    }
                }
                if(x==-1)return cout << -1 << endl,0;
                else 
                {
                    mark[tm[0]]=mark[tm[1]]=mark[x]=1;
                    tick[x]=1;
                    v.pb({tm[0],{tm[1],x}});
                }
            }
        }
    }
    vector<int> tm;
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==0)
        {
            mark[i]=1;
            tm.pb(i);
        }
        if(tm.size()==3)
        {
            v.pb({tm[0],{tm[1],tm[2]}});
            tm.clear();
        }
    }

    n/=3;
    for(int i=0;i<n;i++) cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << endl;
    
    //---------------------------------
    
    return 0;
}
