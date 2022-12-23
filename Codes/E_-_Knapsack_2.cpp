#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, w; 
vector<ll> vaule, weight; 

ll res[101][100005]; 

ll dp(ll pos, ll val)
{
    if(pos==n) 
    {
        if(val == 0) return 0; 
        else return 1e18; 
    } 
    if(res[pos][val]!=-1) return res[pos][val]; 

    if(vaule[pos]<=val)
    {
        return res[pos][val] = min(weight[pos]+ dp(pos+1, val - vaule[pos]), dp(pos+1, val)); 
    }
    else return res[pos][val] = dp(pos+1, val) ; 
}

void solve()
{
    cin >> n >> w; 
    vaule.resize(n); 
    weight.resize(n); 

    ll max_val = 0 ; 
    for(int i=0;i<n;i++)
    {
        cin >> weight[i] >> vaule[i]; 
        max_val += vaule[i]; 
    }
    memset(res, -1, sizeof res); 

    for(int i = max_val; i>=0; i--)
    {
        if(dp(0, i)<=w)
        {
            cout << i << endl; 
            break;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}