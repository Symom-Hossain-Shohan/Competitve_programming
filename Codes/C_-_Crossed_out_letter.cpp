#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string a, b; 
    cin >> a >> b; 
    int n = a.size();
    pair<int, int> f, s;  
    if(a==b)
    {
        cout << 'a' << a << endl;
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]==b[i+1])
            {
                f = {2, i};
            }
            else 
            {
                f = {1, i};
            }
            break;
        }
        
    }
    for(int i = n-1;i>0;i--)
    {
        if(a[i]!=b[i])
        {
            if(a[i]==b[i-1])
            {
                s = {2, i};
            }
            else 
            {
                s = {1, i};
            }
            break;
        }
    }
    
    if(f.first == s.first) cout << "IMPOSSIBLE\n";
    else 
    {   
        string c,d;
        if(f.first==1)
        {
             
            for(int i = 0;i<n;i++)
            {
                if(i==f.second) continue;
                c.push_back(a[i]);
            }
            for(int i = 0;i<n;i++)
            {
                if(i==s.second) continue;
                d.push_back(b[i]);
            }
        }
        else 
        {
            for(int i = 0;i<n;i++)
            {
                if(i==f.second) continue;
                d.push_back(a[i]);
            }
            for(int i=0;i<n;i++)
            {
                if(i==s.second) continue;
                c.push_back(b[i]);
            }
        }

        if(c==d)
        {
            if(f.first==2) swap(f, s);
            string ans; 
            //cout << a << endl << b << endl; 
            for(int i =0;i<n;i++)
            {
                if(i==s.second)
                {
                    ans.push_back(a[i]); 
                    ans.push_back(b[i]);
                    continue;
                }
                ans.push_back(a[i]);
            }
            cout << ans << endl; 
        }
        else 
        {
            //cout << 3 << endl ;
            cout << "IMPOSSIBLE\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}