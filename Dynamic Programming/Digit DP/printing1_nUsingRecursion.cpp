#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s; 

void printAllNum(string ans, int index, bool is_last)
{
    if(index == s.length()) 
    {
        cout << ans << endl; 
        return; 
    }

    int till = is_last ? (s[index] - '0') : 9 ; 
    for(int i=0;i<=till; i++)
    {
        printAllNum(ans + to_string(i), index + 1, (is_last & (i==till))); 
    }
}

void solve()
{
    cin >> s; 

    printAllNum("", 0, true);
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