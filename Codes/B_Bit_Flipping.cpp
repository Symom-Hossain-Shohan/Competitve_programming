#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k ;
    string s ; 
    cin >> n >> k >>  s ; 
    vector<ll> ans(n, 0) ; 
    if(k%2)
    {
        ll ix = n-1 ; 
        for(int i = n-1 ; i>=0 ; i--)
        {
            if(s[i]=='1') ix=i ;
        }
        ans[ix]++;
        k--; 
        for(int i=0 ;i<n ;i++) 
        {
            if(ix==i) continue; 
            else 
            {
                if(s[i]=='0') s[i] = '1' ;
                else s[i] = '0' ;
            }
        }
    }
    for(int i=0;i< n; i++)
    {
        if(s[i]=='0' and k)
        {
            k--;
            ans[i]++;
            s[i] = '1' ;
        }
    }

    ans[n-1]+=k; 
    if(k%2)
    {
        if(s[n-1]=='0') s[n-1] = '1' ;
        else s[n-1] = '0' ;
    }

    cout << s << endl ;
    for(auto i: ans) cout << i << ' ' ;
    cout << endl ;
 
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