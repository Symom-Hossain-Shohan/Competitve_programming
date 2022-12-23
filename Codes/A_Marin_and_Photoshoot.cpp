#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll tc;
    cin >> tc ;
    while(tc--)
    {
        ll n ;
        cin >> n;
        string s;
        cin >> s;
        ll ans=0;
        vector<ll> zero ;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') zero.push_back(i);
        }
        //ll ans=0;
        for(int i=0;i<(int)zero.size()-1;i++)
        {
            if(zero[i+1]-zero[i]==1) ans+=2;
            else if(zero[i+1]-zero[i]==2) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}