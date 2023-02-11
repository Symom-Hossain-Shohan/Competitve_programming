#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=2e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

ll a, b, n; 

bool is_good(ll x)
{
    while(x)
    {
        if(!(x%10 == a or x%10 ==b)) return false; 
        x/=10; 
    }
    return true; 
}

void solve()
{
     
    cin >> a >> b >> n; 
    ll fact[n+1];
    fact[0]  = 1; 
    for(int i = 1;i<=n;i++) fact[i] = modMul(i, fact[i-1]); 
    vector<pair<ll,ll>> vp; 
    for(int i=0;i<=n;i++)
    {
        ll x = i*a + (n-i)*b; 
        if(is_good(x)) vp.push_back({i, n-i}); 
    }

    ll ans = 0; 
    for(auto i: vp)
    {
        ll x = modMul(fact[i.first], fact[i.second]); 
        ans += modDiv(fact[n], x); 
    } 
    norm(ans);
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}