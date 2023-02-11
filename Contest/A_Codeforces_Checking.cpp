#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    char a; 
    string s = "codeforces";
    cin >> a; 
    if(count(s.begin(), s.end(), a)) cout << "YES\n";
    else cout << "NO\n";
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