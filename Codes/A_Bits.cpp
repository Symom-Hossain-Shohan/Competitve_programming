#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll number_of_bits(ll x)
{
	ll cnt = 0;
	while(x)
	{
		cnt++;
		x = x>>1;
	}
	return cnt;
}

void solve()
{
    ll l, r; 
    cin >> l >> r; 
    ll a = number_of_bits(l), b = number_of_bits(r); 
    if(a<b)
    {
    	if(__builtin_popcountll(r) == b) cout << r << endl; 
    	else cout << (1ll<<(b-1))-1ll << endl; 
    }
    else 
    {
    	//cout << a << endl; 
    	//cout << l << endl; 
    	for(ll i = 0;i<a;i++)
    	{
    		ll x = l | (1ll<<i); 
    		if(x<=r) l = x; 
    		//cout << l << endl;  
    	}
    	cout << l << endl; 
    }
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