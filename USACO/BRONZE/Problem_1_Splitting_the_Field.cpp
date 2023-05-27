#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(vector<pair<ll,ll>> &vp)
{
    ll n = vp.size();
    vector<ll> fminx(n), fminy(n), fmaxx(n), fmaxy(n);
    fminx[0] = vp[0].first; 
    fminy[0] = vp[0].second; 
    fmaxx[0] = vp[0].first; 
    fmaxy[0] = vp[0].second; 

    for(int i = 1;i<n;i++) 
    {
        fminx[i] = min(fminx[i-1], vp[i].first);
        fminy[i] = min(fminy[i-1], vp[i].second);
        fmaxx[i] = max(fmaxx[i-1], vp[i].first);
        fmaxy[i] = max(fmaxy[i-1], vp[i].second);
    }

    vector<ll> bminx(n), bminy(n), bmaxx(n), bmaxy(n);
    bminx[n-1] = vp[n-1].first; 
    bminy[n-1] = vp[n-1].second; 
    bmaxx[n-1] = vp[n-1].first; 
    bmaxy[n-1] = vp[n-1].second;
    for(int i=n-2;i>=0; i--)
    {
        bminx[i] = min(bminx[i+1], vp[i].first);
        bminy[i] = min(bminy[i+1], vp[i].second);
        bmaxx[i] = max(bmaxx[i+1], vp[i].first);
        bmaxy[i] = max(bmaxy[i+1], vp[i].second);
    }

    ll ret = 1e18; 
    for(int i=0;i<n-1; i++)
    {
        
        ll area = (fmaxx[i]-fminx[i])*(fmaxy[i]-fminy[i]) + (bmaxx[i+1]-bminx[i+1])*(bmaxy[i+1]-bminy[i+1]); 
        ret = min(ret, area);
        
    }
    return ret; 
}

vector<pair<ll,ll>> sp(vector<pair<ll,ll>> vp)
{
    for(auto i: vp) swap(i.first, i.second);
    return vp; 
}

void solve()
{
    ll n; 
    cin >> n; 
    vector<pair<ll,ll>> vp(n);
    for(auto &i: vp) 
    {
        cin >> i.first >> i.second; 
    }
    sort(vp.begin(), vp.end()); 
    ll minx = 1e18, miny = 1e18, maxx = 0, maxy = 0; 
    for(auto i: vp)
    {
        minx = min(minx, i.first);
        miny = min(miny, i.second);
        maxx = max(i.first, maxx);
        maxy = max(i.second, maxy);
    } 

    ll ans = (maxx-minx) * (maxy-miny);
    //cout << ans << endl; 
    ll res = ans - fun(vp);
    for(int i = 0;i<n;i++) swap(vp[i].first, vp[i].second); 
    res = max(res, ans - fun(vp)); 
    cout << res << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}