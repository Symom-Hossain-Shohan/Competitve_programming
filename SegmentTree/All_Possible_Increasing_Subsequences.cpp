#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 5, mod = 1e9 + 7;

ll ar[N];
ll tree[4 * N + 5];

ll query(ll s, ll e, ll l, ll r, ll index)
{
    if (e < l or s > r)
        return 0;
    if (s >= l and e <= r)
        return tree[index];

    ll mid = (s + e) / 2;

    ll left = query(s, mid, l, r, 2 * index);
    ll right = query(mid + 1, e, l, r, 2 * index + 1);

    return tree[index] = (left + right) % mod;
}

void update(ll s, ll e, ll i, ll val, ll index)
{
    if(i>e or i<s) return; 
    if(s==e and s==i)
    {
        tree[index] =(tree[index] + val)%mod; 
        return; 
    }

    ll mid = (s+e)/2; 
    update(s, mid, i, val, 2*index); 
    update(mid+1, e, i, val, 2*index+1); 

    tree[index] = (tree[2*index] + tree[2*index+1])%mod; 

    return; 
}

bool cmp(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first==b.first) return a.second>b.second; 
    else return a.first<b.first; 
}

void solve()
{
    ll n;
    cin >> n;
    memset(tree, 0, sizeof(tree));
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end(), cmp);
    //for(auto i: v) cout << i.first << ' ' << i.second << endl; 

    for (int i = 0; i < n; i++)
    {
        ll pos = v[i].second;
        ll val = query(0, n - 1, 0, pos, 1) + 1;

        update(0, n-1, pos, val, 1);
    }
    cout << tree[1] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t
             << ": ";
        solve();
    }
    return 0;
}