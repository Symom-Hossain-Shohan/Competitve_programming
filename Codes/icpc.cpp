#include<bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <ios>
using namespace std;

typedef long long ll;

void solve()
{
    double l, w; 
    while(1)
    {
    	cin >> l >> w; 
    	if(l==0 and w==0)  break;
    	double d  = (5.0*l)/8; 
    	double ans = 2*d + w - sqrt(d*d- (l-d)*(l-d));
    	cout << fixed;   
    	
    	cout << setprecision(4) << ans << endl; 
    }
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