#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1),b(m+1),c(n+m+1);
    for(auto &i: a) cin >> i;
    for(auto &i: c) cin >> i;

    for(int i=m;i>=0;i--)
    {
        b[i]=c[i+n]/a[n];
        for(int j=0;j<=n;j++) c[i+j]-=(a[j]*b[i]);
    }

    for(auto i: b) cout << i << ' ';
    cout << endl;


    return 0;
}