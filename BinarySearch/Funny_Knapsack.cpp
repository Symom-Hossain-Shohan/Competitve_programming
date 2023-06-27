#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar1[20], ar2[20];
vector<ll> one, two; 
ll s1, s2; 

void combination(ll pos, ll sum, ll op)
{
    if(op==1)
    {
        if(pos==s1)
        {
            one.push_back(sum); 
            return; 
        }
    }
    else 
    {
        if(pos==s2) 
        {
            two.push_back(sum); 
            return; 
        }
    }

    ll val = 0; 
    if(op==1) val = ar1[pos]; 
    else val = ar2[pos]; 

    combination(pos+1, sum, op); 
    combination(pos+1, sum+val, op); 
}

void solve()
{
    ll n, k; 
    cin >> n >> k;
    one.clear(), two.clear(); 
    s1 = n/2, s2 = n - s1;

    for(int i=0;i<s1; i++) cin >> ar1[i]; 
    for(int i=0;i<s2; i++) cin >> ar2[i]; 

    combination(0, 0, 1); 
    combination(0, 0, 2);

    sort(one.begin(), one.end()); 
    sort(two.begin(), two.end()); 
    ll ans = 0; 
    for(auto i: one)
    {
        if(i<=k)
        {
            ll x = k - i; 

            ll it = upper_bound(two.begin(), two.end(), x) - two.begin(); 
            ans += it; 
        } 
    }

    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}