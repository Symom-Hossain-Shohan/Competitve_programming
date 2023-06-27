#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const ll MX = 2e5 + 5;

inline void norm(ll &a)
{
    a %= mod;
    (a < 0) && (a += mod);
} // positive mod value
inline ll modAdd(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a + b) % mod;
} // modular addition
inline ll modSub(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a - b) % mod;
} // modular subtraction
inline ll modMul(ll a, ll b)
{
    a %= mod, b %= mod;
    norm(a), norm(b);
    return (a * b) % mod;
} // modular multiplication

inline ll bigMod(ll b, ll p)
{
    ll r = 1;
    while (p)
    {
        if (p & 1LL)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1LL;
    }
    return r;
}
inline ll modInverse(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

bool isVowel(char a)
{
    if (a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u')
        return true;
    else
        return false;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    string s;
    cin >> s;
    ll cnt = 0;

    ll tt = 0; 
    
    for(int i=0;i<n;i++)
    {
        if(isVowel(s[i])) tt++; 
    }

    if(tt%k!=0)
    {
        cout << 0 << endl; 
        return; 
    }

    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i]))
        {
            cnt++;
            //cout << s[i] << ' ';
            if (cnt == k)
            {
                ll x = 1;
                for (int j = i + 1; j < n; j++)
                {
                    if (isVowel(s[j]))
                    {
                        i = j - 1;
                        if (j != n-1)
                            ans = modMul(ans, x);
                        break;
                    }
                    else
                        x++;
                }
                //ans = modMul(ans, x);
                cnt = 0;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}