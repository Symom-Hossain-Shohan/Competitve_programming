#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MX=5e5+5;


inline void norm(ll &a) {a%=mod; (a<0) && (a+=mod) ;}                            //positive mod value
inline ll modAdd(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a+b)%mod;} //modular addition
inline ll modSub(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a-b)%mod;} //modular subtraction
inline ll modMul(ll a,ll b) {a%=mod, b%=mod; norm(a),norm(b); return (a*b)%mod;} //modular multiplication

inline ll bigMod(ll b,ll p)  {ll r=1; while(p) {if(p & 1LL) r=modMul(r,b) ;b=modMul(b,b) ; p>>=1LL ; } return r; }
inline ll modInverse(ll a) {return bigMod(a,mod-2); }
inline ll modDiv(ll a ,ll b) { return modMul(a,modInverse(b)) ;}

vector<ll> fact; 

void factorial()
{
    fact.push_back(1); 
    for(int i = 1;i<MX; i++) fact.push_back(modMul(i, fact[i-1])); 
}

void solve()
{
    ll n;
    cin >> n; 
    vector<ll> v(n);
    set<ll> st; 
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
        st.insert(v[i]); 
    }

    sort(v.begin(), v.end()); 
    for(int i = 0;i<n;i++)
    {
        if(i<v[i]) 
        {
            cout << 0 << endl; 
            return; 
        }
    } 
    ll ans = fact[st.size()]; 
    ll dummy = v[0], cnt = 0; 
    for(int i  =0;i<n;i++)
    {
        if(v[i]==dummy) cnt++; 
        else 
        {
            ans = modMul(ans, fact[cnt]); 
            dummy = v[i], cnt = 1; 
        }
    }
    ans = modMul(ans, fact[cnt]); 

    cout << ans << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    factorial();

    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}