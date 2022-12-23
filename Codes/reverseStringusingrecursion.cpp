#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v ; 

int  mn(vector<int> v) 
{
    if(v.size()==1) return v[0] ; 
    vector<int> a, b ; 
    int x = v.size() ; 
    a.assign(v.begin(),v.end()-1) ; 
    b.push_back(v[x-1]) ; 
    return min(mn(a), mn(b)) ; 
}

void solve()
{
    int n ;
    cin >> n ;
    for(int i=0;i<n;i++) 
    {
        int x ;
        cin >> x ; 
        v.push_back(x) ; 
    }
    cout << mn(v) << endl ; 
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