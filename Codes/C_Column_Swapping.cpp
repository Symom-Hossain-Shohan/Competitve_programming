#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int r, c ;
    cin >> r >> c ;
    int mtx [r][c]; 
    vector<int> v[r];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) 
        {
            cin >> mtx[i][j];
            v[i].push_back(mtx[i][j]);
        }
    }
    for(int i=0;i<r;i++) sort(v[i].begin(), v[i].end());

    vector<pair<int, int>> pos ; 
    bool ok = true ;
    for(int i=0;i<r;i++)
    {
        vector<int> tm; 
        for(int j=0;j<c;j++)
        {
            if(mtx[i][j]!=v[i][j]) tm.push_back(j);
        }

        if(tm.size()>2)
        {
            ok = false ;
            break;
        }
        else 
        {
            if(tm.size()==2) pos.push_back({tm[0], tm[1]});
        }
    }

    

    for(auto i: pos)
    {
        if(i!=pos[0]) 
        {
            ok =false;
            break;
        }
    }

    if(ok)
    {
        if(pos.empty()) 
        {
            cout << "1 1\n";
            return;
        }
        int one = pos[0].first , two = pos[0].second; 
        for(int i=0;i<r;i++)
        {
            swap(mtx[i][one], mtx[i][two]);
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mtx[i][j]!=v[i][j])
                {
                    cout << -1 << endl; 
                    return;
                }
            }
        }

        cout << one+1 << ' ' << two+1 << endl;
        
    } 
    else cout << -1 << endl; 

    
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