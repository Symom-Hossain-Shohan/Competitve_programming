#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
 
void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    vector<ll> b(n, 0); 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[i]) b[i]++; 
        }
    }

    for(int i=0;i<n;i++) cout << b[i] << ' '; 
    cout << endl; 

     

    ll ans = 0; 

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[j]>v[i]) b[j]--;
        }

        for(int j=1;j<=i;j++) b[j] += b[j-1]; 
        
    }
    

    //cout << ans << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}