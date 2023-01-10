#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution
{
public:
    string s, p;
    vector<vector<int>> memo;
    bool dp(int i, int j)
    {
        if (i == s.size() and j == p.size())
            return true;
        if (j == p.size())
            return false;

        int &ans = memo[i][j];

        if (ans == -1)
        {
            bool ok = false;
            if (i < s.size() and s[i] == p[j])
                ok |= dp(i + 1, j + 1);
            else if (p[j] == '?')
            {
                if (i < s.size())
                    ok |= dp(i + 1, j + 1);
                else
                    return ans = false;
            }
            else if (p[j] == '*')
            {
                if (i < s.size())
                    ok |= dp(i + 1, j);
                
                ok |= dp(i, j + 1);
            }
            ans = ok;
        }

        return ans;
    }

    bool isMatch(string s, string p)
    {
        this->s = s;
        this->p = p;
        memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0);
    }
};

void solve()
{
    string s, p;
    cin >> s >> p;
    Solution ans;
    cout << ans.isMatch(s, p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}