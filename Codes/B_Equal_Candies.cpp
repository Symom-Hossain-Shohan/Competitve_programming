#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n ;
    cin >> n; 
    vector<int> v(n) ; 
    int sum = 0 ; 
    for(auto &i: v) 
    {
        cin >> i ;
        sum += i ; 
    }
    sort(v.begin(),v.end()) ; 
    sum -= n*(v[0]) ; 
    cout << sum << endl; 
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