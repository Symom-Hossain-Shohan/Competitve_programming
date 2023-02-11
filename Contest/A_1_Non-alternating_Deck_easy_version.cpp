#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    n -= 1; 
    ll a = 1, b = 0, cnt =0; 
    for(int i=2;n-i>=0;i++)
    {
        if(cnt==0)
        {
            b += i; 
            n -=i; 
            cnt++; 
        }
        else if(cnt==1)
        {
            b += i; 
            n -=i; 
            cnt++; 
        }
        else if(cnt==2)
        {
            a += i; 
            n-=i; 
            cnt++; 
        }
        else 
        {
            a += i; 
            n-=i; 
            cnt = 0;
        }
    }
    if(cnt<2) b += n; 
    else a += n; 
    cout <<a << ' ' << b << endl; 
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