#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> pal;
ll mod = 1e9 + 7; 

ll cnt [500][40001]; 

ll dp(int pos, int n)
{
    if(n<0 ) return 0 ;  
    if(pos == (int) pal.size())
    {
        if(n==0) return 1; 
        else return 0 ; 
    }

    if(cnt[pos][n]!=-1) return cnt[pos][n];

    return cnt[pos][n] =  (dp(pos, n-pal[pos]) + dp(pos+1, n)) %mod; 
}

void solve()
{
    int n ;
    cin >> n; 
    cout << dp(0, n) % mod << endl; 
   
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc=1;
    cin >> tc;
    
    for(int v =1;v<=40000;v++)
    {
        
        vector<ll> a;
        int x = v; 
        while(x>0)
        {
            a.push_back(x%10);
            x/=10;
        }
        ll i,j;
        ll m=a.size();
        bool ok = true; 
        for(i=0,j=m-1;i<j;i++,j--)
        {
            if(a[i]!=a[j])
            {
                ok = false; 
            }
        }
        if(ok) pal.push_back(v); 
    }
    memset(cnt, -1, sizeof cnt); 

    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}