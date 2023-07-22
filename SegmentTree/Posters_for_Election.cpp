#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 
ll tree[4*N+1];
ll prop[4*N+1]; 

void update(ll s, ll e, ll l, ll r, ll index)
{
    if(prop[index])
    {
        tree[index] = (e-s+1); 
        if(s!=e)
        {
            prop[2*index]++; 
            prop[2*index+1]++; 
        }
        prop[index] = 0; 
    }

    if(e<l or s>r) return; 
    if(s>=l and e<=r)
    {
        tree[index] = (e-s+1); 
        if(s!=e)
        {
            prop[2*index]++; 
            prop[2*index+1]++; 
        }
        return; 
    }

    ll mid = (s+e)/2; 
    update(s, mid, l, r, 2*index); 
    update(mid+1, e, l, r, 2*index+1); 

    tree[index] = tree[2*index] + tree[2*index+1]; 
    return; 
}


ll query(ll s, ll e, ll l, ll r, ll index)
{
    if(prop[index])
    {
        tree[index] = (e-s+1); 
        if(s!=e)
        {
            prop[2*index]++; 
            prop[2*index+1]++; 
        }
    }

    if(e<l or s>r) return 0; 
    if(s>=l and e<=r) return tree[index]; 

    ll mid = (s+e)/2; 

    ll left = query(s, mid, l, r, 2*index); 
    ll right = query(mid+1, e, l, r, 2*index+1); 

    return left + right; 
}


void solve()
{
    memset(tree, 0, sizeof(tree)); 
    memset(prop, 0, sizeof(prop)); 
    ll n; 
    cin >> n; 
    vector<pair<ll,ll>> vp(n);
    ll ans = 0; 
    ll mx = 0; 
    for(auto &i: vp) 
    {
        cin >> i.first >> i.second; 
        mx = max({mx, i.first, i.second}); 
    }
    //cout << mx << endl; 

    for(int i=n-1;i>=0; i--)
    {
        ll l = vp[i].first, r = vp[i].second; 
        ll x = query(1, mx, l, r, 1);
        if(x<(r-l+1)) ans++; 

        update(1, mx, l, r, 1); 
    }

    cout << ans << "\n";
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}