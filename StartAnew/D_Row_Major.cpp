#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    if(n==1)
    {
        cout << "a\n"; 
    }
    else if(n==2)
    {
        cout << "ab\n"; 
    }
    else if(n%2==1)
    {
        for(int i=1;i<=n; i++)
        {
            if(i%2) cout << "a"; 
            else cout << "b";
        }
        cout << endl; 
    }
    else 
    {
        ll ix = -1; 
        for(int i = 3;i<=26; i++)
        {
            if(n%i!=0)
            {
                ix = i; 
                break;
            }
        }
        string s; 
        for(int i=0;i<ix; i++) s.push_back('a'+i); 
        for(int j=0, i=0;j<n;j++)
        {
            cout << s[i]; 
            i++; 
            if(i==(int)s.size()) i = 0; 
        }
        cout << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}