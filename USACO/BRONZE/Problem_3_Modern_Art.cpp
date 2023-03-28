#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<vector<ll>> v(n, vector<ll> (n)); 
    set<ll> st; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c; 
            cin >> c; 
            v[i][j] = c -'0'; 
            st.insert(v[i][j]); 
        }
    }

    map<ll,ll> mp; 
    for(auto x: st)
    {
        if(x==0) continue;
        int lx = n+1, rx = -1, ly = n+1, ry = -1; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==x)
                {
                    lx = min(lx, i);
                    rx = max(rx, i);
                    ly = min(ly, j);
                    ry = max(ry, j);
                }
            }
        }

        for(int i=lx;i<=rx;i++)
        {
            for(int j=ly;j<=ry;j++)
            {
                if(v[i][j]!=x) mp[v[i][j]] = 1; 
            }
        }
        
    }

    ll cnt  = 0; 
    for(auto i: st) 
    {
        if(i==0) continue;
        else if(mp[i]==0) cnt++; 
    }
    cout << cnt << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}