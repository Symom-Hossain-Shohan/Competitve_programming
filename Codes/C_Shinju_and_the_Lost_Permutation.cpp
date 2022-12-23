#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for(auto &i: v) cin >> i;
        if(count(v.begin(),v.end(),1)!=1) cout << "NO\n";
        else 
        {
            int r=find(v.begin(),v.end(),1)-v.begin();
            rotate(v.begin(),v.begin()+r,v.end()) ;
            bool ok=true;
            for(int i=1;i<n;i++) 
            {
                if(v[i]-v[i-1]>1) ok=false;
            }

            if(ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}