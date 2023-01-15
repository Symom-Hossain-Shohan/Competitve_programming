#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve()
{
    ll n, y; 
    cin >> n >> y;  
    int x = 0; 
    for(int i = 0;i<n;i++)
    {
        ll a; 
        cin >> a; 
        x|=a; 
    }
     
    ll ans = 0, p = 1; 
    while(y)
    {
        if(x%2!=y%2)
        {
            if(x%2==0 and y%2==1) 
            {
                ans += p; 
            }
            else 
            {
                cout << -1 << endl; 
                return; 

            }
        }
        y/=2, x/=2; 
        p*=2; 
    }
    if(x) {
        cout << -1 << endl; 
        return; 
    }
    cout << ans << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}