#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string a ;
    map<char,int> m ;
    vector<char> tm ;

    cin >> a ;
    for(int i=0;i<(int)a.size();i++)
    {
        if(m[a[i]]==0) 
        {
            tm.push_back(a[i]);
            m[a[i]]++;
        }
        else break;
    }
    bool ok = true ; 
    for(int i=0,j=0;i<(int)a.size();i++,j++)
    {
        if(j==tm.size()) j =0 ;
        if(a[i]!=tm[j]) 
        {
            ok =false;
        }
    }
    //cout << endl ;
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