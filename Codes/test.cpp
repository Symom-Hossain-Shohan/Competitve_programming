#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    vector<int> v={1,2,3,4,5} ; 
    cout << upper_bound(v.begin(),v.end(),0) - v.begin() << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}