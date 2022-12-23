#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        ll n;
        cin >> n;
        char s[n][n];
        int cnt=0;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                cin >> s[i][j];
                if(s[i][j]=='1') cnt++;  
            }
        }

        ll ans=1e18;
        for(int i=0;i<n;i++)
        {
            int j,k=0;
            ll a=0;
            for(j=i;j<n;j++,k++)
            {
                if(s[k][j]=='1') a++;
            }
            for(j=0;j<i;j++,k++) if(s[k][j]=='1') a++; 
            ans=min(ans,(cnt+n-2*a));
        }

        cout << ans << endl;

        
        
    }
    return 0;
}