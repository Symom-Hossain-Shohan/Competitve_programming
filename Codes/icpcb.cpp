#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b, c, k; 
    cin >> a >> b >> c >> k;  
    if((a+b+c)%3==0)
    {
    	ll avg = (a+b+c)/3;  
    	ll cnt = 0; 
    	bool ok = false;   
    	if(a>avg and (a-avg)%k==0)
    	{
    		cnt+=  (a-avg)/k;  
    		ok = true; 
    	}
    	else if(a<avg and (avg-a)%k==0)
    	{
    		cnt -= (avg-a)/k; 
    		ok = true; 
    	}
    	if(b>avg and (b-avg)%k==0)
    	{
    		cnt+=  (b-avg)/k;  
    		ok = true; 
    	}
    	else if(b<avg and (avg-b)%k==0)
    	{
    		cnt -= (avg-b)/k; 
    		ok = true; 
    	}
    	if(c>avg and (c-avg)%k==0)
    	{
    		cnt+=  (c-avg)/k;  
    		ok = true; 
    	}
    	else if(c<avg and (avg-c)%k==0)
    	{
    		cnt -= (avg-c)/k; 
    		ok = true; 
    	}
    	if(a==b and b==c) ok = true; 
    	if(cnt==0 and ok) cout << "Peaceful\n"; 
    	else cout << "Fight\n";   
    }
    else cout << "Fight\n";  
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        cout << "Case " << t << ": ";  
        solve();
    }
    return 0;
}