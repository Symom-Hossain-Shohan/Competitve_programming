#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<char> is_prime(100001,true);
vector<int> primes;

void sieve()
{
    primes.push_back(2);
    for(int i=3;i*i<=100000;i+=2)
    {
        if(is_prime[i])
        {
           
            for(int j=i*i;j<=100000;j+=i) is_prime[j]=false;
        }
    }
    for(int i=3;i<=100000;i+=2) if(is_prime[i]) primes.push_back(i);
}

void seg_sieve(ll L,ll R)
{
    if(L==1) L++;
    vector<char> prime_check(R-L+1,true);

    for(auto p: primes)
    {
        ll i=(L/p)*p;
        if(i<L) i+=p;
        for(;i<=R;i+=p)
        {
            if(i!=p) prime_check[i-L]=false;
        }

    }

    for(int i=0;i<R-L+1;i++) if(prime_check[i]) cout << i+L << endl;
}

int main()
{
    sieve();
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll L,R;
        cin >> L >> R ;
        seg_sieve(L,R);
        cout << endl;

    }
    return 0;
}