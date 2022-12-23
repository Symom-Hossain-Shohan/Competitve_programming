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
        string s;
        cin >> s;
        ll ans=0;

        for(int i=0;i<n;i++)
        {
            ll plus=0,minus=0,pair=0,cnt=0;
            for(int j=i;j<n;j++)
            {
                if(s[j]=='-') 
                {
                    cnt++,minus++;
                    if(cnt==2)
                    {
                        pair++;
                        cnt=0;
                    }
                }
                else 
                {
                    if(cnt==2) pair++;
                    cnt=0;
                    plus++;
                }
                if(plus==minus and plus!=0) ans++;
                if((minus-plus)>0 and (minus-plus)%3==0) ans+=1;
            }
            //cout << pair << endl;
           
        }
        cout << ans << endl;
    }

    return 0;
}