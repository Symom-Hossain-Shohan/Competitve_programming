#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 4e6 + 1; 
ll ans[N];

void solve()
{
    ll n; 
    cin >> n; 
    cout << ans[n] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    
    vector<ll> v[2001];
    v[1].push_back(1), v[2].push_back(2), v[2].push_back(3);
    ans[1] = 1, ans[2] = 5, ans[3] = 10; 
    ll k = 4; 
    for(int i=3;i<=2000; i++)
    {
        for(int j=0;j<i; j++)
        {
            v[i].push_back(k);
            if(j==0) ans[k] = ans[v[i-1][0]] + k*k; 
            else if(j==i-1) ans[k] = ans[v[i-1][j-1]] + k*k; 
            else ans[k] = ans[v[i-1][j-1]] + ans[v[i-1][j]] - ans[v[i-2][j-1]] + k*k; 
            k++; 
        }
    }

    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}