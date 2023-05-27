#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


//defines...
#define ll           long long
const ll mod=1e9+7;
const ll MX=2e5+5;




typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;



void solve()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 

    ll ans =  0; 
    for(int i = 0;i<n; i++)
    {
        ordered_set os; 
        bool ok = true; 
        ll l = 0; 
        for(int j=i;j<n;j++)
        {
            os.insert(v[j]); 

            //ans += os.size()-os.order_of_key(v[j])-1; 
            if(os.order_of_key(v[j])!=os.size()-1) 
            {
                ok = false; 
            }
            else 
            {
                if(ok==true) l++; 
            }

            if(os.order_of_key(v[j])+1>l) ans += os.size()-os.order_of_key(v[j])-1; 
            else ans += os.size();
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
        solve();
    }
    return 0;
}