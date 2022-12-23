#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//defines...
#define ll           long long
#define boost        ios_base::sync_with_stdio(false);cin.tie(NULL);


const ll mod=998244353;
const ll MX=2e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}


int main()
{


    boost
    //---------------------------------
    ll n;
    cin >> n;
    ll t=10;
    ll ans=0;
    while(t<=n and t<=100000000000000000)
    {
        ll y=(t-t/10)%mod;
        
        ans=modAdd(ans%mod,modMul(modMul(y%mod,(y+1)%mod)%mod,modInverse(2%mod)%mod)%mod)%mod;
        t*=10;
    }
    t/=10;
    ll y=(n-t+1)%mod;
    

    ans=modAdd(ans%mod,modMul(modMul(y%mod,(y+1)%mod)%mod,modInverse(2%mod)%mod)%mod)%mod;
    cout << ans%mod << endl;
    
    //---------------------------------
    
    return 0;
}