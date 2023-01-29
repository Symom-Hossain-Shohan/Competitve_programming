#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> a(n), b(n);

    for(auto &i: a) cin >> i; 
    for(auto &i: b) cin >> i; 
    vector<ll> f_a(n+1,0), f_b(n+1, 0), s_a(n+1, 0), s_b(n+1, 0), sum_a(n+1, 0), sum_b(n+1, 0);

    for(int i=n-1, x=n;i>=0;i--, x++)
    {
        sum_a[i] = sum_a[i+1] + a[i];
        sum_b[i] = sum_b[i+1] + b[i];

        f_a[i] = i*a[i] + f_a[i+1]; 
        f_b[i] = x*b[i] + f_b[i+1];
    }

    for(int i=n-1, x=n+1;i>=0;i--,x++)
    {
        s_a[i] = x*a[i] + s_a[i+1];
        s_b[i] = (i+1)*b[i] + s_b[i];
    }

    ll cnt = 0, ans = 0; 

    for(int i=0, t=0;i<n;i++)
    {
        if(i%2==0)
        {
            cnt += a[i]*t; 
            ans = max(ans, cnt+f_a[i+1]+f_b[i]+t*(sum_a[i+1], sum_b[i])); 
            t++; 
            cnt += b[i]*t; 
            ans = max(ans, cnt + s_b[i+1] + s_a[i+1] + t*(sum_a[i+1]+sum_b[i+1])); 
            t++; 
        }
        else 
        {
            cnt += b[i]*t; 
            ans = max(ans, cnt + s_b[i+1] + s_a[i] + t*(sum_b[i+1]+sum_a[i])); 
            t++; 
            cnt += a[i]*t; 
            ans = max(ans, cnt + f_a[i+1] + f_b[i+1] + t*(sum_b[i+1]+ sum_a[i+1])); 
            t++; 
        }
    }

    cout << cnt << ' ' << ans << endl; 


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