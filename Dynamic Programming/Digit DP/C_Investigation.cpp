#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, k; 
string num; 
int memo[10][2][91][91];

int dp(int pos, bool is_last, int sumOfdigits, int numMod)
{
    if(pos==num.length())
    {
        if(sumOfdigits==0 && numMod == 0)
        {
            return 1;
        }
        return 0; 
    }

    if(memo[pos][is_last][sumOfdigits][numMod]!=-1) return memo[pos][is_last][sumOfdigits][numMod]; 
    int till = is_last ? (num[pos]-'0') : 9; 
    int ans = 0; 
    for(int i = 0;i <=till; i++)
    {
        ans += dp(pos+1, is_last && (i==till), (sumOfdigits+i)%k, (numMod*10+i)%k); 
    }
    return memo[pos][is_last][sumOfdigits][numMod] = ans; 
}

int fun(int n)
{
    num = to_string(n);
    if(k>90) return 0; 
    memset(memo, -1, sizeof(memo)); 

    return dp(0, true, 0, 0); 
}

void solve()
{
    cin >> a >> b >> k; 
    //cout << a << ' ' <<  b << ' ' << k << endl; 
    cout << fun(b) - fun(a-1) << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": "; 
        solve();
    }
    return 0;
}