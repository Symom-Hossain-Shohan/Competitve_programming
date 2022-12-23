#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; 
    cin >> n; 
    vector<int> v(n); 
    for(auto &i: v) cin >> i; 
    sort(v.rbegin(), v.rend()); 
    for(auto i: v) cout << i << ' '; 
    cout << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}