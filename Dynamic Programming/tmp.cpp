#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
using namespace std;
const ll N = 200 + 9;
const ll inf = 1e9 + 7;
const ll Log2 = 20;
typedef pair<ll,ll> LL;

/// Enjoy coding ^^

ll n,k,a[N],dp[N][10],lim;

/*
    consider f(pos,pick) = smallest value if we are in pos and we have opened pick door
    then we can iterate over all start point
    just a straight forward dp, idk why it's hard on usaco
    code run under 30ms
*/
ll f(ll pos,ll pick){
    if (pos == lim) return 0;
    if (dp[pos][pick] != -1) return dp[pos][pick];
    ll ans = inf,cur = 0;
    for (ll i = pos + 1;i < lim;i++){
        cur += (i - pos) * a[i];
        if (pick < k) ans = min(ans,cur + f(i + 1,pick + 1));
    }
    ans = min(ans,cur + f(lim,pick));
    return dp[pos][pick] = ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    #define task "cbarn2"
    if (fopen(task".in", "r")){
        freopen(task".in", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin>>n>>k;
    for (ll i = 1;i <= n;i++) cin>>a[i];
    for (ll i = n + 1;i <= 2*n;i++) a[i] = a[i - n];
    ll ans = inf;
    for (ll i = 1;i <= n;i++){
        memset(dp,-1,sizeof(dp)); lim = i + n;
        ans = min(ans,f(i,1));
    }
    cout<<ans;
}