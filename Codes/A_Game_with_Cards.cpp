#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n ;
    cin >> n;
    vector<int> v(n);
    for(auto &i: v) cin >> i ; 
    int m; 
    cin >> m; 
    vector<int> a(m);
    for(auto &i: a) cin >> i; 
    sort(v.begin(), v.end()); 
    sort(a.begin(), a.end()); 
    if(a.back()<v.back()) 
    {
        cout << "Alice\n"; 
        cout << "Alice\n";
    } 
    else if(v.back()<a.back())
    {
        cout << "Bob\n"; 
        cout << "Bob\n"; 
    }
    else 
    {
        cout << "Alice\n"; 
        cout << "Bob\n"; 
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}