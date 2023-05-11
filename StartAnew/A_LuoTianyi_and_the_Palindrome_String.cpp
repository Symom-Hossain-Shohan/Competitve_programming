#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_good(string s)
{
    string a = s; 
    reverse(s.begin(), s.end()); 
    return a == s; 
}

void solve()
{
    string s; 
    cin >> s; 
    while(is_good(s) and !s.empty())
    {
        s.pop_back();
    }

    if(s.empty()) cout << -1 << endl; 
    else cout << s.size() << endl; 

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