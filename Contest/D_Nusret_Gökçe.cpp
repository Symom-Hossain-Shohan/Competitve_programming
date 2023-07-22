#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;



void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<ll> v(n);
    for(auto &i: v) cin >> i; 
    map<ll,vector<ll>> mp; 
    for(int i=0;i<n;i++) mp[v[i]].push_back(i); 

    ordered_set os; 
    for(auto i: v) os.insert(i); 

    if(k==0)
    {
        ll x = *max_element(v.begin(), v.end()); 
        for(int i=0;i<n; i++) cout << x <<' '; 
        return; 
    }

    while(!os.empty())
    {
        auto it = os.end(); it--; 
        ll x = *it; 
        os.erase(x); 


        for(auto index: mp[x])
        {
            if(index<n-1)
            {
                if(abs(v[index]-v[index+1])>k)
                {
                    ll val = v[index+1]; 
                    v[index+1] = v[index] - k; 
                    mp[v[index]-k].push_back( index+1); 
                    os.insert(v[index]-k); 
                    os.erase(val); 
                } 
            }
            if(index>0)
            {
                if(abs(v[index]-v[index-1])>k)
                {
                    ll val = v[index-1]; 
                    v[index-1] = v[index] - k; 
                    mp[v[index]-k].push_back(index-1); 
                    os.insert(v[index]-k); 
                    os.erase(val); 
                }
            }
        }

    }

    for(auto i: v) os.insert(i); 

    while(!os.empty())
    {
        auto it = os.end(); it--; 
        ll x = *it; 
        os.erase(x); 


        for(auto index: mp[x])
        {
            if(index<n-1)
            {
                if(abs(v[index]-v[index+1])>k)
                {
                    ll val = v[index+1];
                     
                    v[index+1] = v[index] - k; 
                    mp[v[index]-k].push_back( index+1); 
                    os.insert(v[index]-k); 
                    os.erase(val); 
                } 
            }
            if(index>0)
            {
                if(abs(v[index]-v[index-1])>k)
                {
                    ll val = v[index-1]; 
                    v[index-1] = v[index] - k; 
                    mp[v[index]-k].push_back(index-1); 
                    os.insert(v[index]-k); 
                    os.erase(val); 
                }
            }
        }

    }



    for(auto i: v) cout << i  << ' '; 
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