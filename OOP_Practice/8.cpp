#include<bits/stdc++.h>
using namespace std;

class IntegerFactory
{
    int array[10005];
    public:
    void get_input(int n)
    {
        for(int i=0;i<n;i++)
        {
            cin >> array[i];
        }
    }

    void even_sum(int n)
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(array[i]%2==0) res+=array[i];
        }
        cout << res << endl;
    }
    void odd_sum(int n)
    {
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(array[i]%2) res+=array[i];
        }

        cout << res << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    IntegerFactory a;
    a.get_input(n);
    int c;
    cin >> c;
    if(c==0)
    {
        a.odd_sum(n);
    }
    else a.even_sum(n);
}