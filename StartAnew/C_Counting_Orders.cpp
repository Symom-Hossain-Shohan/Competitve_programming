#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod=1e9+7; 
ll n; 


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication


void solve()
{
    cin >> n; 
    vector<ll> a(n), b(n);
    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 

    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end()); 

    ll ans = 1, cnt = 0; 

    for(int i=n-1;i>=0; i--)
    {
        ll t = upper_bound(a.begin(), a.end(), b[i]) - a.begin(); 
        //cout << b[i] << ' ';
        ans = modMul(ans, (n-t-cnt)); 
        
        cnt++; 
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