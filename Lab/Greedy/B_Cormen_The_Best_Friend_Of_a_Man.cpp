#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k, ans=0, mid;
 
    cin >> n >> k;
    vector<int> ara(n);
 
    for(int K=0; K<n; K++) cin >> ara[K];
 
    for(int K=1; K<n; K++){
        mid = k-ara[K]-ara[K-1];
        if(mid<=0) continue;
        //cout << ara[K] << ' ' << ara[K-1] << ' ' << mid << "\n";
        ara[K] += mid;
        ans += mid;
    }
 
    cout << ans << "\n";
    for(int K=0; K<n; K++) cout << ara[K] << ' ';
    cout << "\n";
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