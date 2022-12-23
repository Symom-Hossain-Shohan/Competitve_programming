#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >>n ;
    vector<ll> a(n), b(n), c, d; 
    for(auto &i: a) cin >> i ;
    for(auto &i: b) cin >> i; 
    c= a; 
    d=b; 
    sort(c.begin(), c.end()); 
    sort(d.begin(), d.end()); 

    map<pair<ll,ll>,ll> ma, mb; 

    for(int i=0;i<n;i++)
    {
        ma[{a[i], b[i]}]++; 
        mb[{c[i], d[i]}]++;
    }
    
    vector<ll> pos(n, -1) ; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]==c[i] and b[j]==d[i] and pos[j]==-1) pos[j] = i; 
        }
    }

    if(ma != mb) 
    {
        cout << -1 << endl ;
        return ;
    }
    
    vector<pair<ll,ll>> ans; 
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(pos[j]>pos[j+1])
            {
                swap(pos[j], pos[j+1]); 
                ans.push_back({j+1, j+2}); 
            }
        }
    }

    cout << ans.size() << endl; 
    for(auto i: ans) cout << i.first << ' ' << i.second << endl; 
    //cerr << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";

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