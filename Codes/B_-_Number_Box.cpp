#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    char mtx[n][n]; 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mtx[i][j]; 
        }
    }

    ll ans = 0; 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int di = -1; di <= 1; di++)
            {
                for(int dj = -1; dj <= 1; dj++)
                {
                    if(di != 0  or dj != 0)
                    {
                        ll num = 0; 
                        for(int k = 0; k < n; k++)
                        {
                            ll ni = ((i + di * k) % n + n ) % n ;
                            ll nj = ((j + dj * k) % n + n) % n; 
                            num = num * 10 + (mtx[ni][nj] - '0');  
                        }
                        ans = max(ans, num); 
                    }
                    
                }

            }
        }
    }

    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}