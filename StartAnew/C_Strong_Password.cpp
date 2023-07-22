#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 3e5 + 1; 
string s, a, b; 
ll m; 


vector<ll> v[10];

ll memo[10][N]; 

bool dp(ll pos1, ll pos2)
{
    if(pos1==m)
    {
        return pos2 == (int)s.size()+1;
    }

    if(memo[pos1][pos2]!=-1) return memo[pos1][pos2]; 
    ll ans = 0; 
    for(int i=a[pos1]-'0'; i<=b[pos1]-'0'; i++)
    {
        ll x = upper_bound(v[i].begin(), v[i].end(), pos2)-v[i].begin();
        if(x==v[i].size()) x =  (int)s.size()+1;
        else  x = v[i][x]; 
        //cout << pos1 << ' ' << i << ' ' << x << endl; 
        ans = ans | (dp(pos1+1, x)); 
    }
    return memo[pos1][pos2] = ans; 
}

void solve()
{
    cin >> s; 
    for(int i=0;i<10; i++) v[i].clear();

    for(int i = 0;i<(int)s.size(); i++)
    {
        v[s[i]-'0'].push_back(i+1);
    }

    cin >> m; 

    cin >> a >> b; 
    
    for(int i=0;i<10; i++)
    {
        for(int j=0;j<=(int)s.size()+2; j++) memo[i][j] = -1; 
    }

    if(dp(0, 0)) cout << "YES\n"; 
    else cout << "NO\n"; 
    


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