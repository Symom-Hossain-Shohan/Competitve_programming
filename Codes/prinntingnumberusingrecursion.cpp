#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll fx[] = {0, 1, 0, -1};
const ll fy[] = {1, 0, -1, 0};

ll sum, n, m;
ll vis[25][25];
char s[25][25];

void dfs(ll x , ll y)
{
    ll i;
    vis[x][y] = 1;
    ll a, b;
    for (i = 0; i < 4; i++)
    {
	        a = x + fx[i];
	        b = y + fy[i];
	        if (s[a][b] == '.' and a >= 0 and b >= 0 and a < n and b < m and !vis[a][b])
	        {
	            sum++;
	            vis[a][b] = 1;
	            dfs(a, b);
	        }
    }

}

void solve()
{
    memset(vis, 0, sizeof vis);
    cin >> m >> n;
    ll i, j, x, y;
    sum = 1;  
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++) {
            cin >> s[i][j];
            if (s[i][j] == '@')
            {
                x = i;
                y = j;
            }
        }
    }
    dfs(x, y);
    cout << sum << endl;
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