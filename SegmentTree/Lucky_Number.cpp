#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll ans[100005];

const int mx = 1429431 + 20;


void solve()
{
    ll n; 
    cin >> n; 
    cout << ans[n] << '\n'; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;

    ordered_set os; 
    os.insert(0);

    for(int i=1;i<=mx; i+=2) os.insert(i); 

    ans[1] = 1; 
    for(int i=2;i<100005; i++)
    {
        if(os.size()<=i) break;
        int x = *(os.find_by_order(i)); 

        vector<ll> v; 
        for(int j=x; j<mx; j+=x)
        {
            if(j>=os.size()) break;
            v.push_back(*(os.find_by_order(j))); 
        }

        for(auto j: v) os.erase(j); 

        ans[i] = x; 
    }

    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}