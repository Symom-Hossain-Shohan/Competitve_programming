#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    string s; 
    cin >> s; 

    int freq[26];
    memset(freq, 0, sizeof(freq)); 

    for(int i=0;i<n;i++) freq[s[i]-'a']++; 

    vector<pair<ll,ll>> vp; 
    for(int i = 0;i<26;i++) vp.push_back({freq[i], i}); 

    sort(vp.rbegin(), vp.rend()); 

    ll mx = -1, ans = -1; 
    for(int i = 1;i<=26;i++)
    {
        if(n%i==0)
        {
            ll occur = n/i, same = 0; 
            for(int j=0;j<i;j++)
            {
                same += min(occur, vp[j].first); 
            }

            if(same>mx)
            {
                mx = same; 
                ans = i; 
            }

        }
    }

    int present[26], need[26];
    memset(present, 0, sizeof(present)); 
    memset(need, 0, sizeof(need)); 

    for(int i = 0;i<ans;i++)
    {
        present[vp[i].second] = min(n/ans, vp[i].first); 
        need[vp[i].second] = max(0ll, (n/ans)-present[vp[i].second]); 
    }
    cout << n-mx << endl; 

    for(int i =0;i<n;i++)
    {
        if(present[s[i]-'a']>0)
        {
            present[s[i]-'a']--; 
            cout << s[i];
        }
        else 
        {
            for(int j  = 0;j<26; j++)
            {
                if(need[j]>0)
                {
                    need[j]--; 
                    cout << (char)('a'+j); 
                    break;
                }
            }
        }
    }
    cout << endl; 
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