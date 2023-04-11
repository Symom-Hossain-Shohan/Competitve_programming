#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    int mtx[n][n]; 

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin >> mtx[i][j]; 
    }

    for(int i=0, ii=n-1;i<n;i++, ii--)
    {
        for(int j=0, jj=n-1;j<n;j++, jj--)
        {
            if(mtx[i][j]!=mtx[ii][jj])
            {
                mtx[i][j] = mtx[ii][jj]; 
                k--; 
            }
        }
    }
    //cout << k << endl; 

    if(k<0) cout << "NO\n"; 
    else 
    {
        if(k%2==0) cout << "YES\n"; 
        else 
        {
            if(n%2) cout << "YES\n"; 
            else cout << "NO\n"; 
        }
    }
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