#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int power(int a, int e) {
    if (e == 0) return 1;
    return e == 1 ? a : a * power(a, e-1);
}


void solve()
{
    ll a, b, c, k; 
    cin >> a >> b >> c >> k; 

    for(int i= power(10, a-1); i<power(10, a); i++)
    {
        ll minb = max(power(10, b-1), power(10, c-1)-i); 
        ll maxb = min(power(10, b)-1, power(10, c)-1-i); 

        if(minb>maxb) continue;
        ll range = maxb - minb + 1; 

        if(k<=range) 
        {
            cout << i << " + " << minb + k-1 << " = " << i + minb + k -1 << endl; 
            return; 
        }
        else k -= range; 
    }

    cout << -1 << endl; 
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