#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<double> v, p; 
ll n, a, b; 

map<ll, ll> mp; 

ll dp(ll pos, ll sum)
{
    if(pos==n) 
    {
        if(sum==0) return 1; 
        else return 0; 
    }

    
}

void solve()
{
    cin >> n >> a >> b; 
    v.resize(n); 
    for(auto &i: v) cin >> i;
    p = v;  
    sort(v.rbegin(), v.rend()); 
    for(int i = 1;i<n;i++) v[i]+= v[i-1]; 
    double x = 0; 
    ll sum = 0; 
     
    for(int i =a-1;i<b;i++)
    {
        if(v[i]/(i+1)>x) 
        {
            x = (v[i])/(i+1); 
            sum = v[i]; 
        }
    }

    cout << x << endl; 
    cout << dp(0, sum) << endl;  

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