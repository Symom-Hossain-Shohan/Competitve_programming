#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; 
    cin >> n; 
    //cout << n << " hay hay\n";
    

    vector<ll> a, b; 
    for(int i=0;i<n;i++)
    {
        ll x; 
        cin >> x; 
        if(x<0) a.push_back(x);
        else b.push_back(x);
    }
    if(n==1)
    {
        //cout << "Kire\n";
        cout << "No\n";
        return; 
    }

    sort(a.rbegin(), a.rend()); 
    sort(b.begin(), b.end()); 

    list<ll> pos, neg; 
    for(int i=0;i<(int)a.size(); i++) neg.push_back(a[i]);
    for(int i=0;i<(int)b.size();i++) pos.push_back(b[i]);

    a.clear();
    ll tmp = pos.back()-neg.front();
    a.push_back(pos.back()); 
    pos.pop_back();
    ll sum = a[0];
    while(!neg.empty() and !pos.empty())
    {
        
        if(sum+pos.back()<tmp)
        {
            a.push_back(pos.back()); 
            sum += pos.back(); 
            pos.pop_back();
        }
        else if(sum+pos.front()<tmp)
        {
            a.push_back(pos.front()); 
            sum += pos.front();
            pos.pop_front();
        }
        else 
        {
            
                //sum = 0; 
                sum += neg.back();
                a.push_back(neg.back());
                neg.pop_back();
            
        }
    }

    if(neg.empty() and !pos.empty())
    {
        ll sum = a.back();
        while(sum+pos.back()<tmp and !pos.empty())
        {
            sum += pos.back();
            a.push_back(pos.back()); 
            pos.pop_back();
        }

        if(!pos.empty())
        {
            cout << "No\n";
            
        }
        else 
        {
            cout << "Yes\n";
            for(auto i: a) cout << i << ' ';
            cout << endl; 
        }
    }
    else if(pos.empty() and !neg.empty())
    {
        while(!neg.empty()) a.push_back(neg.back()), neg.pop_back();

        cout << "Yes\n";
        for(auto i: a) cout << i << ' ';
        cout << endl; 
    }


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