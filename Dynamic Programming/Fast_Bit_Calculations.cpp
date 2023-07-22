#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s; 

ll memo[32][2]; 

ll dp(string num, ll pos, ll last)
{
    if(pos==(int)s.size())
    {
        cout << num << endl; 
        ll cnt = 0; 
        for(int i=1;i<(int)s.size(); i++)
        {
            if(num[i]==num[i-1] and num[i]=='1') cnt++; 
        }
        return cnt; 
    }

    if(memo[pos][last] !=-1) return memo[pos][last]; 


    ll till = last ? (s[pos] - '0') : 1; 

    ll x = 0; 
    for(int i=0;i<=till; i++)
    {
        x += dp(num+ to_string(i), pos+1, last &&(i==till)); 
    } 

    return memo[pos][last] = x; 
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
    reverse(s.begin(), s.end()); 
    memset(memo, -1, sizeof(memo)); 
    cout << dp("", 0, 1) << endl; 
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