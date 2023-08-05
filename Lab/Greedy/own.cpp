#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Process
{
    int processNumber;
    int arrivalTime;
    int burstTime;
    int remainingBurstTime;
    int startTime;
    int endTime;
    int responseTime;
    int waitingTime;
    int turnaroundTime;
};

bool sortByArrivalTime(const Process &p1, const Process &p2)
{
    return p1.arrivalTime < p2.arrivalTime;
}

bool accordingBT(const Process &p1, const Process &p2)
{
    return p1.remainingBurstTime < p2.remainingBurstTime;
}

ll timeQuantum(vector<pair<ll,ll>> q)
{
    double totalBurstTime = 0; 
    for(auto i: q) totalBurstTime += i.first; 
    double meanBurstTime = totalBurstTime/(double)q.size();
    double median; 
    if(q.size()%2==0)
    {
        median = (q[q.size()/2].first + q[q.size()/2-1].first)/2.0; 
    }
    else 
    {
        median = q[q.size()/2].first; 
    }

    double tq = sqrt(meanBurstTime*median/2.0); 
    return round(tq);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<Process> processes(numProcesses);
    
    for (int i = 0; i < numProcesses; ++i)
    {
        processes[i].processNumber = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].remainingBurstTime = processes[i].burstTime;
        processes[i].startTime = -1; 
    }

    sort(processes.begin(), processes.end(), sortByArrivalTime);

    ll currentTime = 0; 
    ll completedProcess = 0; 
    while(completedProcess<numProcesses)
    {
        vector<pair<ll,ll>> q; 
        for(int i=0;i<numProcesses; i++)
        {
            if(processes[i].remainingBurstTime>0 and processes[i].arrivalTime<=currentTime)
            {
                q.push_back({processes[i].remainingBurstTime, i}); 
            }
        }

        sort(q.begin(), q.end()); 

        if(q.empty())
        {
            currentTime++; 
        }
        else 
        {
            ll tq = timeQuantum(q);
            
            while(!q.empty())
            {
                if(processes[q[0].second].startTime==-1) processes[q[0].second].startTime = currentTime;
                cout << currentTime << ' '; 
                cout << "P" << processes[q[0].second].processNumber << ' '; 
                ll x = min(tq, q[0].first); 
                processes[q[0].second].endTime = currentTime;
                processes[q[0].second].remainingBurstTime -= x;
                if(processes[q[0].second].remainingBurstTime==0) completedProcess++;
                q.erase(q.begin()); 
                for(int i=0;i<numProcesses; i++)
                {
                    if(processes[i].arrivalTime>currentTime and processes[i].arrivalTime<=currentTime+x and processes[i].remainingBurstTime>0)
                    {
                        q.push_back({processes[i].remainingBurstTime, i}); 
                    }
                }

                sort(q.begin(), q.end()); 
                cout << currentTime+x << ' '; 
                currentTime+= x; 
                if(!q.empty())
                    tq = timeQuantum(q);
            }
        }
    }
    
    double totalTurnaround = 0, totalWait = 0, avgresponse = 0; 


    for(int i=0;i<numProcesses; i++)
    {
        processes[i].turnaroundTime = processes[i].endTime - processes[i].startTime; 
        processes[i].waitingTime = processes[i].turnaroundTime-processes[i].burstTime; 
        totalTurnaround += processes[i].turnaroundTime; 
        totalWait += processes[i].waitingTime; 
        avgresponse += processes[i].startTime-processes[i].arrivalTime; 
    }

    cout << "avg turn " << totalTurnaround/numProcesses << ' ' << totalWait/numProcesses  << endl; 
    cout << avgresponse/numProcesses << endl; 

    // for(i)
}