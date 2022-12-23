#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll x, y; 
    cin >> x >> y; 
    ll mn = -1e18;
    ll one , two ; 
    for(int i=0;i<x;i++)
    {
        for(int j = 0;j<y;j++) 
        {
            ll a; 
            cin >> a;
            if(a>mn)
            {
                mn = a; 
                one = i; 
                two = j; 
            } 
        }
    }

    one++, two++; 
    one = max(one, x-one+1), two = max(two, y-two+1); 
    cout <<one*two << endl;  
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