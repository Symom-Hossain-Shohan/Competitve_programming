#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;
const ll MX=5001;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

ll ncr[MX][MX], fact[MX];

ll dp(ll n, ll r)
{
    if(n<r) return 0; 
    if(r==1) return n;
    if(r==0 or r==n) return 1; 
    ll &ans = ncr[n][r];

    if(ans ==-1)
    {
        ans = modAdd(dp(n-1, r), dp(n-1, r-1));
    }

    return ans;  
}


ll fun(ll a, ll b)
{
    ll res = 0; 
    for(int i=0;i<=min(a, b); i++)
    {
        res = modAdd(res, modMul(modMul(dp(a, i), dp(b, i)), fact[i])); 
    }

    return res; 
}

void solve()
{
    ll a, b , c; 
    cin >> a >> b >> c; 
    memset(ncr, -1, sizeof(ncr));

    fact[0] = 1; 
    for(int i = 1;i<MX;i++) fact[i] = modMul(i, fact[i-1]); 

    ll ans = 1; 
    ans = modMul(ans,fun(a, b)); 
    ans = modMul(ans, fun(b, c)); 
    ans = modMul(ans, fun(c, a));

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