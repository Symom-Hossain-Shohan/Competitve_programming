#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> a,b;
ll n,ans=1e18;
void case1()
{
    ans=abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
    ans=min(ans,abs(a[0]-b[n-1])+abs(a[n-1]-b[0]));
}

void case2()
{
    ll sum=abs(a[0]-b[0]);
    ll x=1e18,y=1e18;
    for(int i=0;i<n;i++)
    {
        x=min(x,abs(a[n-1]-b[i]));
        y=min(y,abs(b[n-1]-a[i]));
    }
    sum+=x+y;
    ans=min(ans,sum);

    sum=abs(a[n-1]-b[n-1]);
    x=y=1e18;

    for(int i=0;i<n;i++)
    {
        x=min(x,abs(a[0]-b[i]));
        y=min(y,abs(b[0]-a[i]));
    }
    sum+=x+y;
    ans=min(ans,sum);

    sum=abs(a[0]-b[n-1]);
    x=y=1e18;

    for(int i=0;i<n;i++)
    {
        x=min(x,abs(a[n-1]-b[i]));
        y=min(y,abs(b[0]-a[i]));
    }
    sum+=x+y;
    ans=min(ans,sum);

    sum=abs(a[n-1]-b[0]);
    x=y=1e18;
    for(int i=0;i<n;i++)
    {
        x=min(x,abs(a[0]-b[i]));
        y=min(y,abs(b[n-1]-a[i]));
    }
    sum+=x+y;
    ans=min(ans,sum);
}

void case3()
{
    ll w,x,y,z;
    w=x=y=z=1e18;
    for(int i=0;i<n;i++)
    {
        x=min(x,abs(a[0]-b[i]));
        w=min(w,abs(a[n-1]-b[i]));
        y=min(y,abs(b[0]-a[i]));
        z=min(z,abs(b[n-1]-a[i]));
    }
    ans=min(ans,w+x+y+z);
}

void solve()
{
    ans=1e18;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;
    case1();
    case2();
    case3();
    cout << ans << endl;
}

int main()
{
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}