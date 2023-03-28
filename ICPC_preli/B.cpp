#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mx = 320001;

vector<bool> is_prime(mx, true);
vector<ll> primes;

void sieve()
{
    primes.push_back(2);
    for (int i = 3; i * i < mx; i += 2)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < mx; j += 2 * i)
                is_prime[j] = false;
        }
    }

    for (int i = 3; i < mx; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    // for alice
    map<ll, ll> ma;
    for (int i = 0; i < n; i++)
    {
        ll x = a[i];
        for (int j = 0; primes[j] * primes[j] <= x; j++)
        {
            if (x % primes[j] == 0)
            {
                ma[primes[j]] = 1;
                while (x % primes[j] == 0)
                    x /= primes[j];
            }
        }
        if (x != 1)
            ma[x] = 1;
    }

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        ll x = b[i];
        for (int j = 0; primes[j] * primes[j] <= x; j++)
        {
            if (x % primes[j] == 0)
            {
                if (ma[primes[j]] == 0)
                {
                    ok = false;
                    break;
                }
                while (x % primes[j] == 0)
                    x /= primes[j];
            }
        }

        if (x != 1 and ma[x] == 0)
            ok = false;
    }

    // bob chk

    ll gcd = a[0];
    for (int i = 1; i < n; i++)
        gcd = __gcd(gcd, a[i]);

    map<ll, ll> mpa, mpb, mgcd;

    ll x = a[0];
    for (int i = 0; primes[i] * primes[i] <= x; i++)
    {
        if (x % primes[i] == 0)
        {
            ll p = 0;
            while (x % primes[i] == 0)
            {
                p++;
                x /= primes[i];
            }

            mpa[primes[i]] = p;
        }
    }
    if (x != 0)
        mpa[x] = 1;

    x = gcd;
    for (int i = 0; primes[i] * primes[i] <= x; i++)
    {
        if (x % primes[i] == 0)
        {
            ll p = 0;
            while (x % primes[i] == 0)
            {
                p++;
                x /= primes[i];
            }

            mgcd[primes[i]] = p;
        }
    }
    if (x != 0)
        mgcd[x] = 1;

    x = b[0];
    for (int i = 0; primes[i] * primes[i] <= x; i++)
    {
        if (x % primes[i] == 0)
        {
            ll p = 0;
            while (x % primes[i] == 0)
            {
                p++;
                x /= primes[i];
            }

            mpb[primes[i]] = p;
        }
    }
    if (x != 0)
        mpb[x] = 1;

    ll gun = 1, vag = 1;

    // for(auto i: mpa)
    // {
    //     if(i.second>mpb[i.first] and gcd%i.first == 0) vag *= (i.first)*(i.second-mpb[i.first]);
    //     else if(i.second < mpb[i.first] and gcd%i.first ==0) gun *= i.first*(mpb[i.first]-i.second);

    // }

   
    bool ok2 = true;

    
    for(int i = 0;i<n;i++) 
    {
        while(a[i]%gcd==0 and gcd!=1) a[i]/=gcd; 
        while(b[i]%gcd==0 and gcd!=1) b[i]/=gcd; 
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i]) ok2 = false; 
    }
    if (ok)
        cout << "Yes ";
    else
        cout << "No ";

    if (ok2)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;

    sieve();
    // for(int i =0 ;i<20;i++) cout << primes[i] << endl;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}