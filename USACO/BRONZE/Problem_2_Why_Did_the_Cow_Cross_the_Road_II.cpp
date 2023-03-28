#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; 
    cin >>s; 
    ll ans = 0; 
    for(int a = 0;a<52;a++)
    {
        for(int b =a+1; b<52;b++)
        {
            for(int c=b+1;c<52;c++)
            {
                for(int d=c+1;d<52;d++)
                {
                    if(s[a]==s[c] and s[b]==s[d]) ans++; 
                }
            }
        }
    }
    cout << ans << endl; 
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}