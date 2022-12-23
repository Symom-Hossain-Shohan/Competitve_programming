#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll r, c ;
    cin >> r >> c ; 
    ll mtx [r][c] ; 
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) cin >> mtx[i][j] ; 
    }
    ll ans = -1e15 ;

    for(int i = 0;i<r;i++)
    {
         
        for(int j=0;j<c;j++)
        {
            ll cnt = 0;
            cnt += mtx[i][j] ; 
            int a = i, b=j ; 
            while(a>=0 and b>=0 and a<r and b<c)
            {
                if(!(a==i and b==j))
                {
                    cnt += mtx[a][b] ; 
                }
                a--, b-- ; 
            }
            a = i, b=j ;
            while(a>=0 and b>=0 and a<r and b<c)
            {
                if(!(a==i and b==j))
                {
                    cnt += mtx[a][b] ; 
                }
                a++,b++;
            }
            a = i, b=j ;
            while(a>=0 and b>=0 and a<r and b<c)
            {
                if(!(a==i and b==j))
                {
                    cnt += mtx[a][b] ; 
                }
                a++,b--; 
            }
            a = i, b=j ;
            while(a>=0 and b>=0 and a<r and b<c)
            {
                if(!(a==i and b==j))
                {
                    cnt += mtx[a][b] ; 
                }
                a--,b++;
            }
            ans = max(ans, cnt) ;
        }
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