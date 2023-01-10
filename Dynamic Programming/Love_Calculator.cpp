//https://lightoj.com/problem/love-calculator
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string a, b; 

ll length[31][31], way[31][31]; 


ll dp(ll i, ll j)
{
    if(i==0) 
    {
        way[i][j] = 1; 
        return j;
    } 
    else if(j==0) 
    {
        way[i][j] = 1; 
        return i; 
    }

    ll &ans = length[i][j]; 
    if(ans==-1)
    {
        if(a[i-1]==b[j-1])
        {
            ans = dp(i-1, j-1) +1; 
            way[i][j] = way[i-1][j-1];
        }
        else 
        {
            ll x = dp(i-1, j) + 1; 
            ll y = dp(i, j-1) + 1; 

            ans = min(x, y);
            if(x<y)
            {
                way[i][j] = way[i-1][j];
            }
            else if(x>y)
            {
                way[i][j] = way[i][j-1];
            }
            else 
            {
                way[i][j] = way[i-1][j] + way[i][j-1];
            }
        }

    }

    return ans; 

}

void solve()
{
    cin >> a >> b; 
    memset(length, -1, sizeof(length)); 
    memset(way, -1, sizeof(way)); 

    cout << dp(a.size(), b.size()) << ' ' << way[a.size()][b.size()] << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}