#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n ; 
    cin >> n; 
    vector<ll> v(n) ;
    for(auto &i: v) cin >> i ;
    
    ll ans = 1e18 ; 
    for(int i=0;i< n;i++)
    {
        vector<ll> b(n, 0); 
        ll cnt = 0;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]>b[j-1])
            {
                cnt++;
                b[j]=v[j];
            }
            else 
            {
                ll t = b[j-1]/v[j];
                if(t*v[j]<=b[j-1]) t++ ;
                cnt+= t ;
                b[j] = t*v[j];
            }
        }

        for(int j=i-1;j>=0;j--)
        {
            if(v[j]>b[j+1])
            {
                cnt++;
                b[j]=v[j];
            }
            else 
            {
                ll t = b[j+1]/v[j] ;
                if(t*v[j]<=b[j+1]) t++ ;
                cnt+= t ;
                b[j]=t*v[j] ;
            }
        }
        ans=min(ans,cnt) ;
    }

    cout << ans << endl;
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