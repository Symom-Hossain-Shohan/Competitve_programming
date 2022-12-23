#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i: v) cin >> i;
    sort(v.begin(),v.end());

    ll two=0,one=0;
    for(int i=0;i<n;i++)
    {
        ll x=v[n-1]-v[i];
        two+=x/2;
        one+=x%2;
    }
    //cout << one << ' ' << two << endl;
    if(one==two) cout << one+two << endl;
    else if(one-two==1) cout << one+two  << endl;
    else if(two-one==1) cout << 2*two << endl;
    else if(one-two>1) cout << 2*one-1 << endl;
    else 
    {
        ll x=(two-one)/3;
        one=one+2*x;
        two=two-x;
        //cout << one << ' ' << two << endl;
        if(one==two) cout << one+two << endl;
        else if(one-two==1) cout << one+two  << endl;
        else if(two-one==1) cout << 2*two << endl;
        else if(one-two>1) cout << 2*one-1 << endl;
    }

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