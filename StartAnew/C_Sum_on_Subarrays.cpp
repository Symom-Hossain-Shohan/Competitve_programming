#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    if(k==0)
    {
        while(n--) cout << -1 << ' ';
        cout <<endl; 
        return; 
    }
    ll x = 0; 
    for(int i=1;i<=n;i++)
    {
        if(i*(i+1)/2<=k) x = i; 
    }
    //cout << x << endl; 

    for(int i=1;i<=x;i++) cout << 2 << ' ';

    if(k-(x*(x+1)/2)>0)
    {
        //cout << "Yes\n";
        ll req = k - x*(x+1)/2; 
        cout << -((x-req+1)*2-1) << ' ';
        x++; 
    }
     
    for(int i=x+1;i<=n;i++) cout << -1000 << ' ';
    cout << endl; 
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