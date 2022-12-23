#include<bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    vector<pair<ll, ll>> a, b; 
    for(int i = 0; i < n; i++)
    {
    	ll x; 
    	cin >> x; 
    	ll cnt = 1; 
    	while(x % m == 0)
    	{
    		cnt *= m; 
    		x /= m; 
    	}
    	if(a.empty()) a.push_back({x, cnt}); 
    	else 
    	{
    		if(a.back().first == x) a.back().second  += cnt; 
    		else a.push_back({x, cnt});
    	}
    }
    ll k; 
    cin >> k; 
    for(int i = 0; i < k; i++)
    {
    	ll x; 
    	cin >> x; 
    	ll cnt = 1; 
    	while(x % m == 0)
    	{
    		cnt *= m; 
    		x /= m; 
    	}

    	if(b.empty()) b.push_back({x, cnt}); 
    	else 
    	{
    		if(b.back().first == x) b.back().second += cnt; 
    		else b.push_back({x, cnt}); 
    	}
    }
    //for(auto i: a) cout << i.first << ' ' << i.second << endl; 
    //for(auto i: b) cout << i.first <<  ' ' << i.second << endl; 

    if(a == b) cout << "Yes\n"; 
    else cout << "No\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}