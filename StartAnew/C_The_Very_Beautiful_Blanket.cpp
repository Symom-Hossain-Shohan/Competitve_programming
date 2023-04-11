#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<ll>> mtx(280, vector<ll> (280)); 

void solve()
{
    ll n, m; 
    cin >> n >> m; 
    cout << n*m << endl; 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout <<mtx[i][j] << ' '; 
        }
        cout << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll now = 0; 
    for(int i = 0;i<256; i+=2)
        for(int j=0;j<256;j+=2)
        {
            mtx[i][j] = now; 
            mtx[i][j+1] = now+1; 
            mtx[i+1][j] = now + 2; 
            mtx[i+1][j+1] = now + 3; 
            now += 4; 
        }


    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}