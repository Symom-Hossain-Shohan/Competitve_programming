#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n ;
    cin >> n ;
    vector<int> a(n) , b(n) ; 
    for(auto &i: a) cin >> i ;
    for(auto &i: b) cin >> i ;

    map<int,int> m ;
    int j = 0;
    bool ok = true ; 
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[j])
        {
            j++; 
            continue; 
        }


        if(i>0 and a[i-1]==b[j] and m[b[j]]>0) 
        {
            m[b[j]]--; 
            j++;
            i--;
        }
        else m[a[i]]++;
    }
    while (j<n and a[n-1]==b[j] and m[b[j]]>0)
    {
        m[b[j]]--;
        j++;
    }
    ok = (j==n) ;
    if(ok) cout << "YES\n" ; 
    else cout << "NO\n" ;
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