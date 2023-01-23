#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    char matrix[n+1][m+1];
    ll vertical[n+1][m+1]; 
    ll horizontal[n+1][m+1];
    memset(vertical, 0, sizeof(vertical)); 
    memset(horizontal, 0, sizeof(horizontal)); 
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cin >> matrix[i][j];
        }
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(matrix[i][j]=='.' and matrix[i][j-1]=='.') horizontal[i][j]++; 
        }
    }

    for(int j=1;j<=m;j++)
    {
        for(int i=2;i<=n;i++)
        {
            if(matrix[i][j]=='.' and matrix[i-1][j]=='.') vertical[i][j]++; 
        }
    }

    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            vertical[i][j] = vertical[i][j] + vertical[i-1][j] + vertical[i][j-1] - vertical[i-1][j-1]; 
            horizontal[i][j] = horizontal[i][j] + horizontal[i-1][j] + horizontal[i][j-1] - horizontal[i-1][j-1];
        }
    }

    ll q; 
    cin >> q; 
    while(q--)
    {
        ll x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2; 
        if(x1== x2 and y1 == y2) cout << 0 << endl; 
        else 
        {
            //for horizontal y1+= 1

            ll ans = 0; 
            y1+= 1; 
            if(y1<=y2)
            {
                ans += horizontal[x2][y2] - horizontal[x1-1][y2] - horizontal[x2][y1-1] + horizontal[x1-1][y1-1];
            }
            y1-=1; 
            //for vertical x1 += 1
            x1 += 1; 

            if(x1<=x2)
            {
                ans += vertical[x2][y2] - vertical[x1-1][y2] - vertical[x2][y1-1] + vertical[x1-1][y1-1];
            }
            cout << ans << endl; 
        }

        
    }

    
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