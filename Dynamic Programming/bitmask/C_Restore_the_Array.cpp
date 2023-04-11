#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
map<char, ll> val = { {'0' , 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
                        {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10}, {'B', 11}, {'C', 12}, 
                        {'D', 13}, {'E', 14}, {'F', 15}
                      }; 

void solve()
{
    
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