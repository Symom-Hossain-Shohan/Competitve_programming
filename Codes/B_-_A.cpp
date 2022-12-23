#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

typedef long long ll;

void solve()
{
    int n; 
    while(cin >> n)
    {
        vector<int> v(n); 
        for(auto &i: v) cin >> i; 
        
        ll ans = 0; 
        for(int i=0;i<n-1;i++)
        {
            for(int j = 0;j<n-i-1;j++)
            {
                if(v[j]>v[j+1])
                {
                    swap(v[j], v[j+1]); 
                    ans++; 
                }
            }
        }
        cout << ans << endl; 
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}