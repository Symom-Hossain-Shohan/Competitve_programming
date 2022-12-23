#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime[86028122];
vector<int> primes;

void sieve()
{
    memset(is_prime,1,sizeof(is_prime));
    for(ll i=3;i*i<=86028121;i+=2)
    {
        if(is_prime[i])
        {
            for(ll j=i*i;j<=86028121;j+=i) is_prime[j]=false;
        }
    }

    primes.push_back(2);
    for(int i=3;i<=86028121;i+=2) if(is_prime[i]) primes.push_back(i);

}


int main()
{
    sieve();
    ll tc;
    cin >> tc;

    while(tc--)
    {
        ll n;
        cin >> n;
        cout << primes[n-1] << endl;
    }
    return 0;
}