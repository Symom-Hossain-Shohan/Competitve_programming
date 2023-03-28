#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,m; 
    cin >>  n >> m; 
    vector<string> spot, nspot; 
    for(int i=0;i<n;i++) 
    {
        string s; 
        cin >> s; 
        spot.push_back(s); 
    }

    for(int i=0;i<n;i++)
    {
        string s; 
        cin >> s; 
        nspot.push_back(s); 
    }

    ll ans =0; 
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            for(int k=j+1; k<m;k++)
            {
                set<string> a, b, c; 
                int mp[1000] ={0}; 
                for(int x=0;x<n;x++)
                {
                     
                    ll num = 0; 
                    if(spot[x][i]=='A') num += 1; 
                    else if(spot[x][i]=='C') num+=2; 
                    else if(spot[x][i]=='G') num+=3; 
                    else if(spot[x][i]=='T') num+=4; 

                    if(spot[x][j]=='A') num = num*10+ 1; 
                    else if(spot[x][j]=='C') num = num*10+ 2; 
                    else if(spot[x][j]=='G')num = num*10+ 3; 
                    else if(spot[x][j]=='T')num = num*10+ 4; 

                    if(spot[x][k]=='A') num = num*10+ 1;
                    else if(spot[x][k]=='C') num = num*10+ 2;
                    else if(spot[x][k]=='G') num = num*10+ 3; 
                    else if(spot[x][k]=='T') num = num*10+ 4;

                    if(mp[num]==0) mp[num]++; 

                }
                bool ok = true; 
                for(int x=0;x<n;x++)
                {
                     
                    ll num = 0; 
                    if(nspot[x][i]=='A') num += 1; 
                    else if(nspot[x][i]=='C') num+=2; 
                    else if(nspot[x][i]=='G') num+=3; 
                    else if(nspot[x][i]=='T') num+=4; 

                    if(nspot[x][j]=='A') num = num*10+ 1; 
                    else if(nspot[x][j]=='C') num = num*10+ 2; 
                    else if(nspot[x][j]=='G')num = num*10+ 3; 
                    else if(nspot[x][j]=='T')num = num*10+ 4; 

                    if(nspot[x][k]=='A') num = num*10+ 1;
                    else if(nspot[x][k]=='C') num = num*10+ 2;
                    else if(nspot[x][k]=='G') num = num*10+ 3; 
                    else if(nspot[x][k]=='T') num = num*10+ 4;

                    if(mp[num]==1) ok= false;  

                }

                //set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin())); 
                if(ok) ans++; 
            }
        }
    }

    cout << ans << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}