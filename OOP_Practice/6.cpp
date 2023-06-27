#include<bits/stdc++.h>
using namespace std;

class cmplx
{
    float real, img;
    public:
    void getData()
    {
        cin >> real >> img;
    }

    friend void sum_cmplx(cmplx a, cmplx b);
    friend class chotobhai;
    
};

void sum_cmplx(cmplx a, cmplx b)
{
    cout << a.real+b.real << ' ' ;
    if(b.img+a.img>=0) cout << "+ " << a.img + b.img << "i\n";
    else cout <<  a.img+b.img << "i\n";
}

class chotobhai
{
    public:
    void sum(cmplx a, cmplx b)
    {
        cout << a.real+b.real << ' ' ;
        if(b.img+a.img>=0) cout << "+ " << a.img + b.img << "i\n";
        else cout <<  a.img+b.img << "i\n";
    }
};


int main()
{
    cmplx a,b;
    a.getData();
    b.getData();

    cout << setprecision(2) << fixed;
    sum_cmplx(a,b);

    chotobhai c;
    c.sum(a,b);
}