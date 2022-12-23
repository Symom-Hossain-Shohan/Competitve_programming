#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);

    for(auto &i: v) cin >> i; 
    sort(v.begin(), v.end());

    if(n%2==1) cout << "NO\n";
    else 
    {
        vector<ll> ans(n);
        int j = 0; 
        for(int i = 0;i<n;i+=2, j++) ans[i] =  v[j];
        for(int i=1;i<n;i+=2, j++) ans[i] = v[j];

        bool ok = true; 

        for(int i=1;i<n-1;i++)
        {
            if(!((ans[i]>ans[i+1] and ans[i]>ans[i-1]) or (ans[i]<ans[i+1] and ans[i]<ans[i-1]))) ok = false;
        }
        if(!((ans[0]>ans[1] and ans[0]>ans[n-1]) or (ans[0]<ans[1] and ans[0]<ans[n-1]))) ok = false;
        if(!((ans[n-1]>ans[n-2] and ans[n-1]>ans[0]) or (ans[n-1]<ans[n-2] and ans[n-1]<ans[0]))) ok = false;

        if(ok ) 
        {
            cout << "YES\n"; 
            for(auto i: ans) cout << i <<  ' '; 
            cout << endl; 
        }
        else cout << "NO\n";
    }
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