#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> a;
    for (auto &i : v)
    {
        cin >> i;
        a[i]++;
    }

    bool ok = true;
    ll cnt = n;
    for (int i = n; i > 0 and cnt; i--)
    {
        if ((a[i] == 0 and i<=cnt) or a[i]>2)
        {
            ok = false;
            break;
        }
        else
            cnt -= a[i];
    }
    if (ok)
    {
        cout << "YES\n";
        int ar[n] = {0}, br[n] = {0};

        map<ll, ll> b;

        a.clear();

        for (int i = 0; i < n; i++)
        {
            if (a[v[i]] == 0)
            {
                a[v[i]]++;
                ar[i] = v[i];
            }
            else 
            {
                b[v[i]]++; 
                br[i] = v[i];
            }
        }

        priority_queue<ll> avail; 
        priority_queue<pair<ll,ll>> option; 
        for(int i = 1;i<=n;i++) if(a[i]==0) avail.push(i);
        for(int i = 0;i<n;i++)
        {
            if(ar[i]==0)
            {
                option.push({br[i],i});
            }
        }

        while((!avail.empty()) and (!option.empty()))
        {
            ar[option.top().second] = avail.top();
            option.pop();
            avail.pop();
        }

        avail = priority_queue<ll> ();
        option = priority_queue<pair<ll,ll>> ();

        for(int i = 1;i<=n;i++)
        {
            if(b[i]==0) avail.push(i);
        }
        for(int i=0;i<n;i++)
        {
            if(br[i]==0)
            {
                option.push({ar[i],i}); 
            }
        }

        while((!avail.empty()) and (!option.empty()))
        {
            br[option.top().second] = avail.top();
            option.pop();
            avail.pop();
        }

        for(int i=0;i<n;i++) cout << ar[i] << ' ';
        cout << endl; 
        for(auto i: br) cout << i << ' '; 
        cout << endl; 
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}