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

ll fun(string a, string b, char ch)
{
    bool ok=false;
    for(int i=0;i<(int)a.size();i++)
    {
        if(a[i]=='1' and b[i]==ch)
        {
            for(int j=0;j<i;j++) 
            {
                if(a[j]=='0') a[j]='1';
                else a[j]='0';
            }
            for(int j=i+1;j<(int)a.size();j++)
            {
                if(a[j]=='0') a[j]='1';
                else a[j]='0';
            }
            //cout << "YES\n";
            ok=true;
            break;
        }
        
    }
        ll c10=0,c01=0;
        for(int i=0;i<(int)a.size();i++) 
        {
            if(a[i]=='1' and b[i]=='0') c10++;
            if(a[i]=='0' and b[i]=='1') c01++;
        }

        if(c01==c10)
        {
            return c10+c01+ok;
        }
        else return 1e18;
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
        ll n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        
        if(a==b) cout << 0 << endl;
        else 
        {
            ll ans=1e18;
            ll c10=0,c01=0;
            for(int i=0;i<n;i++) 
            {
                if(a[i]=='1' and b[i]=='0') c10++;
                if(a[i]=='0' and b[i]=='1') c01++; 
            }
            if(c10==c01) ans=min(ans,c10+c01);
            ans=min(ans,fun(a,b,'1'));
            ans=min(ans,fun(a,b,'0'));
            //ll r1=fun(a,b,'1');
            //ll r2=fun(a,b,'0');
            //cout << r1 << endl << r2 << endl;
            if(ans>=1e18) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    
    //---------------------------------
    
    return 0;
}