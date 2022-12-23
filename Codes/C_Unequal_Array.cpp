#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n ; 
    cin >> n ;
    vector<int> v(n) ; 
    for(auto &i: v) cin >> i ; 
    int f = -1 , s = -1 ; 
    for(int i=0;i<n-1;i++)
    {
        if(v[i]==v[i+1])
        {
            f= i ;
            break;
        }
    }
    for(int i=n-1; i>0 ;i--)
    {
        if(v[i]==v[i-1])
        {
            s = i ;
            break; 
        }
    }
    if(f==-1) cout << "0\n" ; 
    else 
    {
        int x = s-f +1; 
        if(x<=3) cout << x-3+1 << endl; 
        else cout << x-3 << endl ;
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