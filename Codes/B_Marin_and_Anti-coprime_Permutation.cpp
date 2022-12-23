#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=998244353;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n;
        cin >> n;
        if(n%2==1) cout << 0 << endl;
        else 
        {
            ll ans=1;
            for(int i=n/2;i>=1;i--)
            {
                ans=(ans*i)%mod;
                ans=(ans*i)%mod;
            }
            cout << ans%mod << endl;
        }
    }
    return 0;
}