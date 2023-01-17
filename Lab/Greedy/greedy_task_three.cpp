#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; 
    cin >> n; 
    ll profit[n], deadline[n];
    ll mx = -1; 
    for(int i=0;i<n;i++)
    {
        cin >> profit[i] >> deadline[i];

        mx = max(mx, deadline[i]); 
    }

    vector<pair<ll,ll>> vp; 
    for(int i =0;i<n;i++)
    {
        vp.push_back({profit[i], deadline[i]}); 
    }

    sort(vp.begin(), vp.end());

    int visited[mx+1]; 
    memset(visited, 0, sizeof(visited)); 
    ll cnt = 0; 
    for(int i=n-1;i>=0;i--)
    {
        for(int j=vp[i].second;j>0;j--)
        {
            if(visited[j]==0)
            {
                visited[j] = 1; 
                cnt+= vp[i].first; 
                break;
            }
        }
    }
    //for(int i=0;i<3;i++) cout << visited[i] << ' ';

    cout << cnt << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}