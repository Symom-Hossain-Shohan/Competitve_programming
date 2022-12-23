#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll l,r;
        cin >> l >> r;
        vector<ll> v((r-l)+1);
        for(auto &i: v) cin >> i;
        ll p=1,ans=0;
        for(int i=0;i<17;i++)
        {
            int zero=0,one=0;
            for(int j=0;j<(int)v.size();j++)
            {
                if(v[j]%2==0) zero++;
                else one++;
                v[j]/=2;
            }
            if(zero<=one) ans+=p;
            p*=2;
        }
        cout << ans << endl;
    }
    return 0;
}