#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    set<ll> st; 
    map<ll,ll> mp; 
    for(int i=0;i<2*n;i++)
    {
        ll x; 
        cin >> x; 
        mp[x]++; 
    }

    vector<ll> v; 
    for(auto i: mp)
    {
        ll x = i.second; 
        if(x !=2)
        {
            cout << "NO\n"; 
            return; 
        }
        while(x>1)
        {
            v.push_back(i.first);
            x/=2; 
        }
    }

    if(v.size()!=n)
    {
        cout << "NO\n";
        return ; 
    }
    ll minus = 0; 
    for(int i=n-1;i>=0; i--)
    {
        if((v[i]-minus)%((i+1)*2)!=0)
        {
            cout << "NO\n"; return; 
        }
        else 
        {
            ll x = (v[i] - minus)/ (2*(i+1));
            //cout << x << ' ';
            if(x<=0)
            {
                cout << "NO\n"; 
                return; 
            }
            minus += 2*x; 
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