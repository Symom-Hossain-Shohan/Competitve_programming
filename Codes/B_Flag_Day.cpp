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
//code goes from here...



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
    vector<int> v(n+1);
    vector<int > el;
    int mtx[m][3];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> mtx[i][j];
            el.pb(mtx[i][j]);
        }
    }

    int ar[4];
    for(int i=0;i<m;i++)
    {
        mem(ar,0);
        ar[v[mtx[i][0]]]++;
        ar[v[mtx[i][1]]]++;
        ar[v[mtx[i][2]]]++;
        //cout << ar[0] << ' ' << ar[1] << ' ' << ar[2] << ' ' << ar[3] << endl;
        for(int j=1;j<4;j++)
        {
            if(ar[j]==0)
            {
                ar[j]++;
                if(v[mtx[i][0]]==0) v[mtx[i][0]]=j;
                else if(v[mtx[i][1]]==0) v[mtx[i][1]]=j;
                else if(v[mtx[i][2]]==0) v[mtx[i][2]]=j;
            }
        }
    }

    for(int i=1;i<=n;i++) if(v[i]!=0) cout << v[i] << ' ';

    cout << endl;
    
    //---------------------------------
    
    return 0;
}
