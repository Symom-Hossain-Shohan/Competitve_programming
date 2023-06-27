#include<bits/stdc++.h>
using namespace std;

class Play
{
    int playcode;
    string playtitle;
    float duration;
    int noofscene;
    public:
    Play()
    {
        duration=45;
        noofscene=5;
    }

    void newplay()
    {
        cin >> playcode ;
        getchar();
        getline(cin,playtitle);
    }

    void newinfo(double d, int nf)
    {
        duration=d;
        noofscene=nf;
    }

    void showplay()
    {
        cout << "Play Code: " << playcode << endl;
        cout << "Play Title: " << playtitle << endl;
        cout << "Duration: " <<duration << endl;
        cout << "Noofscences: " << noofscene << endl;
    }
};


int main()
{
    Play p;
    p.newplay();
    p.newinfo(20,2);
    p.showplay();
}