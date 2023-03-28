#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    vector<vector<ll>> v(n, vector<ll> (n)); 

    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> v[i][j];  
    }

    ll sum = 0; 
    for(int j=0;j<n;j++)
    {
        ll val = 0, val2 = 0; 
        for(int i=0;i<n;i++)
        {
            if(i%2==0) val += v[i][j];
            else val2+=v[i][j];  
        }
        sum += max(val, val2);
    }
    ll sum2 = 0; 
    for(int i = 0;i<n;i++)
    {
        ll val = 0, val2 = 0; 
        for(int j=0;j<n;j++)
        {
            if(j%2==0) val+= v[i][j];
            else val2 += v[i][j]; 
        }
        sum2 += max(val, val2); 

    }



    cout << max(sum, sum2) << endl; 
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