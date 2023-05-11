#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    ll l = 0, r = n - 1;
    while (a[l] == b[l])
        l++;
    while (a[r] == b[r])
        r--;
    if(l>=n) l--; 
    while (l > 0 and b[l - 1] <= b[l])
        l--;
    if(r<0) r++; 
    while (r < n - 1 and b[r + 1] >= b[r])
        r++;
    cout << l + 1 << ' ' << r + 1 << endl;
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