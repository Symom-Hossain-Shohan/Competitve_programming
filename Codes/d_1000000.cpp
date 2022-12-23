#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll tc;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        ll n;
        cin >> n; 
        vector<ll> v(n);
        for(auto &i: v) cin >> i;
        
        ll ans=0;
        sort(v.begin(),v.end());
        ll k=1;
        for(int i=0;i<n;i++)
        {
            if(v[i]>=k) ans++,k++;
        }

        cout << "Case #" << t<< ": " << ans << endl;
    }
    return 0;
}