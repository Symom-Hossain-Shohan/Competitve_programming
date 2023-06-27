#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    map<ll,ll> pos; 
    ll num; 
    ll cur = 1; 
    cin >> num; 
    pos[num] = cur; 
    for(int i = 1;i<1000; i++)
    {
        cur++; 
        cout << "+ " << "1" << endl; 
        cin >> num; 
        if(pos[num])
        {
            cout << "! " << cur - pos[num] << endl; 
            return ; 
        }
        pos[num] = cur; 
    }
    while(1)
    {
        cout << "+ " << "1000" << endl; 
        cur += 1000; 
        cin >> num; 

        if(pos[num])
        {
            cout << "! " << cur - pos[num] << endl; 
            return; 
        }

        pos[num] = cur; 
    }

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