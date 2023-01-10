#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin>>  n; 
    if(n%2)
    {
        if(n==3)
        {
            cout<< "NO\n"; 
        }
        else 
        {
            cout << "YES\n";
            ll x = 1, i = 5; 
            while(i<n)
            {
                x++, i+=2; 
            }
            n/=2; 
            while(n--)
            {
                cout << x << " -" << x+1 << ' '; 
            } 
            cout << x << endl; 
        }
    }
    else 
    {
        cout << "YES\n"; 
        n/=2; 
        while(n--)
        {
            cout << "1 -1 "; 
        }
        cout << endl; 
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