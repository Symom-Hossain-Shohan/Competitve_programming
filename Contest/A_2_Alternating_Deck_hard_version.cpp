#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    ll aw = 1, ab = 0, bw=0, bb=0;

    ll sum = n;  
    ll cnt =0; 
    int j=2;
        
    for(int i=2;i<=sum and j<=sum;i++)
    {
        int x = j+i-1; 
        for(;j<=x and j<=sum;j++)
        {
            //cout << j << ' ';
            if(j%2==0)
            {
                if(cnt==0 or cnt==1)
                {
                    bb ++; 
                    
                }
                else ab++; 
            }
            else 
            {
                if(cnt==0 or cnt==1)
                {
                    bw ++; 
                }
                else aw++; 
            }
        }
        //cout << endl; 
        cnt++; 
        if(cnt==4) cnt = 0;  

    }

    cout << aw << ' ' << ab << ' ' << bw << ' ' << bb << endl; 
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