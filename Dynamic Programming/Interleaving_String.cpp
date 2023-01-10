//https://leetcode.com/problems/interleaving-string/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string s1, s2, s3; 
    vector<vector<vector<int>>> memo; 
    bool dp(int i, int j, int k)
    {
        if(i==s1.size() and j==s2.size() and k==s3.size()) return true; 
        if(i==s1.size() and j==s2.size()) return false; 

        int &ans = memo[i][j][k];

        if(ans == -1)
        {
            bool ok = false; 
            if(s1[i] == s2[j] and s1[i] == s3[k] and i<s1.size() and j<s2.size() and k<s3.size())
            {
                ok |= (dp(i+1, j, k+1) | dp(i, j+1, k+1)); 
            }
            else if(s1[i] == s3[k] and i<s1.size()  and k<s3.size() ) ok |= dp(i+1,j,  k+1);
            else if(s2[j]==s3[k] and  j<s2.size() and k<s3.size()) ok |= dp(i, j+1, k+1);
            else return ans = false;

            ans = ok;  
        }
        return ans; 
    }
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1; 
        this->s2 = s2; 
        this->s3 = s3; 
        
        memo.resize(s1.size() +1, vector<vector<int>> (s2.size()+1, vector<int> (s3.size()+1, -1)));
        return dp(0, 0, 0);
    }
};

void solve()
{
    string s1, s2, s3; 
    cin >> s1 >> s2 >> s3; 
    Solution s; 
    cout << s.isInterleave(s1, s2, s3); 
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