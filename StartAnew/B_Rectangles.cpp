#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll r, c; 
    cin >> r >> c; 
    int mtx[r][c];

    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> mtx[i][j]; 
    ll ans = 0; 
    for(int i = 0;i<r;i++)
    {
        int one = 0, zero = 0; 
        for(int j=0;j<c;j++)
        {
            mtx[i][j] == 1 ? one++ : zero++; 
        }

        ans += (ll) pow(2, one) - 1 + (ll) pow(2, zero) - 1; 
    }

    for(int j=0;j<c;j++)
    {
        int one = 0, zero = 0;
        for(int i=0;i<r;i++)
        {
            mtx[i][j] == 1 ? one++ : zero++; 
        }
        ans += (ll) pow(2, one) - 1 + (ll) pow(2, zero) - 1 - r; 

    }

    cout << ans << endl; 
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