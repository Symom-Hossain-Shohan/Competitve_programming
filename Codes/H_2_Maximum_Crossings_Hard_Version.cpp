#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


void solve()
{
    int n ; 
    cin >> n ;
    int x ;
    cin >> x ; 
    ordered_set os ; 
    os.insert(x) ; 
    ll ans = 0 ; 
    for(int i=1;i<n;i++)
    {
        cin >> x ; 
        int k = os.order_of_key(x) ; 
        ans+= os.size()-k ; 
        os.insert(x) ; 
    }
    cout << ans << endl ; 
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





