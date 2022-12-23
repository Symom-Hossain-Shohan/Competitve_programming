#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    int ar[11] ={0};
    for(int i=0;i<(int)s.size();i++) ar[s[i]-'0']++;

    for(int i=0;i<11;i++) 
    {
        if(ar[i]==0) 
        {
            cout << i << endl;
            break;;
        }
    }
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