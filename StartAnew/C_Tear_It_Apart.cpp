#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fun(ll x)
{
    ll res = 0; 
    while(x)
    {
        res++; 
        x/=2; 
    }
    return res; 
}

void solve()
{
    string s; 
    cin >> s; 
    set<char> st; 
    for(auto i: s) st.insert(i);
    ll res = INTMAX_MAX; 
    for(auto c: st)
    {
        ll cnt = 0, ans = -1; 
        for(int i=0;i<(int)s.size(); i++)
        {
            if(s[i]!=c) cnt++; 
            else 
            {
                ans = max(ans, cnt);
                cnt=0; 
            }
        }
        ans = max(ans, cnt);
        res = min(res, fun(ans));
        //cout << c << ' ' << fun(ans) << endl;  
    }
    //cout << fun(9) << endl; 
    cout << res << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}