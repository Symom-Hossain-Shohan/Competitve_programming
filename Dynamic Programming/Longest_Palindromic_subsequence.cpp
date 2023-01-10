//https://leetcode.com/problems/longest-palindromic-subsequence/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string s; 
    vector<vector<int>> memo; 
    int dp(int i, int j)
    {
        if(i==j) return 1; 
        if(i+1==j)
        {
            if(s[i] == s[j]) return 2; 
            else return -1e7; 
        }
        int &ans = memo[i][j];
        if(ans == -1)
        {
            if(s[i] == s[j]) ans = 2 + dp(i+1, j-1);
            else ans = max(dp(i, j-1), dp(i+1, j));
        }
         
        return ans; 
        
    }
    int longestPalindromeSubseq(string s) {
        this->s = s; 
        memo.resize(s.size()+1, vector<int> (s.size()+1, -1)); 
        int ans = dp(0, s.size()-1);
        return ans;
    }
};

void solve()
{
    string s; 
    cin >> s; 

    Solution sv; 
    cout << sv.longestPalindromeSubseq(s);
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