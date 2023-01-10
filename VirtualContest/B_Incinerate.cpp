#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; 
    cin >> n >> k; 
    vector<pair<ll,ll>> hp(n);

    for(int i=0;i<n;i++) cin >> hp[i].second; 
    for(int i=0;i<n;i++) cin >> hp[i].first; 

    sort(hp.begin(), hp.end());

    ll dmg = k; 

    for(int i = 0;i<n;i++)
    {
        while(hp[i].second>dmg)
        {
            k -= hp[i].first; 
            if(k<0)
            {
                break;
            }
            dmg +=k;
        }

        if(hp[i].second>dmg)
        {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";


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