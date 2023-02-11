#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// typedefs...
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

// constants...
const double PI = acos(-1);
const ll mod = 1000000007; // 998244353
const int MXS = 2e5+5;
const ll MXI = 1e9+5;
const ll MXL = 1e18+5;
const ll INF = 1e9+5;
const ll INFLL = 1e18+5;
const ll EPS = 1e-9;

// defines...
#define MP        make_pair
#define PB        push_back
#define fi         first
#define se         second
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define boost_      ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

// functions...
ll gcd(ll a, ll b){ while (b){ a %= b; swap(a, b);} return a;}
ll lcm(ll a, ll b){ return (a/gcd(a, b)*b);}
ll ncr(ll a, ll b){ ll x = max(a-b, b), ans=1; for(ll K=a, L=1; K>=x+1; K--, L++){ ans = ans * K; ans /= L;} return ans;}
ll bigmod(ll a,ll b,ll mod){ if(b==0){ return 1;} ll tm=bigmod(a,b/2,mod); tm=(tm*tm)%mod; if(b%2==1) tm=(tm*a)%mod; return tm;}
ll egcd(ll a,ll b,ll &x,ll &y){ if(a==0){ x=0; y=1; return b;} ll x1,y1; ll d=egcd(b%a,a,x1,y1); x=y1-(b/a)*x1; y=x1; return d;}
ll modpow(ll a,ll p,ll mod) {ll ans=1;while(p){if(p%2)ans=(ans*a)%mod;a=(a*a)%mod;p/=2;} return ans;}
ll inverse_mod(ll n,ll mod) {return modpow(n,mod-2,mod);}
//ll fact[2000005];
//ll ncr_mod(ll n,ll r) {return (((fact[n]*inverse_mod(fact[r]))%mod)*inverse_mod(fact[n-r]))%mod;}

ll n, a[200005], s;
ll dp[200005][2];
ll check(ll pos, ll pre, ll val) {
    if(pos == n - 1) {
      return val * a[n - 1];//val * last index of array
    }
    if(dp[pos][pre] != -1) return dp[pos][pre];
    
    ll mx;
    if(a[pos] <= s) {
        mx = a[pos];
    }
    else if(a[pos] <= 2 * s) {
        mx = s;
    }
    else {
        mx = a[pos] - s;
    }
    ll ans = check(pos + 1, 0, mx) + (a[pos] - mx) * val;
    ll ans1 = check(pos + 1, 1, a[pos] - mx) + mx * val;
    return dp[pos][pre] = min(ans, ans1);
}
void solve()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = -1;//memoization
    }
    cout << check(1, 0, a[0]) << endl;//dp call
}
int main()
{
    boost_;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
      // cout<<"Case "<<i<<": ";
       solve();
    }
}