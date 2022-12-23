#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    string s; 
    cin >> s; 
    int pos[n+1]; 
    for(int i=0;i<n;i++)
    {
        ll x; 
        cin >> x; 
        pos[x] = i+1; 
    }

    ll res = 1;
    vector<bool>  visited(n+1, false);  
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue; 
        visited[i] = true; 
        string t = s; 
        ll cnt = 0; 
        while(cnt==0 or s!=t)
        {
            ll x = i; 
            string now = t; 
            do
            {
                now[pos[x]-1] = t[x-1]; 
                x = pos[x]; 
                visited[x] = true;
            } while (x!=i);
            cnt++; 
            t = now; 
        }
        res = (res*cnt)/__gcd(res, cnt); 
    }
    cout << res << endl; 
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}   