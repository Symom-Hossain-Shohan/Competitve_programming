#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n) ; 
    for(auto &i: v) cin >> i ; 
    ll a =0, b=0, ans = 0;
    a=v[0] , b=v[n-1];
    for(ll i=0,j=n-1;i<j;)
    {
        if(a<b)
        {
            i++; 
            a+=v[i];
        }
        else if(a>b)
        {
            j--;
            b+=v[j];
        }
        else 
        {
            ans=max(ans,n-(j-i)+1) ;
            i++;
            a+=v[i];
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