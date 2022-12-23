#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<bool> is_prime(1010, true);
vector<ll> primes; 

void sieve()
{
    primes.push_back(1);
    primes.push_back(2);

    for(int i = 3;i*i<=1001;i+=2)
    {
        if(is_prime[i])
        {
            for(int j = i*i; j<=1001; j+= 2*i) is_prime[j] = false; 
        }
    }

    for(int i=3;i<=1001;i+=2) if(is_prime[i]) primes.push_back(i);
}

void solve()
{
    
    int n,c;
    while(cin>>n>>c)
    {
        int cnt=0;
        for(int i=0;;i++)
        {
            if(primes[i]>n)break;
            cnt++;
        }
        int low,high;
        if(cnt%2==0)
        {
            low=cnt/2-c;
            high=low+2*c;
        }
        else
        {
            low=cnt/2-c+1;
            high=low+2*c-1;
        }
        if(low<0)
        {
            low=0;
        }
        if(high>cnt-1)
        {
            high=cnt;
        }
        cout << n << ' ' << c << ":"; 
        for(int i=low;i<high;i++)
        {
            cout<<" "<<primes[i];
        }
        cout<<endl<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    sieve();
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}