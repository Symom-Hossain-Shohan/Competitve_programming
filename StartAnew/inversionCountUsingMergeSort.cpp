#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll merg(vector<ll> &v, ll s, ll m, ll e)
{
    ll cnt = 0, i = s, j = m+1, r = 0; 
    vector<ll> tmp; 
    while(i<=m and j<e)
    {
        if(v[i]<=v[j]) 
        {
            tmp.push_back(v[i]); 
            i++; 
        }
        else tmp.push_back(v[j]), j++, cnt += m-i; 
    }

    while(i<=m) tmp.push_back(v[i]), i++; 
    while(j<e) tmp.push_back(v[j]), j++; 
    for(int i=s;i<e;i++) v[i] = tmp[r], r++; 
    return cnt; 
}

ll mergeSort(vector<ll> &v, ll s, ll e)
{
    if(e-s+1<2) return 0; 
    else 
    {
        int cnt = 0; 
        ll mid = (s+e)/2; 
        cnt += mergeSort(v, s, mid); 
        cnt += mergeSort(v, mid+1, e); 

        cnt += merg(v, s, mid, e); 
        return cnt; 
    }
}

void solve()
{
    vector<ll> v = {1, 20, 6, 4, 5}; 

    cout << mergeSort(v, 0, v.size()-1) << endl; 
    for(auto i: v) cout <<i << ' '; 
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