#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    if(n == 3) cout << -1 << endl; 
    else 
    {
        cout << "3 4 2 1 "; 
        for(int i = 5; i <= n; i++) cout << i << ' '; 
        cout << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t = 1;t <= tc; t++)
    {
        solve();
    }
    return 0;
}