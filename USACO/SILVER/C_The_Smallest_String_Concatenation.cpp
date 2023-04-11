#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(string a, string b)
{
    return a+b < b+a; 
}

void solve()
{
    ll n;
    cin >> n; 
    vector<string> v(n);
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end(), cmp); 
    for(auto i: v) cout << i ;  

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}