#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    string a = "", b = "";

    for (int i = 0; i < 2 * n - 2; i++)
    {
        string s;
        cin >> s;
        if (s.size() == n - 1)
        {
            if (a == "")
                a = s;
            else
                b = s;
        }
    }

    reverse(a.begin(), a.end()); 
    if(a==b) cout << "YES\n"; 
    else cout << "NO\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}