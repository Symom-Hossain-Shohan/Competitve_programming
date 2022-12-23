#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n ;
    cin >> n ; 
    map<string, ll > mp ; 
    for(int i=0;i<n;i++)
    {
        string a ; 
        cin >> a ;
        mp[a]++ ; 
    }

    ll ans = 0 ; 
    for(auto i: mp )
    {
        for(auto j: mp)
        {
            if(i.first!=j.first)
            {
                if((i.first[0]==j.first[0] and i.first[1]!=j.first[1] ) or (i.first[0]!=j.first[0] and i.first[1]==j.first[1])) ans+=i.second*j.second , mp[i.first] = 0;
            }
        }
        
    }
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
