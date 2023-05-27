#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;

inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    map<ll,ll> mp; 
    for(int i=0;i<n; i++)
    {
        ll x; 
        cin >> x; 
        mp[x]++; 
    }

    vector<ll> v; 
    for(auto i: mp) v.push_back(i.first);
     
    ll ans = 0, temp = 1; 
    for(int i=0;i<min(m-1, (ll)v.size()); i++)
    {
        temp = modMul(temp, mp[v[i]]); 
    }
    
    for(int i=0, j=m-1; j<(int)v.size(); j++, i++)
    {
        temp = modMul(temp, mp[v[j]]);
        if(v[j]-v[i]<m) ans = modAdd(ans, temp); 
        temp  = modDiv(temp, mp[v[i]]); 
    }

    cout << ans << endl; 
     
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}