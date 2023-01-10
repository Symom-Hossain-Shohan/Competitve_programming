//https://leetcode.com/problems/palindromic-substrings/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string s; 
    vector<vector<int>> memo; 
    bool dp(int i, int j)
    {
        if(i==j) return true; 
        else if(j== i+1)
        {
            if(s[i] == s[j]) return true; 
            else return false; 
        }

        int &ans = memo[i][j];
        if(ans == -1)
        {
            if(s[i]==s[j]) ans = dp(i+1, j-1);
            else ans = false; 
        }
        return ans; 


    }
    int countSubstrings(string s) {
        this->s = s; 
        ll ans = 0; 
        memo.resize(s.size() +1, vector<int> (s.size()+1, -1)); 
        for(int i=0;i<(int)s.size(); i++)
        {
            for(int j=i;j<(int)s.size(); j++)
            {
                ans += dp(i, j);
            }
        }
        return ans; 
    }
};


void solve()
{
    string s; 
    cin >> s; 
    Solution st; 
    cout << st.countSubstrings(s);
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