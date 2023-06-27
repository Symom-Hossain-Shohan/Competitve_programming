#include<bits/stdc++.h>

using namespace std;

class parity
{
    int x;
    public:
    parity()
    {
        cin >> x;
    }
    friend void check_pairity(parity a);
    friend class chotobhai;
};


void check_pairity(parity a)
{
    if(a.x%2==0) cout << "Even\n";
    else cout << "Odd\n";
}

class chotobhai
{
    public:
    void choto_chk(parity a)
    {
        if(a.x %2==0) cout << "Even\n";
        else cout << "Odd\n";
    }
};

int main()
{
    parity a,b;
    check_pairity(a);
    chotobhai x;
    x.choto_chk(b);
    
}