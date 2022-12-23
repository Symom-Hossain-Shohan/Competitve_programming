#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string text; 
    cin >> text; 

    vector<int> lps((int)text.size()); 

    int index = 0; 
    for(int i = 1;i<(int)text.size();)
    {
        if(text[index]==text[i])
        {
            lps[i] = index+1; 
            i++, index++; 
        }
        else 
        {
            if(index!=0) index = lps[index-1];
            else lps[i] = 0, i++; 
        }
    }
    for(auto i: lps) cout << i << ' '; 
    cout << endl; 
    /*
    if(lps[(int)text.size()-1]==0) cout << "Just a legend\n";
    else 
    {
        int n = text.size()-1;
        int x = lps[n];
        for(int i=n-1;i>=0;i--)
        {
            if(lps[i]==x) 
            {
                for(int j = 0;j<x;j++) 
                {
                    cout << text[j];
                }
                return;
            }
        }
        x = lps[x];
        if(x==0) cout << "Just a legend\n";
        else 
        {
            for(int i=0;i<x;i++) cout << text[i];
        }
    } 
    */
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