#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n; 
    ll ans = 0;  
    for(int i=0;i<n;i++)
    {
    	string s; 
    	ll cost; 
    	cin >> s >> cost; 
    	unordered_map<char, ll> mp; 
    	bool ok = true;  
    	for(int j=0;j<(int)s.size();j++)
    	{
    		mp[s[j]]++; 
    		if(mp[s[j]]>1)
    		{
    			ok = false;
    			break;
    		}
    	}
    	if(ok) ans += cost;
    }
    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}