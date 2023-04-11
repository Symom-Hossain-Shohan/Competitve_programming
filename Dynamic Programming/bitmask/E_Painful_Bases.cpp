#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map<char, ll> val = { {'0' , 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
                        {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, 
                        {'D', 13}, {'E', 14}, {'F', 15}
                      }; 

ll b, k; 
string num; 

ll memo[(1<<12)][21];

ll dp(ll mask, ll mod, ll pos)
{
    if(mask == (1<<num.size())-1) return mod == 0; 
    if(memo[mask][mod]!=-1) return memo[mask][mod]; 

    ll ans = 0, n = num.size();
    for(int i=0;i<n;i++)
    {
        if(!((1<<i) & mask))
        {
            ans += dp((mask)|(1<<i), (mod+ (ll)pow(b, pos) * val[num[i]] + k) % k, pos-1); 
        }
    }
    return memo[mask][mod] = ans; 
}

void solve()
{
    cin >> b >> k; 
    cin >> num; 
    memset(memo, -1, sizeof(memo)); 
    cout << dp(0, 0, num.size()-1) << endl; 

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