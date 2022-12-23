#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int r, c ;
    cin >> r >> c ; 

    char mtx[r][c] ;
    for(int i=0;i<r;i++) for(int j=0;j<c; j++) cin >> mtx[i][j] ;

    for(int j=0;j<c;j++)
    {
        for(int i = r-1;i>=0;i--)
        {
            if(mtx[i][j]=='o' or mtx[i][j]=='*') continue;
            else 
            {
                for(int k =i-1;k>=0;k--)
                {
                    if(mtx[k][j]=='*') 
                    {
                        swap(mtx[i][j],mtx[k][j]) ;
                        break;;
                    }
                    else if(mtx[k][j]=='o') 
                    {
                        i=k;
                        break;
                    }
                }
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout << mtx[i][j] ;
        }
        cout << endl ;
    }
    cout << endl ;

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