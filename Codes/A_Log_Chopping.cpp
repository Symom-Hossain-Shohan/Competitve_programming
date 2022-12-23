#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n ;
    cin >> n ;
    int non_one = 0 ; 
    int sum = 0 ; 
    for(int i = 0;i<n;i++)
    {
        int x ; 
        cin >> x ;
        sum += x ; 
    }
    sum -= n ;
    non_one = sum ;
    if(non_one%2) cout << "errorgorn\n" ; 
    else cout << "maomao90\n" ;
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