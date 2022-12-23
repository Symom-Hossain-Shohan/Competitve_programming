#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
const ll INF_MUL = 1e13;
const ll INF_ADD = 1e18;
#define pb push_back
#define mp make_pair
#define nline "\n"
#define f first
#define s second
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<nline;
#else
#define debug(x);
#endif
void _print(ll x) {cerr << x;}
void _print(char x) {cerr << x;}
void _print(string x) {cerr << x;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template<class T>void _print(vector<T> v) {cerr << " [ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(set<T> v) {cerr << " [ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T>void _print(multiset<T> v) {cerr << " [ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V>void _print(map<T, V> v) {cerr << " [ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_pset;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const ll MOD = 1e9 + 7;
const ll MAX = 1000100;

ll overflow(ll l, ll r) {
    if (l > (2 * INF_ADD / r))
        return 1;
    if (l * r > INF_ADD) {
        return 1;
    }
    return 0;
}

ll sqr(ll x) {
    ll y = sqrt(x);
    y += 5;
    while (1) {
        if (y * y <= x) {
            return y;
        }
        y--;
    }
}

vector<pair<ll, ll>> getv(ll x) {
    map<ll, ll> visited, cost;
    queue<ll> track; track.push(x);
    visited[x] = 1, cost[x] = 0;
    while (!track.empty()) {
        auto it = track.front();
        track.pop();
        if (!overflow(it, it)) {
            ll y = it * it;
            if (!visited[y]) {
                visited[y] = 1;
                cost[y] = cost[it] + 1;
                track.push(y);
            }
        }
        ll z = sqr(it);
        if (!visited[z]) {
            visited[z] = 1;
            cost[z] = cost[it] + 1;
            track.push(z);
        }
    }
    vector<pair<ll, ll>> anot;
    for (auto it : cost) {
        anot.push_back(it);
    }
    return anot;
}

void solve() {
    ll n; cin >> n;
    map<ll, ll> dp;
    dp[0] = 0;
    for (ll i = 1; i <= n; i++) {
        ll x; cin >> x;
        vector<pair<ll, ll>> v = getv(x);
        map<ll, ll> adp, visited;
        sort(all(v));
        reverse(all(v));
        for (auto it : dp) {
            for (auto j : v) {
                if (j.f < it.f) {
                    break;
                }
                if (visited[j.f] == 0) {
                    adp[j.f] = j.s + it.s;
                }
                visited[j.f] = 1;
                adp[j.f] = min(adp[j.f], j.s + it.s);
            }
        }
        swap(dp, adp);
    }
    ll ans = INF_ADD;
    for (auto it : dp) {
        ans = min(ans, it.s);
    }
    cout << ans << nline;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif
    ll test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    cout << fixed << setprecision(10);
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}