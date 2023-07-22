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

    queue<Process> processQueue;
    int currentTime = 0;
    int completedProcesses = 0;
    cout << "Gantt Chart: \n"; 
    cout << 0 << ' ';

    while (completedProcesses < numProcesses)
    {
        vector<double> tqall;
        vector<Process> toExecute; 
        for (int i = 0; i < numProcesses; i++)
        {
            if (processes[i].arrivalTime <= currentTime)
            {
                // processQueue.push(processes[i]); 
                toExecute.push_back(processes[i]); 
                tqall.push_back(processes[i].remainingBurstTime);
            }
        }

        if (toExecute.empty())
        {
            cout << "idle ";
            currentTime++;
        }
        else
        {
            sort(tqall.begin(), tqall.end());

            double sum = 0;
            for (auto i : tqall)
                sum += i;
            double median;
            if (tqall.size() % 2 == 0)
            {
                median = (tqall[tqall.size() / 2] + tqall[tqall.size() / 2 - 1]) / 2;
            }
            else
            {
                median = tqall[tqall.size() / 2];
            }
            double avg = sum/(tqall.size()); 


            double tq = sqrt(avg*median/2.0); 
            tq = round(tq); 
            //cout << "tq " <<  tq << endl; 

            sort(toExecute.begin(), toExecute.end(), accordingBT); 

            for(auto i: toExecute) processQueue.push(i); 
            

            while(!processQueue.empty())
            {
                Process p = processQueue.front();
                processQueue.pop();

                ll x = min((ll)tq, (ll)p.remainingBurstTime); 

                for(int i=0;i<numProcesses; i++)
                {
                    if(processes[i].processNumber==p.processNumber)
                    {
                        if(processes[i].startTime==-1) processes[i].startTime = currentTime; 

                        processes[i].endTime = currentTime+x; 
                        processes[i].remainingBurstTime -= x; 
                        
                        if(currentTime!=0) cout << currentTime << ' '; 


                        cout << processes[i].processNumber << ' ' << currentTime+x << ' '; 


                        if(processes[i].remainingBurstTime==0) completedProcesses++; 
                        currentTime+=x; 
                    }
                }
            }


        }
    }
}