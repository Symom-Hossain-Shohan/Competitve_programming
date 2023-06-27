#include<bits/stdc++.h>

using namespace std;

class Batsman
{
    int batsman_code;
    string batsman_name;
    int total_innings,notout_innings,total_runs;
    double batting_avg;
    void calcavg()
    {
        batting_avg=total_runs/(total_innings-notout_innings);
    }

    public:
    void read_data()
    {
        cin >> batsman_code;
        getchar();
        getline(cin,batsman_name);
        cin >> total_innings>>notout_innings>> total_runs;
        calcavg();
    }

    void dispalyData()
    {
        cout << "Batsman code " << batsman_code << endl;
        cout << "Batsman Nmae " << batsman_name << endl;
        cout << "Total Innings " << total_innings << endl;
        cout << "Noutout Innigs " << notout_innings << endl;
        cout << "Total Runs " << total_runs << endl;
        cout << "Batting Avg " << batting_avg << endl;
    }
};

int main()
{
    Batsman smith;
    smith.read_data();
    smith.dispalyData();
}