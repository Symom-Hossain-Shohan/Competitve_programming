#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll tc;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        ll r,c;
        cin >> r >> c ;
        cout << "Case #" << t << ":\n";
        for(int i=0;i<=2*r;i++)
        {
            for(int j=0;j<=2*c;j++)
            {
                if((i==0 or i==1) and (j==0 or j==1)) cout << ".";
                else 
                {
                    if(i%2==0)
                    {
                        if(j%2==0)cout << "+";
                        else cout << "-";
                    }
                    else 
                    {
                        if(j%2==0) cout << "|";
                        else cout << ".";
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}