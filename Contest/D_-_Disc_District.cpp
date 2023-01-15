#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll r; 
    cin >> r; 
    ll ans = r*r + 1; 
    ll x = r, y = 1; 
    for(int i=1,j=r ;i<=r and j>0;)
    {
        if(i*i+j*j>r*r )
        {   
            if(i*i+j*j<ans)
            {
                ans = i*i+j*j; 
                x = i, y = j; 
            }
            j--; 
        }
        if(i*i+j*j<=r*r) i++; 

    }
    cout << x << ' ' << y << endl; 
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