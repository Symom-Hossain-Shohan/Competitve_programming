#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Number of process, n: ";
    cin >> n;
    int burst_time[n+1], arrival_time[n+1];
    for(int i=1;i<=n; i++)
    {
        string s = "P" + to_string(i);
        cout << "Enter the burst time of " << s << ": ";
        cin >> burst_time[i];
        cout << "Enter the arrival time of " << s << ": ";
        cin >> arrival_time[i];
        cout << endl;
        cout << endl;
    }

    vector<pair<int, int>> v;
    for(int i=1;i<=n; i++)
    {
        v.push_back({arrival_time[i], i});
    }

    sort(v.begin(), v.end());

    cout << 0 << ' ';
    int t_last = 0;
    int waiting_time[n+1], turn_around_time[n+1], startTime[n+1];
    for(int i=0;i<n; i++)
    {
        cout << "P" << v[i].second << ' ';
        int ix = v[i].second;
        t_last = max(t_last, v[i].first);
        waiting_time[ix] = t_last - v[i].first;
        startTime[ix] = t_last;
        t_last += burst_time[ix];
        turn_around_time[ix] = t_last - v[i].first;
        cout << t_last << ' ';
    }
    cout << endl;
    double wait = 0, turn = 0;
    for(int i=0;i <n; i++)
    {
        int ix = v[i].second;
        cout << "Process: P" << ix << " Start time:  " << startTime[ix] << " Waiting time: " << waiting_time[ix] << " Turnaround time:  " << turn_around_time[ix] << endl;

        wait += waiting_time[ix];
        turn += turn_around_time[ix];
    }
    cout << endl;
    cout << "Average waiting time: " << wait/n << endl;
    cout << "Average turnaround time: " << turn/n << endl;
}
