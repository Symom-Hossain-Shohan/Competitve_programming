#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1;
map<char, ll> mp;
ll memo[N][33][2];
ll n;
string s;

ll dp(ll pos, ll mask, ll flag)
{
    if (pos == n)
        return 0;
    if (memo[pos][mask][flag] != -1)
        return memo[pos][mask][flag];

    // change korbo na
    ll op1 = -1e18;
    int i = s[pos] - 'A';
    bool ok = true;
    for (int j = i + 1; j < 5; j++)
    {
        if ((1 << j) & mask)
            ok = false;
    }

    if (ok)
        op1 = mp['A' + i] + dp(pos + 1, mask | (1 << i), flag);
    else
        op1 = -mp['A' + i] + dp(pos + 1, mask | (1 << i), flag);

    // change korbo
    ll op2 = -1e18;
    if (flag == 0)
    {
        ll x = s[pos]-'A'; 
        for(int i=0;i<5; i++)
        {
            if(i==x) continue;
            bool ok = true; 
            for(int j=i+1; j<5;j++)
            {
                if((1<<j) & mask) ok = false; 
            }

            if(ok) op2 = max(op2, mp['A'+i] + dp(pos+1, mask | (1<<i), 1)); 
            else op2 = max(op2, -mp['A'+i] + dp(pos+1, mask | (1<<i), 1));
        }
    }
    else
    {
        int i = s[pos] - 'A';
        bool ok = true;
        for (int j = i + 1; j < 5; j++)
        {
            if ((1 << j) & mask)
                ok = false;
        }

        if (ok)
            op2 = mp['A' + i] + dp(pos + 1, mask | (1 << i), flag);
        else
            op2 = -mp['A' + i] + dp(pos + 1, mask | (1 << i), flag);
    }

    return memo[pos][mask][flag] = max(op1, op2); 
}

void solve()
{
    cin >> s;
    reverse(s.begin(), s.end());
    n = s.size();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= 32; j++)
            memo[i][j][0] = -1, memo[i][j][1] = -1;
    }
    cout << dp(0, 0, 0) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    mp['A'] = 1, mp['B'] = 10, mp['C'] = 100, mp['D'] = 1000, mp['E'] = 10000;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}