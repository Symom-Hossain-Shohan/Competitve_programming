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
ll x,y,x2,y2;
ll area=0;

void func(ll a,ll b,ll c,ll d)
{
    if(a>=x and c<=x2 and b>=y and d<=y2)
    {
        area-=(c-a)*(d-b);
    }
    else if(a<=x and c>=x2 and b<=y and d>=y and d<y2)
    {
        area-=(x2-x)*(d-y);
    }
    else if(a<=x and c>=x2 and b<=y2 and b>y and d>=y2)
    {
        area-=(x2-x)*(y2-b);
    }
    else if(b<=y and d>=y2 and  a<=x and c>=x and c<x2)
    {
        area-=(y2-y)*(c-x);
    }
    else if(b<=y and d>=y2 and a<=x2 and a>x and c>=x2)
    {
        area-=(y2-y)*(x2-a);
    }
    else if(a<=x and c<x2 and c>=x and b<=y and d>=y and d<y2)
    {
        area-=(c-x)*(d-y);
    }
    else if(a>x and a<=x2 and c>=x2 and b<=y and  d>=y and d<y2)
    {
        area-=(x2-a)*(d-y);
    }
    else if(a<=x and c>=x and c<x2 and b<=y2 and b>y and d>=y2)
    {
        area-=(c-x)*(y2-b);
    }
    else if(a>x and a<=x2 and c>=x2 and b<=y2 and b>y and d>=y2)
    {
        area-=(x2-a)*(y2-b);
    }
    else area=0;
}

int main()
{
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    
    //freopen("output.txt", "w", stdout);
//#endif

    boost
    //---------------------------------
    cin >> x >> y >> x2 >> y2;
    ll x3,y3,x4,y4;
    cin >> x3 >> y3 >> x4 >> y4;
    ll x5,y5,x6,y6;
    cin >> x5 >> y5 >> x6 >> y6 ;

    area=(x2-x)*(y2-y);
    func( x3,y3,x4,y4);
    func(x5,y5,x6,y6);
    if(area>0) cout << "YES\n";
    else cout << "NO\n";
    
    //---------------------------------
    
    return 0;
}