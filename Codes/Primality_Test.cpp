#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(ll n)
{
    if(n==1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    ll tc;
    cin >> tc;
    while(tc--)
    {
        ll n;
        cin >> n;
        if(is_prime(n)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}