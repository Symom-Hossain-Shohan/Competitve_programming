#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n , m; 
    cin >> n >> m; 
    string s;  
    cin >> s; 
    s = "#" + s; 

    vector<ll> zero, one; 
    for(int i=1;i<=n; i++)
    {
        if(s[i]=='1') one.push_back(i); 
        else zero.push_back(i); 
    }


    vector<ll> count_one(n+1, 0); 
    for(int i=1;i<=n; i++)
    {
        count_one[i] = s[i]-'0' + count_one[i-1]; 
    }

    set<pair<ll,ll>> ans;

    for(int i=0;i<m; i++)
    {
        ll l, r; 
        cin >> l >> r; 
        ll ones = count_one[r] - count_one[l-1]; 
        if(ones==(r-l+1) or ones==0 or l==r)
        {
            ans.insert({-1, -1}); 
        }
        else 
        {
            ll firstOne = lower_bound(one.begin(), one.end(), l) - one.begin(); 
            ll lastzeor = upper_bound(zero.begin(), zero.end(), r) - zero.begin(); 
            lastzeor--; 
            if(one[firstOne]<zero[lastzeor]) ans.insert({one[firstOne], zero[lastzeor]}); 
            else ans.insert({-1, -1}); 
        }
    }

    // for(auto i: ans)
    // {
    //     cout << i.first << ' ' << i.second << endl; 
    // }
    cout << ans.size() << endl;
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