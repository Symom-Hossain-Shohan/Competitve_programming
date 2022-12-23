#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i ;
    vector<int> s; 
    for(int i=0;i<n;i++) if(v[i]!=i) s.push_back(v[i]); 
    ll ans = s[0] ; 
    for(int i=1;i<(int)s.size();i++) ans = ans & s[i];
    cout << ans << endl; 

     
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