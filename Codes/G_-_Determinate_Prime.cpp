#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll const mx =  35005; 
vector<bool> is_prime(mx, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(2);
    for(int i=3; i*i<=  35000; i+=2)
    {
        if(is_prime[i])
        {
            for(int j = i*i; j<=  35000; j+= 2*i)
            {
                is_prime[j] = false; 
            }
        }
    }

    for(int i=3;i<= 35000;i+=2) if(is_prime[i]) primes.push_back(i); 
}

void solve()
{
    ll a, b; 
    while (cin >> a >> b)
    {
        if(a==0  and b==0) break;

        if(a>b) swap(a, b); 

        int i = 0; 

        while(primes[i]<a) i++;

        while(primes[i+2]<=b)
        {
            if(primes[i+2]-primes[i+1]== primes[i+1]-primes[i])
            {
                int st = i, end = i+2, d = primes[i+2]-primes[i+1]; 

                while(i+3<primes.size() and primes[i+3]-primes[i+2] == d)
                {
                    end++, i++; 
                }

                if(primes[end]<=b)
                {
                    if(st == 0 or primes[st]-primes[st-1]!=d)
                    {
                        for(int j = st; j<end; j++) cout << primes[j] << ' '; 
                        cout << primes[end] << endl; 
                    }
                    
                }
                else break;
            }
            i++; 
        } 

        
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    sieve();
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}