// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// void solve()
// {
//     ll n; 
//     cin >> n; 
//     vector<ll> v(n);

//     for(auto &i: v) cin >> i; 

//     sort(v.begin(), v.end());

//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<10;j++)
//         {
//             if((v[i]&(1<<j)) and (v[n-1]&(1<<j)) == 0)
//             {
//                 v[i] = v[i] & (~(1<<j)); 
//                 v[n-1] = v[n-1] | (1<<j);
//                 //cout << "no\n";
//             }
            
//         }
//     }

//     sort(v.begin(), v.end()); 

//     for(int i=1;i<n-1;i++)
//     {
//         for(int j=0;j<10;j++)
//         {
//             if((v[0]&(1<<j)) and (v[i]&(1<<j))==0)
//             {
//                 v[0] = v[0] & (~(1<<j));
//                 v[i] = v[i] | (1<<j);
//             }
//         }
//     } 
//     cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()) << endl; 
// }

// int main()
// {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     ll tc = 1;
//     cin >> tc;
//     for (ll t = 1; t <= tc; t++)
//     {
//         solve();
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;

    vector<ll> v(n);

    for(auto &i: v) cin >> i; 

    ll mx = v[0], mn = v[0];

    for(int i=1;i<n;i++)
    {
        mx  |= v[i];
        mn &= v[i];
    }

    cout << mx - mn << endl; 
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