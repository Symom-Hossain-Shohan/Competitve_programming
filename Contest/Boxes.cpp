#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v; 
ll n; 


bool good(ll index)
{
    index--; 
    vector<ll> temp; 
    for(int i=index; i<n; i++)
    {
        temp.push_back(v[i]); 
    }

    for(int i = 0, j=index;i<index; i++ ,j++)
    {
        if(temp[j]>=v[i])
        {
            temp[j] = temp[j] ^ v[i]; 
        }
        else return false; 
        if(j==n-1) j = index-1; 
    }

    return true; 
}


void solve()
{
    cin >> n; 
    v.resize(n); 
    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end());

    if(n==1)
    {
        cout << 1 << endl; 
        return; 
    }


    ll low  = 1, high = n, ans = -1; 
    while(low<=high)
    {
        ll mid = (low+high)/2; 

        if(good(mid))
        {
            ans = mid; 
            low = mid+1; 
        }
        else high = mid-1; 
    }

    cout << n-ans-1 << endl; 
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