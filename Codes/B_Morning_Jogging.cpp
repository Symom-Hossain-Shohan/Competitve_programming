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
        ll n,m;
        cin >> n >> m;
        int mtx[n][m];
        vector<int> d;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> mtx[i][j];
                d.pb(mtx[i][j]);
            }
        }
        srt(d);
        int tm[n][m];
        mem(tm,0);
        for(int i=0;i<m;i++)
        {
            bool ok=false;
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    if(mtx[j][k]==d[i] and tm[j][k]==0)
                    {
                        tm[j][i]=1;
                        swap(mtx[j][k],mtx[j][i]);
                        ok=true;
                        break;
                    }
                }
                if(ok) break;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cout << mtx[i][j] << ' ';
            cout << endl;
        }
    }
    
    //---------------------------------
    
    return 0;
}
