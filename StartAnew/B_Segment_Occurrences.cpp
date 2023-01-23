//https://codeforces.com/problemset/problem/1016/B
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m, q; 
    cin >> n >> m >> q; 
    string a, b; 
    cin >> a >> b ; 
    ll occurance[n+1];
    memset(occurance, 0, sizeof(occurance)); 

    for(int i=0;i<n;i++)
    {
        int j = 0; 
        for(;j<m;j++)
        {
            if(a[i+j]==b[j]) continue;
            else break;
        }
        if(j==m)
        {
            occurance[i+j-1]++; 
        }
    }

    for(int i=1;i<n;i++) occurance[i]+=occurance[i-1]; 
    //for(auto i: occurance) cout << i << ' '; 
    //cout << endl; 
    //cout << occurance[3] << 
    while(q--)
    {
        ll x, y; 
        cin >> x >> y; 
        x--, y--; 
        if(y-m+1<x)
        {
            cout << 0 << endl;continue;
        }
        else if(x+m-1>y)
        {
            cout << 0 << endl;continue;
        }
        else if(x+m-2<0)
        {
            cout << occurance[y] << endl; 
        }
        else
            cout << occurance[y] - occurance[x+m-2] << endl; 
    }
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