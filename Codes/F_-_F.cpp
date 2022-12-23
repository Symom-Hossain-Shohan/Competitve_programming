#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve()
{
    int n ;
    cin >> n ;
    vector<int> t(n), x(n), y(n) ; 
    for(int i=0;i<n;i++) cin >> t[i] >> x[i] >> y[i] ; 
    bool ok = true ; 
    int xx=0, yy=0; 
    int tt=0;
    for(int i=0;i<n;i++)
    {
        int dist = abs(xx-x[i])+abs(yy-y[i]); 
        int tim = t[i]-tt ;
        if(tim<dist) 
        {
            ok = false ;
            break;
        }
        else 
        {
            tim -= dist; 
            if(tim%2!=0)
            {
                ok = false ;
                break;
            }
        }

        xx = x[i], yy = y[i], tt = t[i] ;
    }

    if(ok) cout << "Yes\n" ; 
    else cout << "No\n" ; 
    
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