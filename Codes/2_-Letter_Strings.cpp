#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>> n; 
    map<string,ll> mp ; 
    for(int i=0;i<n;i++)
    {
        string s; 
        cin >> s ;
        mp[s]++;
    }
    ll ans=0 ;
    vector<string> v ;
    for(char i='a';i<='k';i++)
    {
        for(char j='a';j<='k';j++)
        {
            string a; 
            a.push_back(i) ; 
            a.push_back(j) ; 
            v.push_back(a);
        }
    }
    for(auto i: v) 
    {
        cout << i<< endl; 
    }

    for(int i=0;i<(int)v.size();i++)
    {
        for(int j=0;j<(int)v.size();j++)
        {
            if(v[i]!=v[j])
            {
                if(v[i][0]==v[j][0] or v[i][0]==v[j][1] or v[i][1]==v[j][0] or v[i][1]==v[j][1])
                {
                    ans+= mp[v[j]]*mp[v[i]];
                    //cout << v[i] << ' ' << v[j] << ' ' << mp[v[i]] << ' ' << mp[v[j]] << endl;
                }
            }
        }
        mp[v[i]]=0;
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