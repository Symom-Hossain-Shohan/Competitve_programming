#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v; 
ll output[10000005]; 

ll getMax()
{
    return *max_element(v.begin(), v.end()); 
}

void countingSort(ll size, ll place)
{
    const ll max = 10; 
    ll count[max];

    for(ll i=0;i<max; i++)
    {
        count[i] = 0; 
    }
    for(ll i=0;i<size; i++) count[(v[i]/place)%10]++; 
    for(ll i=1;i<max; i++) count[i] += count[i-1]; 

    for(ll i=size-1; i>=0; i--)
    {
        output[count[(v[i]/place)%10]-1] = v[i]; 
        count[(v[i]/place)%10]--; 
    }

    for(ll i=0;i<size; i++) v[i] = output[i];
}

void radixsort(int size)
{
    ll max = (getMax()); 
    for(ll place = 1; max/place>0; place*=10) countingSort(size, place); 
}

void printArray()
{
    for(auto i: v) cout << i << ' '; 
    cout << endl; 
}


void solve()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("output.txt", "r", stdin);
    freopen("input.txt", "w", stdout);

    ll n;
    n = 1000000; 
    //cin >> n; 
    //vector<ll> v; 
    v.clear();
    ll mn = 0; 
    ll x  = 1e18; 

    for(int i=0;i<n; i++, x--)
    {
        //ll x; 
        cin >> x; 
        v.push_back(x);
        //mn = min(mn, x);
    }
    //for(int i=0;i<n; i++) v[i] += (mn)*(-1); 

    radixsort(n);
    //printArray();
    //for(int i=0;i<n; i++) v[i] += mn; 
    //cout <<max(v[0]*v[1], v[n-1]*v[n-2]) << endl; 
    cerr << (clock()*1.0)/CLOCKS_PER_SEC << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 

    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}