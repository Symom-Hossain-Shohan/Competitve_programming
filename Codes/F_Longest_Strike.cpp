#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k ;
    cin >> n >> k ;
    vector<ll> v(n) ; 
    map<ll,ll> mp ; 
    for(auto &i: v) 
    {
        cin >> i ; 
        mp[i]++;
    }

    sort(v.begin(),v.end()) ; 

    int dif = -1, l =-1 , r =-1 ;
    for(int i =0;i<n;i++)
    {
        if(mp[v[i]]>=k)
        {
            int tm = v[i] ; 
            if(dif<0)
            {
                dif = 0; 
                l = v[i] , r=v[i] ; 
            }
            for(int j=i+1;j<n;j++)
            {
                if(v[j]-tm<=1 and mp[v[j]]>=k )
                {
                    if(dif<v[j]-v[i])
                    {
                        dif = v[j] - v[i] ; 
                        l = v[i]  , r=v[j] ;
                    }
                    tm = v[j] ;
                    if(j==n-1){
                        i=n; 
                    }
                }
                else if(mp[v[j]]>=k)
                {
                    i = j-1 ; 
                    break;
                }
                else 
                {
                    i = j ; 
                    break;
                }
            }
        }
    }
    if(dif == -1) cout << -1 << endl ;
    else cout << l << ' ' << r << endl ; 
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