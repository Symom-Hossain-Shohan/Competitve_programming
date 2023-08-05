#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct Process
{
    int processNumber;
    int arrivalTime;
    int burstTime;
    int remainingBurstTime;
    int priority;
    int responseTime;
    int waitingTime;
    int turnaroundTime;
    int startTime;
    int endTime;

};

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


bool sortByArrivalTime(const Process &p1, const Process &p2)
{
    return p1.arrivalTime < p2.arrivalTime;
}

bool accordingBT(const Process &p1, const Process &p2)
{
    return p1.remainingBurstTime < p2.remainingBurstTime;
}


bool compareProcessNo(const Process &p1, const Process &p2)
{
    return p1.processNumber < p2.processNumber;
}



// void owerOwn()

bool compareArrivalTime(const Process &p1, const Process &p2)
{
    return p1.arrivalTime < p2.arrivalTime;
}

bool compareBurstTime(const Process &p1, const Process &p2)
{
    return p1.burstTime < p2.burstTime;
}

bool compareRemainingTime(const Process &p1, const Process &p2)
{
    return p1.remainingBurstTime < p2.remainingBurstTime;
}

bool comparePriority(const Process &p1, const Process &p2)
{
    return p1.priority < p2.priority;
}

void first_come_first_serve(vector<Process> &processes, int flag = 0)
{
    int n = processes.size();
    int total_waitingTime = 0;
    int total_turnaroundTime = 0;
    int total_responseTime = 0;
    int current_time = 0;
    if (!flag)
    {
        cout << "Gantt Chart: ";
        cout << 0 << " ";
    }
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrivalTime > current_time)
        {
            current_time = processes[i].arrivalTime;
            if (!flag)
            {
                cout << "idle " << current_time << " ";
            }
        }

        processes[i].startTime = current_time;
        processes[i].endTime = current_time + processes[i].burstTime;
        processes[i].responseTime = current_time - processes[i].arrivalTime;
        processes[i].waitingTime = current_time - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].endTime - processes[i].arrivalTime;

        total_waitingTime += processes[i].waitingTime;
        total_turnaroundTime += processes[i].turnaroundTime;
        total_responseTime += processes[i].responseTime;

        current_time = processes[i].endTime;
        if (!flag)
        {
            cout << "P" << processes[i].processNumber << " " << current_time << " ";
        }
    }
    if (!flag)
    {

        cout << endl
             << endl;

        sort(processes.begin(), processes.end(), compareProcessNo);
        for (int i = 0; i < n; i++)
        {
            cout << "Process: P" << processes[i].processNumber << " ";
            cout << "Start Time: " << processes[i].startTime << " ";
            cout << "End Time: " << processes[i].endTime << " ";
            cout << "Response Time: " << processes[i].responseTime << " ";
            cout << "Waiting Time: " << processes[i].waitingTime << " ";
            cout << "Turnaround Time: " << processes[i].turnaroundTime << endl;
        }
        cout << endl;
    }

    double avg_waitingTime = (total_waitingTime * 1.0) / n;
    double avg_turnaroundTime = (total_turnaroundTime * 1.0) / n;
    double avg_responseTime = (total_responseTime * 1.0) / n;

    if (!flag)
    {
        cout << "Average Waiting Time: " << avg_waitingTime << endl;
        cout << "Average Turnaround Time: " << avg_turnaroundTime << endl;
        cout << "Average Response Time: " << avg_responseTime << endl;
        cout << endl;
    }
    if (flag)
    {
        cout << "Algo: FCFS                      "
             << "Avg. Response time: " << avg_responseTime << "\t"
             << "Avg. Waiting time: " << avg_waitingTime << "\t"
             << "Avg. Turnaround time: " << avg_turnaroundTime << endl;
    }
}

void non_preemptive_sjf(vector<Process> &processes, int flag = 0)
{
    int n = processes.size();
    int total_waitingTime = 0;
    int total_turnaroundTime = 0;
    int total_responseTime = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0, idle = 0;
    if (!flag)
    {
        cout << "Gantt Chart: ";
        cout << 0 << " ";
    }
    while (completed_processes_count < n)
    {
        while (idx < n && processes[idx].arrivalTime <= current_time)
        {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty())
        {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle)
        {
            if (!flag)
            {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), compareBurstTime);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        current_process.startTime = current_time;
        current_process.endTime = current_time + current_process.burstTime;
        current_process.responseTime = current_process.startTime - current_process.arrivalTime;
        current_process.waitingTime = current_process.startTime - current_process.arrivalTime;
        current_process.turnaroundTime = current_process.endTime - current_process.arrivalTime;

        total_waitingTime += current_process.waitingTime;
        total_turnaroundTime += current_process.turnaroundTime;
        total_responseTime += current_process.responseTime;

        completed_processes.push_back(current_process);
        current_time = current_process.endTime;
        completed_processes_count++;
        if (!flag)
        {
            cout << "P" << current_process.processNumber << " " << current_process.endTime << " ";
        }
    }
    if (!flag)
    {
        cout << endl
             << endl;

        sort(completed_processes.begin(), completed_processes.end(), compareProcessNo);
        for (int i = 0; i < n; i++)
        {
            cout << "Process: P" << completed_processes[i].processNumber << " ";
            cout << "Start Time: " << completed_processes[i].startTime << " ";
            cout << "End Time: " << completed_processes[i].endTime << " ";
            cout << "Response Time: " << completed_processes[i].responseTime << " ";
            cout << "Waiting Time: " << completed_processes[i].waitingTime << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaroundTime << endl;
        }
        cout << endl;
    }

    double avg_waitingTime = (total_waitingTime * 1.0) / n;
    double avg_turnaroundTime = (total_turnaroundTime * 1.0) / n;
    double avg_responseTime = (total_responseTime * 1.0) / n;

    if (!flag)
    {
        cout << "Average Waiting Time: " << avg_waitingTime << endl;
        cout << "Average Turnaround Time: " << avg_turnaroundTime << endl;
        cout << "Average Response Time: " << avg_responseTime << endl;
        cout << endl;
    }

    if (flag)
    {
        cout << "Algo: Non-Preemptive-SJF        "
             << "Avg. Response time: " << avg_responseTime << "\t"
             << "Avg. Waiting time: " << avg_waitingTime << "\t"
             << "Avg. Turnaround time: " << avg_turnaroundTime << endl;
    }
}

void preemptive_sjf(vector<Process> &processes, int flag = 0)
{
    int n = processes.size();
    int total_waitingTime = 0;
    int total_turnaroundTime = 0;
    int total_responseTime = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0, idle = 0;
    if (!flag)
    {
        cout << "Gantt Chart: ";
        cout << 0 << " ";
    }
    while (completed_processes_count < n)
    {
        while (idx < n && processes[idx].arrivalTime <= current_time)
        {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty())
        {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle)
        {
            if (!flag)
            {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), compareRemainingTime);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        if (current_process.responseTime == -1)
        {
            current_process.responseTime = current_time - current_process.arrivalTime;
            total_responseTime += current_process.responseTime;
            current_process.startTime = current_time;
        }

        current_time++;

        current_process.remainingBurstTime--;

        if (current_process.remainingBurstTime == 0)
        {
            current_process.endTime = current_time;
            current_process.waitingTime = current_time - current_process.arrivalTime - current_process.burstTime;
            total_waitingTime += current_process.waitingTime;
            current_process.turnaroundTime = current_process.endTime - current_process.arrivalTime;
            total_turnaroundTime += current_process.turnaroundTime;
            completed_processes_count++;
            completed_processes.push_back(current_process);
            if (!flag)
            {
                cout << "P" << current_process.processNumber << " " << current_process.endTime << " ";
            }
        }
        else
        {
            while (idx < n && processes[idx].arrivalTime <= current_time)
            {
                ready_queue.push_back(processes[idx]);
                idx++;
            }
            ready_queue.push_back(current_process);
            sort(ready_queue.begin(), ready_queue.end(), compareRemainingTime);
            if (ready_queue.front().processNumber != current_process.processNumber)
            {
                if (!flag)
                {
                    cout << "P" << current_process.processNumber << " " << current_time << " ";
                }
            }
        }
    }

    if (!flag)
    {
        cout << endl
             << endl;

        sort(completed_processes.begin(), completed_processes.end(), compareProcessNo);
        for (int i = 0; i < n; i++)
        {
            cout << "Process: P" << completed_processes[i].processNumber << " ";
            cout << "Start Time: " << completed_processes[i].startTime << " ";
            cout << "End Time: " << completed_processes[i].endTime << " ";
            cout << "Response Time: " << completed_processes[i].responseTime << " ";
            cout << "Waiting Time: " << completed_processes[i].waitingTime << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaroundTime << endl;
        }
        cout << endl;
    }

    double avg_waitingTime = (total_waitingTime * 1.0) / n;
    double avg_turnaroundTime = (total_turnaroundTime * 1.0) / n;
    double avg_responseTime = (total_responseTime * 1.0) / n;

    if (!flag)
    {
        cout << "Average Waiting Time: " << avg_waitingTime << endl;
        cout << "Average Turnaround Time: " << avg_turnaroundTime << endl;
        cout << "Average Response Time: " << avg_responseTime << endl;
        cout << endl;
    }

    if (flag)
    {
        cout << "Algo: Preemptive-SJF            "
             << "Avg. Response time: " << avg_responseTime << "\t"
             << "Avg. Waiting time: " << avg_waitingTime << "\t"
             << "Avg. Turnaround time: " << avg_turnaroundTime << endl;
    }
}

void non_preemptive_priority(vector<Process> &processes, int flag = 0)
{
    int n = processes.size();
    int total_waitingTime = 0;
    int total_turnaroundTime = 0;
    int total_responseTime = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0, idle = 0;
    if (!flag)
    {
        cout << "Gantt Chart:\n";
        cout << 0 << " ";
    }
    while (completed_processes_count < n)
    {
        while (idx < n && processes[idx].arrivalTime <= current_time)
        {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty())
        {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle)
        {
            if (!flag)
            {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), comparePriority);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        current_process.startTime = current_time;
        current_process.endTime = current_time + current_process.burstTime;
        current_process.waitingTime = current_process.startTime - current_process.arrivalTime;
        current_process.turnaroundTime = current_process.endTime - current_process.arrivalTime;
        current_process.responseTime = current_process.startTime - current_process.arrivalTime;

        total_waitingTime += current_process.waitingTime;
        total_turnaroundTime += current_process.turnaroundTime;
        total_responseTime += current_process.responseTime;

        completed_processes.push_back(current_process);
        current_time = current_process.endTime;
        completed_processes_count++;
        if (!flag)
        {
            cout << "P" << current_process.processNumber << " " << current_process.endTime << " ";
        }
    }
    if (!flag)
    {
        cout << endl
             << endl;

        sort(completed_processes.begin(), completed_processes.end(), compareProcessNo);
        for (int i = 0; i < n; i++)
        {
            cout << "Process: P" << completed_processes[i].processNumber << " ";
            cout << "Start Time: " << completed_processes[i].startTime << " ";
            cout << "End Time: " << completed_processes[i].endTime << " ";
            cout << "Response Time: " << completed_processes[i].responseTime << " ";
            cout << "Waiting Time: " << completed_processes[i].waitingTime << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaroundTime << endl;
        }
        cout << endl;
    }

    double avg_waitingTime = (total_waitingTime * 1.0) / n;
    double avg_turnaroundTime = (total_turnaroundTime * 1.0) / n;
    double avg_responseTime = (total_responseTime * 1.0) / n;

    if (!flag)
    {
        cout << "Average Waiting Time: " << avg_waitingTime << endl;
        cout << "Average Turnaround Time: " << avg_turnaroundTime << endl;
        cout << "Average Response Time: " << avg_responseTime << endl;
        cout << endl;
    }

    if (flag)
    {
        cout << "Algo: Non-Preemptive-Priority   "
             << "Avg. Response time: " << avg_responseTime << "\t"
             << "Avg. Waiting time: " << avg_waitingTime << "\t"
             << "Avg. Turnaround time: " << avg_turnaroundTime << endl;
    }
}

void preemptive_priority(vector<Process> &processes, int flag = 0)
{
    int n = processes.size();
    int total_waitingTime = 0;
    int total_turnaroundTime = 0;
    int total_responseTime = 0;
    int current_time = 0;

    sort(processes.begin(), processes.end(), compareArrivalTime);

    vector<Process> ready_queue;
    vector<Process> completed_processes;

    int completed_processes_count = 0;
    int idx = 0, idle = 0;
    if (!flag)
    {
        cout << "Gantt Chart:\n";
        cout << 0 << " ";
    }

    while (completed_processes_count < n)
    {
        while (idx < n && processes[idx].arrivalTime <= current_time)
        {
            ready_queue.push_back(processes[idx]);
            idx++;
        }

        if (ready_queue.empty())
        {
            idle = 1;
            current_time++;
            continue;
        }

        if (idle)
        {
            if (!flag)
            {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        sort(ready_queue.begin(), ready_queue.end(), comparePriority);

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        if (current_process.responseTime == -1)
        {
            current_process.responseTime = current_time - current_process.arrivalTime;
            total_responseTime += current_process.responseTime;
            current_process.startTime = current_time;
        }

        current_time++;

        current_process.remainingBurstTime--;

        if (current_process.remainingBurstTime == 0)
        {
            current_process.endTime = current_time;
            current_process.waitingTime = current_time - current_process.arrivalTime - current_process.burstTime;
            total_waitingTime += current_process.waitingTime;
            current_process.turnaroundTime = current_process.endTime - current_process.arrivalTime;
            total_turnaroundTime += current_process.turnaroundTime;
            completed_processes_count++;
            completed_processes.push_back(current_process);
            if (!flag)
            {
                cout << "P" << current_process.processNumber << " " << current_process.endTime << " ";
            }
        }
        else
        {
            while (idx < n && processes[idx].arrivalTime <= current_time)
            {
                ready_queue.push_back(processes[idx]);
                idx++;
            }
            ready_queue.push_back(current_process);
            sort(ready_queue.begin(), ready_queue.end(), comparePriority);
            if (ready_queue.front().processNumber != current_process.processNumber)
            {
                if (!flag)
                {
                    cout << "P" << current_process.processNumber << " " << current_time << " ";
                }
            }
        }
    }

    if (!flag)
    {
        cout << endl
             << endl;

        sort(completed_processes.begin(), completed_processes.end(), compareProcessNo);
        for (int i = 0; i < n; i++)
        {
            cout << "Process: P" << completed_processes[i].processNumber << " ";
            cout << "Start Time: " << completed_processes[i].startTime << " ";
            cout << "End Time: " << completed_processes[i].endTime << " ";
            cout << "Response Time: " << completed_processes[i].responseTime << " ";
            cout << "Waiting Time: " << completed_processes[i].waitingTime << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaroundTime << endl;
        }
        cout << endl;
    }

    double avg_waitingTime = (total_waitingTime * 1.0) / n;
    double avg_turnaroundTime = (total_turnaroundTime * 1.0) / n;
    double avg_responseTime = (total_responseTime * 1.0) / n;

    if (!flag)
    {
        cout << "Average Waiting Time: " << avg_waitingTime << endl;
        cout << "Average Turnaround Time: " << avg_turnaroundTime << endl;
        cout << "Average Response Time: " << avg_responseTime << endl;
        cout << endl;
    }

    if (flag)
    {
        cout << "Algo: Preemptive-Priority       "
             << "Avg. Response time: " << avg_responseTime << "\t"
             << "Avg. Waiting time: " << avg_waitingTime << "\t"
             << "Avg. Turnaround time: " << avg_turnaroundTime << endl;
    }
}

void round_robin(vector<Process> &processes, int time_quantum, int flag = 0)
{
    int n = processes.size();
    vector<Process> ready_queue;
    vector<Process> completed_processes;
    int current_time = 0;
    int total_waitingTime = 0;
    int total_turnaroundTime = 0;
    int total_responseTime = 0;

    if (!flag)
    {
        cout << "Gantt Chart:\n";
        cout << 0 << " ";
    }
    int idle = 0;

    while (!processes.empty() || !ready_queue.empty())
    {
        // Check for newly arrived processes
        while (!processes.empty() && processes.front().arrivalTime <= current_time)
        {
            ready_queue.push_back(processes.front());
            processes.erase(processes.begin());
        }

        if (ready_queue.empty())
        {
            current_time++;
            idle = 1;
            continue;
        }

        if (idle)
        {
            if (!flag)
            {
                cout << "idle " << current_time << " ";
            }
            idle = 0;
        }

        Process current_process = ready_queue.front();
        ready_queue.erase(ready_queue.begin());

        if (current_process.responseTime == -1)
        {
            current_process.responseTime = current_time - current_process.arrivalTime;
            total_responseTime += current_process.responseTime;
            current_process.startTime = current_time;
        }

        int execution_time = min(time_quantum, current_process.remainingBurstTime);
        current_process.remainingBurstTime -= execution_time;
        current_time += execution_time;

        if (!flag)
        {
            cout << "P" << current_process.processNumber << " " << current_time << " ";
        }

        if (current_process.remainingBurstTime == 0)
        {
            current_process.waitingTime = current_time - current_process.arrivalTime - current_process.burstTime;
            current_process.turnaroundTime = current_time - current_process.arrivalTime;
            total_waitingTime += current_process.waitingTime;
            total_turnaroundTime += current_process.turnaroundTime;
            current_process.endTime = current_time;
            completed_processes.push_back(current_process);
        }
        else
        {
            while (!processes.empty() && processes.front().arrivalTime <= current_time)
            {
                ready_queue.push_back(processes.front());
                processes.erase(processes.begin());
            }
            ready_queue.push_back(current_process);
        }
    }

    if (!flag)
    {
        cout << endl
             << endl;

        sort(completed_processes.begin(), completed_processes.end(), compareProcessNo);
        for (int i = 0; i < n; i++)
        {
            cout << "Process: P" << completed_processes[i].processNumber << " ";
            cout << "Start Time: " << completed_processes[i].startTime << " ";
            cout << "End Time: " << completed_processes[i].endTime << " ";
            cout << "Response Time: " << completed_processes[i].responseTime << " ";
            cout << "Waiting Time: " << completed_processes[i].waitingTime << " ";
            cout << "Turnaround Time: " << completed_processes[i].turnaroundTime << endl;
        }
        cout << endl;
    }

    double avg_waitingTime = (total_waitingTime * 1.0) / n;
    double avg_turnaroundTime = (total_turnaroundTime * 1.0) / n;
    double avg_responseTime = (total_responseTime * 1.0) / n;

    if (!flag)
    {
        cout << "Average Waiting Time: " << avg_waitingTime << endl;
        cout << "Average Turnaround Time: " << avg_turnaroundTime << endl;
        cout << "Average Response Time: " << avg_responseTime << endl;
        cout << endl;
    }

    if (flag)
    {
        cout << "Algo: Round-Robin               "
             << "Avg. Response time: " << avg_responseTime << "\t"
             << "Avg. Waiting time: " << avg_waitingTime << "\t"
             << "Avg. Turnaround time: " << avg_turnaroundTime << endl;
    }
}



void ower_own(vector<Process> processes, int flag)
{
    int numProcesses = processes.size(); 

    for (int i = 0; i < numProcesses; ++i)
    {
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
                if(!flag) cout << currentTime << ' '; 
                if(!flag) cout << "P" << processes[q[0].second].processNumber << ' '; 
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
                if(!flag) cout << currentTime+x << ' '; 
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

    
    if(!flag)
    {
        cout << "Average Waiting Time: " << totalWait/numProcesses << endl;
        cout << "Average Turnaround Time: " << totalTurnaround/numProcesses << endl;
        cout << "Average Response Time: " << avgresponse/numProcesses << endl;
        cout << endl;
    }

    if(flag)
    {
        cout << "Algo: Our-Own-Algorithm          "
             << "Avg. Response time: " << avgresponse/numProcesses << "\t"
             << "Avg. Waiting time: " << totalWait/numProcesses << "\t"
             << "Avg. Turnaround time: " << totalTurnaround/numProcesses << endl;
    }

}

int main()
{
    while (1)
    {
        cout << "1: FCFS" << endl;
        cout << "2: Non-Preemptive-SJF" << endl;
        cout << "3: Preemptive-SJF" << endl;
        cout << "4: Non-Preemptive-Priority" << endl;
        cout << "5: Preemptive-Priority" << endl;
        cout << "6: Round-Robin" << endl;
        cout << "7: Your-Own-Algorithm" << endl;
        cout << "8: Compare-All" << endl;
        cout << endl;
        cout << "Input your choice: ";
        int choice;
        cin >> choice;
        cout << endl;

        if (choice == 1 || choice == 2 || choice == 3)
        {
            int n, p_no, b_time, a_time, r_time;
            vector<Process> processes;

            cout << "Number of process, n: ";
            cin >> n;
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                p_no = i;
                cout << "Enter the burst time of P" << i << ": ";
                cin >> b_time;
                cout << "Enter the arrival time of P" << i << ": ";
                cin >> a_time;
                r_time = b_time;
                processes.push_back({p_no, a_time, b_time, r_time, -1, -1, -1, -1, -1, -1});
                cout << endl;
            }
            sort(processes.begin(), processes.end(), compareArrivalTime);
            if (choice == 1)
            {
                first_come_first_serve(processes);
            }
            else if (choice == 2)
            {
                non_preemptive_sjf(processes);
            }
            else if (choice == 3)
            {
                preemptive_sjf(processes);
            }
        }
        else if (choice == 4 || choice == 5)
        {
            int n, p_no, b_time, a_time, r_time, priority;
            vector<Process> processes;

            cout << "Number of process, n: ";
            cin >> n;
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                p_no = i;
                cout << "Enter the burst time of P" << i << ": ";
                cin >> b_time;
                cout << "Enter the arrival time of P" << i << ": ";
                cin >> a_time;
                cout << "Enter the priority of P" << i << ": ";
                cin >> priority;
                r_time = b_time;
                processes.push_back({p_no, a_time, b_time, r_time, priority, -1, -1, -1, -1, -1});
                cout << endl;
            }
            sort(processes.begin(), processes.end(), compareArrivalTime);
            if (choice == 4)
            {
                non_preemptive_priority(processes);
            }
            else if (choice == 5)
            {
                preemptive_priority(processes);
            }
        }
        else if (choice == 6)
        {
            int n, p_no, b_time, a_time, r_time, time_quantum;
            vector<Process> processes;

            cout << "Number of process, n: ";
            cin >> n;
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                p_no = i;
                cout << "Enter the burst time of P" << i << ": ";
                cin >> b_time;
                cout << "Enter the arrival time of P" << i << ": ";
                cin >> a_time;
                r_time = b_time;
                processes.push_back({p_no, a_time, b_time, r_time, -1, -1, -1, -1, -1, -1});
                cout << endl;
            }
            cout << "Time Quantum: ";
            cin >> time_quantum;
            cout << endl;
            sort(processes.begin(), processes.end(), compareArrivalTime);
            round_robin(processes, time_quantum);
        }
        else if (choice == 7)
        {
            int n, p_no, b_time, a_time, r_time, time_quantum;
            vector<Process> processes;

            cout << "Number of process, n: ";
            cin >> n;
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                p_no = i;
                cout << "Enter the burst time of P" << i << ": ";
                cin >> b_time;
                cout << "Enter the arrival time of P" << i << ": ";
                cin >> a_time;
                r_time = b_time;
                processes.push_back({p_no, a_time, b_time, r_time, -1, -1, -1, -1, -1, -1});
                cout << endl;
            }
            // cout << "Time Quantum: ";
            // cin >> time_quantum;
            cout << endl;
            sort(processes.begin(), processes.end(), sortByArrivalTime);
            ower_own(processes, time_quantum);
        }
        else if (choice == 8)
        {
            int n, p_no, b_time, a_time, r_time, priority, time_quantum;
            vector<Process> processes;

            cout << "Number of process, n: ";
            cin >> n;
            cout << endl;
            for (int i = 1; i <= n; i++)
            {
                p_no = i;
                cout << "Enter the burst time of P" << i << ": ";
                cin >> b_time;
                cout << "Enter the arrival time of P" << i << ": ";
                cin >> a_time;
                cout << "Enter the priority of P" << i << ": ";
                cin >> priority;
                r_time = b_time;
                processes.push_back({p_no, a_time, b_time, r_time, priority, -1, -1, -1, -1, -1});
                cout << endl;
            }
            cout << "Time Quantum: ";
            cin >> time_quantum;
            cout << endl;
            sort(processes.begin(), processes.end(), compareArrivalTime);

            vector<Process> n_processes = processes;
            first_come_first_serve(n_processes, 1);

            n_processes = processes;
            non_preemptive_sjf(n_processes, 1);

            n_processes = processes;
            preemptive_sjf(n_processes, 1);

            n_processes = processes;
            non_preemptive_priority(n_processes, 1);

            n_processes = processes;
            preemptive_priority(n_processes, 1);

            n_processes = processes;
            round_robin(n_processes, time_quantum, 1);

            n_processes = processes;
            sort(n_processes.begin(), n_processes.end(), sortByArrivalTime);
            ower_own(n_processes, 1);
            cout << endl;
        }
        else if (choice == 9)
        {
            cout << "Program Terminated" << endl;
            break;
        }
    }
    return 0;
}
