#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m ;
    cin >> n >> m ;
    vector<string> st ; 
    for(int i=0;i<n;i++){
        string s; 
        cin >> s ;
        st.push_back(s) ;  
    }
    ll ans = 1e18; 
    for(int i=0;i<n-1;i++)
    {   
        
        for(int j = i+1;j<n;j++)
        {
            string a = st[i], b=st[j] ;
            ll cnt = 0; 
            for(int k = 0;k<m;k++)
            {
                cnt += abs(a[k]-b[k]) ; 
            }
            ans = min(ans, cnt) ; 
        }
        
        
    }
    cout << ans << endl; 
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