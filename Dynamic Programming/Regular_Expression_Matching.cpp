#include<bits/stdc++.h>
using namespace std;

    typedef long long ll;

    class Solution {
    public:
        string s, p; 
        vector<vector<ll>> memo; 
        bool dp(ll i, ll j)
        {
            if(i == 0 and j==0) return true; 
            if(j==0) return false; 

            ll &ans = memo[i][j]; 
            if(ans == -1)
            {
                bool ok = false; 
                if(s[i-1] == p[j-1])
                {
                    ok |= dp(i-1, j-1);
                }
                else if(p[j-1]=='.')
                {
                    if(i>0) ok |= dp(i-1, j-1);
                    else return ans = false; 
                }
                else if(p[j-1] == '*')
                {
                    if(i>0) ok |= dp(i-1, j); 
                    ok |= dp(i, j-1);
                }
                ans = ok; 
            }

            return ans; 
        }
        bool isMatch(string s, string p) {
            this->s = s; 
            this->p = p; 
            memo.resize(s.size()+5, vector<ll> (p.size()+5, -1)); 
            return dp(s.size(), p.size()); 
        }
    };

void solve()
{
    string s, p; 
    cin >> s >> p; 
    Solution sp; 
    cout << sp.isMatch(s, p); 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}