#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n ;
    string s; 
    cin >> s ;
    int op = 0;
    int i;
    for(i=0;i<n-1;i++)
    {
        if(s[i]=='(')
        {
            op++, i++;
        }
        else
        {
            int j=i+1;
            for(;j<n;j++)
            {
                if(s[j]==')')
                {
                    i =j ;
                    op++;
                    break;
                }
            }
            if(j==n) break;
        }
    }

    cout << op << ' ' << n-i << endl; 
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