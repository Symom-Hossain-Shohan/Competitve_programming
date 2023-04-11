#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll m, d, mod = 1e9 + 7;
string num; 

ll memo[2001][2][2001]; 

ll dp(ll pos, bool last, ll sum)
{
    if(pos==num.length())
    {
        if(sum == 0) return 1; 
        return 0; 
    }

    if(memo[pos][last][sum] != -1) return memo[pos][last][sum]; 

    ll till = last ? num[pos] - '0' : 9; 
    ll ans = 0; 
    if(pos%2==1)
    {
        if(d<=till) 
        {
            ans = (ans + dp(pos+1, last && (d==till), (sum*10+d)%m)) % mod; 
        }
    }
    else 
    {
        for(int i = 0;i<=till; i++)
        {
            if(i==d) continue;
            ans = (ans + dp(pos+1, last && (i==till), (sum*10+i)%m)) % mod; 
        }
    }

    return memo[pos][last][sum] = ans; 
}

ll fun(string a)
{
    num = a; 
    memset (memo, -1, sizeof(memo)); 
    return dp(0, true, 0); 
}

void sub(string &a)
{
    int i = a.size()-1; 
    while(i>= 0 and a[i]=='0') a[i] = '9', i--; 
    a[i]  -= 1; 
}

void solve()
{
    cin >> m >> d; 
    string a, b; 
    cin >> a >> b; 
    sub(a);
    cout << (fun(b)- fun(a) + mod ) % mod << endl;   
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