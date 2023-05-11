#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    if(n==1)
    {
        cout << 1 << endl; 
    }
    else 
    {
        if(n%2) cout << -1 << endl; 
        else 
        {
            for(int i = 0; i<n; i++)
            {
                if(i%2) cout << i << ' '; 
                else cout << n-i << ' ';
            }
            cout << "\n";
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