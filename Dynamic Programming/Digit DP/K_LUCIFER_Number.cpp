#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string num; 

bool isPrime(ll x, ll y)
{
    ll dif; 
    if(num.length()%2==0) dif = x - y; 
    else dif = y - x; 
    if(dif<=1) return false; 
    for(int i=2;i*i<=dif; i++) if(dif%i==0) return false;
    return true; 
}

ll memo[12][2][60][60];

ll dp(ll pos, bool last, ll evenSum, ll oddSum)
{
    if(pos==num.size())
    {
        return isPrime(evenSum, oddSum);
    }

    ll till = last ? (num[pos] - '0') : 9; 
    ll &ans = memo[pos][last][evenSum][oddSum]; 
    if(ans!=-1) return ans; 
    ans = 0; 

    for(int i=0;i<=till; i++)
    {
        if(pos % 2==1) ans += dp(pos + 1, last && (i==till), evenSum, oddSum + i); 
        else ans += dp(pos + 1, last && (i==till), evenSum + i, oddSum); 
    }
    return ans; 
}

ll fun(ll n)
{
    num = to_string(n);
    memset(memo, -1, sizeof(memo)); 
    return dp(0, true, 0, 0);
}

void solve()
{
    ll a, b; 
    cin >> a >> b; 
    cout << fun(b) - fun(a-1) << endl; 
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