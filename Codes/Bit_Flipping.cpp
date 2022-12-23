#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



void solve()
{
    ll n, k;
    cin>> n >> k;
    string s;
    cin >> s;
    ll zero=0,one=0;
    vector<ll> ans(n,0);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0') zero++;
        else one++;
    }
    if(k==0) 
    {
        cout << s << endl;
        for(auto i: ans) cout << i << ' ' ;
        cout << endl;
    }
    else 
    {
        if(one<zero)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i]=='1')
                {
                    k--;
                    ans[i]++;
                    for(int j=i-1;j>=0;j--) 
                    {
                        if(s[j]=='0') s[j]='1' ;
                        else s[j] = '0' ;
                    }
                    for(int j=i+1;j<n;j++) 
                    {
                        if(s[j]=='0') s[j]='1' ;
                        else s[j] = '0' ;
                    }
                    break;
                }
            }
            

        }
        zero =0 ;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0') zero++;
            }
            if(zero%2) zero--;
            zero=min(zero,k) ;
            for(int i=0;i<n and zero ;i++)
            {
                if(s[i]=='0') 
                {
                    zero--;
                    ans[i]++;
                    k--;
                    if(s[i]=='0') s[i]='1' ;
                        else s[i] = '0' ;
                }
            }
            ans[n-1]+=k;
            if(k%2) 
            {
                if(s[n-1]=='0') s[n-1]='1' ;
                        else s[n-1] = '0' ;
            }
        cout << s << endl;
        for(auto i :ans) cout << i <<' ' ;
        cout << endl;
    }
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