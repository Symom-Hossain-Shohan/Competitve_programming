#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n;
    vector<string> v(n);

    for(auto &i: v)
    {
        cin >> i; 
        reverse(i.begin(), i.end()); 
    }
    sort(v.begin(), v.end()); 
    for(int i=0;i<n;i++)
    {
        reverse(v[i].begin(), v[i].end()); 
        cout << v[i];
    }
    cout << endl; 
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