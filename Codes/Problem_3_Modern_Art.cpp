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

ll paint[10][10];
ll n;

bool color_appear(int col)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) 
        {
            if(paint[i][j]==col) return true;
        }

    }
    return false;
}


bool on_top_of(int col2,int col1)
{
    ll top=n,bottom=0,left=n,right=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(paint[i][j]==col2)
            {
                top=min(top,i);
                bottom=max(bottom,i);
                left=min(left,j);
                right=max(right,j);
            }
        }
    }

    for(ll i=top;i<=bottom;i++)
    {
        for(ll j=left;j<=right;j++)
        {
            if(paint[i][j]==col1) return true;
        }
    }
    return false;
}

int main()
{
//#ifndef ONLINE_JUDGE
    freopen("art.in", "r", stdin);
    
    freopen("art.out", "w", stdout);
//#endif

    boost
    //---------------------------------
    
    cin>> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c;
            cin >> c;
            paint[i][j]=c-'0';
        }
    }

    ll ans=0;
    for(int i=1;i<=9;i++)
    {
        if(color_appear(i))
        {
            bool can_be_first=true;
            for(int j=1;j<=9;j++)
            {
                if(i!=j and color_appear(j) and on_top_of(j,i))
                {
                    can_be_first=false;
                }
            }
            if(can_be_first) ans++;
        }
    }

    cout << ans << endl;
    
    //---------------------------------
    
    return 0;
}