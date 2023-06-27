#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, q; 
    cin >> n>> q; 
    vector<ll> a(n), b; 
    for(auto &i: a) cin >> i; 

    sort(a.begin(), a.end()); 

    while(q--)
    {
        ll k; 
        cin >> k; 
        b = a; 
        if(k<=n)
        {
            for(int i=0;i<n and k>=0; i++)
            {
                b[i] += k; 
                k--; 
            }

            cout << *min_element(b.begin(), b.end()) << ' '; 
            continue;
        }
        else 
        {
            for(int i=0;i<n and k>=0 ; i++) 
            {
                b[i] += k; 
                k--; 
            }
            if(k%2==1)  k++, b[n-1] -= k; 
            k/=2; 
            sort(b.begin(), b.end()); 

            ll sum = 0; 
            for(auto i: b) sum += i; 
            sum -= k; 
            cout << min(b[0], sum/n) << ' ';
        }

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