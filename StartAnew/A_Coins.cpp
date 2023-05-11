#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b; 
    cin >> a >> b; 
    if(a%2== b%2)
    {
        cout << "YES\n"; 
    }
    else 
    {
        b*= 2; 
        if(a%2==0)
        {
            cout << "YES\n";
        }
        else if(a%2==b%2 and a>=b)
        {
            cout << "YES\n"; 
        }
        else cout << "NO\n"; 
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