#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    multiset<ll> st; 
    st.insert(1);
    st.insert(2); 
    st.insert(1);
    //for(auto i: st) cout << i << ' ';
    cout << st.size();
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