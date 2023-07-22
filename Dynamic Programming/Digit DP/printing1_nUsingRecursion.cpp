#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s; 
ll memo[32][2]; 

ll printAllNum(string ans, int index, bool is_last)
{
    if(index == s.length()) 
    {
        ll cnt = 0; 
        for(int i=1;i<(int)s.length(); i++)
        {
            if(ans[i]==ans[i-1] and ans[i]=='1') cnt++; 
        }
        return cnt; 
    }

    // if(memo[pos][])//

    int till = is_last ? (s[index] - '0') : 1 ; 
    ll x = 0; 
    for(int i=0;i<=till; i++)
    {
        x += printAllNum(ans + to_string(i), index + 1, (is_last && (i==till))); 
    }

    return x; 
}

void solve()
{
    ll n; 
    cin >> n; 
    s.clear(); 
    while(n)
    {
        s += to_string(n%2); 
        n/=2; 
    }


    memset(memo, -1, sizeof(memo)); 

    cout << printAllNum("", 0, true);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}