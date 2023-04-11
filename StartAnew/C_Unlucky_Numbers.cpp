#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string a, b; 

ll memo[20][2][2][10][10];
ll path[20][2][2][10][10];


ll dp(ll pos, bool is_big, bool is_small, ll mn, ll mx)
{
    if(pos>=a.size())
    {
        return mx - mn; 
    }

    ll &ans = memo[pos][is_big][is_small][mn][mx];
    if(ans !=-1) return ans; 

    ans = 10; 
    ll l = a[pos] - '0', r = b[pos] - '0';
    ll low = l, high = r;

    if(is_big) low = 0; 
    if(is_small) high = 9; 

    for(ll i = low; i<=high; i++)
    {
        ll x = dp(pos+1, is_big | (i>l), is_small | (i<r), min(mn, i), max(mx, i)); 
        if(x<ans)
        {
            ans = x; 
            path[pos][is_big][is_small][mn][mx] = i; 
        }
    }
    return ans; 

}

void print(ll pos, bool is_big, bool is_small, ll mn, ll mx)
{
    if(pos==a.size()) return ; 
    ll l = a[pos] - '0', r = b[pos] - '0';

    ll p = path[pos][is_big][is_small][mn][mx];
    cout << p; 
    print(pos+1, is_big | (p>l), is_small | (p<r), min(p, mn), max(p, mx)); 
}

void solve()
{
    cin >> a >> b;

    if(a.size()!=b.size())
    {
        for(int i = 0;i<(int)a.size(); i++) cout << '9';
        cout << endl; 
        return; 
    }

    memset(memo, -1, sizeof(memo)); 

    dp(0, 0, 0, 9, 0); 
    print(0, 0, 0, 9, 0); 
    cout << endl; 


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