#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n); 
    for(auto &i: v) cin >> i; 

    if(v[n-1]) cout << "NO\n";
    else 
    {
        cout << "YES\n";
        //reverse(v.begin(), v.end()); 
        for(int i = n-1; i>=0; )
        {
            if(v[i]==0) cout << 0 << ' ',  i--; 
            else 
            {
                ll a = 0; 
                while(i>=0 and v[i]==1)
                {
                    a++; 
                    i--; 
                }
                for(int j=1;j<a; j++)
                {
                    cout << 0 << ' ';
                }
                cout << a << ' ';
            }
        }
        cout << "\n";

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