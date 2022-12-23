#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    double c;
    cin >>c;
    double l=0, r=c ;
    for(int i=0;i<100;i++)
    {
        double m=(r+l)/2;
        if(m*m+sqrt(m)<=c) l=m;
        else r=m;
    }
    cout << setprecision(20) << l << endl;
}

int main()
{
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}