#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >> s; 
    ll n = s.size(); 
    ll ones = count(s.begin(), s.end(), '1'); 
    ll zeros = count(s.begin(), s.end(), '0'); 

    vector<ll> pref_zero, suff_zero; 
    ll cnt = 0; 
    for(int i=0;i<n; i++)
    {
        if(s[i]=='0') cnt++; 
        else
        {
            pref_zero.push_back(cnt); 
        }
    }

    pref_zero.push_back(cnt); 
    cnt = 0; 

    for(int i = n-1; i>=0; i--)
    {
        if(s[i] == '0') cnt++; 
        else 
        {
            suff_zero.push_back(cnt); 
        }
    }

    suff_zero.push_back(cnt); 

    ll l = -1, r = ones; 

    while(r>l+1)
    {
        ll mid = (l+r)/2 ;
        bool ok = false; 
        for(int i=0; i<=mid; i++)
        {
            ll left = zeros ; 
            left -= pref_zero[i];
            left -= suff_zero[mid-i]; 
            if(left<=mid)
            {
                ok = true; 
                break;
            }
        }

        if(ok) r = mid; 
        else l = mid; 
    }

    cout << r << endl; 
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