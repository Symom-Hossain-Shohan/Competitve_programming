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


void solve()
{
    string s; 
    cin >> s; 
    ll ans = 0; 
    int k, n = s.length();
    cin >> k; 
    ll cnt = 0; 
    for(int i =0;i<n;i++)
    {
        if(s[i]=='0' or s[i]=='5')
        {
            ll a = bigMod(2, cnt); 
            ll r = bigMod(2, n);
            ans  = modAdd(ans,modDiv( modMul(a, (bigMod(r, k)-1)), r-1));
        }
        cnt++; 
    }

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