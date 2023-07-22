#include <bits/stdc++.h>
using namespace std;

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

struct CompareProcess {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.remainingBurstTime > p2.remainingBurstTime;
    }
};



bool sortByArrivalTime(const Process &p1, const Process &p2)
{
    return p1.arrivalTime < p2.arrivalTime;
}

bool cmp(const Process &p1, const Process &p2)
{
    return p1.remainingBurstTime < p2.remainingBurstTime;
}


int main()
{
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;
    double exec[numProcesses+1]; 
    double arraival[numProcesses+1];

    vector<Process> processes(numProcesses);
    for (int i = 0; i < numProcesses; ++i)
    {
        processes[i].processNumber = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].remainingBurstTime = processes[i].burstTime;
        exec[i+1] = processes[i].burstTime; 
        arraival[i+1] = processes[i].arrivalTime;
    }

    sort(processes.begin(), processes.end(), sortByArrivalTime);

    // queue<Process> processQueue;//
    std::priority_queue<Process, std::vector<Process>, CompareProcess> processQueue;
    int currentTime = 0;
    int completedProcesses = 0;

    double sstart[numProcesses + 1]; 
    // memset(sstart, -1, sizeof(sstart)); 
    for(int i=0;i<=numProcesses; i++) sstart[i] = -1; 
    double eend[numProcesses + 1] = {0};

    vector<string> res;
    res.push_back("0");

    while (completedProcesses < numProcesses)
    {
        // Enqueue processes that have arrived
        vector<Process> tmp; 
        for (int i = 0; i < numProcesses; ++i)
        {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingBurstTime > 0)
            {
                processQueue.push(processes[i]);
                tmp.push_back(processes[i]); 

                processes[i].arrivalTime = INT_MAX; // Mark as processed
            }
        }

        // sort(tmp.begin(), tmp.end(), cmp); 

        // for(auto i: tmp) processQueue.push(i);

        if (!processQueue.empty())
        {
            // Calculate the mean and median of the remaining burst times
            int numRemainingProcesses = processQueue.size();
            int totalRemainingBurstTimes = 0;
            vector<int> remainingBurstTimes;
            std::priority_queue<Process, std::vector<Process>, CompareProcess> tempQueue = processQueue;

            // queue<Process> tempQueue = processQueue;
            while (!tempQueue.empty())
            {
                int remainingBurstTime = tempQueue.top().remainingBurstTime;
                if (remainingBurstTime > 0)
                {
                    remainingBurstTimes.push_back(remainingBurstTime);
                    totalRemainingBurstTimes += remainingBurstTime;
                }
                tempQueue.pop();
            }

            // Calculate the time quantum
            int mean = (numRemainingProcesses > 0) ? (totalRemainingBurstTimes / numRemainingProcesses) : 0;
            sort(remainingBurstTimes.begin(), remainingBurstTimes.end());
            int median = (numRemainingProcesses > 0) ? remainingBurstTimes[numRemainingProcesses / 2] : 0;
            int timeQuantum = max(1, static_cast<int>(sqrt(mean * median / 2)));

            Process currentProcess = processQueue.top();
            processQueue.pop();

            if (currentProcess.startTime == 0)
            {
                currentProcess.responseTime = currentTime - currentProcess.arrivalTime;
                currentProcess.startTime = currentTime;
            }

            int executedTime = min(timeQuantum, currentProcess.remainingBurstTime);
            if (executedTime != 0)
            {
                if (sstart[currentProcess.processNumber] == -1)
                    sstart[currentProcess.processNumber] = currentTime;
            }
            currentProcess.remainingBurstTime -= executedTime;
            currentTime += executedTime;

            if (executedTime != 0)
            {
                res.push_back(to_string(currentTime - executedTime));
            }

            if (currentProcess.remainingBurstTime <= 0)
            {
                currentProcess.endTime = currentTime;
                currentProcess.turnaroundTime = currentProcess.endTime - currentProcess.arrivalTime;
                currentProcess.waitingTime = currentProcess.turnaroundTime - currentProcess.burstTime;
                completedProcesses++;
            }
            else
            {
                processQueue.push(currentProcess);
            }

            cout << "Process " << currentProcess.processNumber << " executed for " << executedTime << " units of time." << endl;
            eend[currentProcess.processNumber] = currentTime;
            res.push_back("P" + to_string(currentProcess.processNumber));
            res.push_back(to_string(currentTime));
        }
        else
        {
            currentTime++;
        }
    }

    

    vector<string> newRes;
    newRes.push_back(res[0]);
    for (int i = 1; i < (int)res.size(); i++)
    {
        if (res[i] != newRes.back())
            newRes.push_back(res[i]);
    }
    for (auto i : newRes)
        cout << i << ' ';
    cout << endl;
    double ta[numProcesses+1], wa[numProcesses+1];

    for(int i=1;i<=numProcesses; i++)
    {
        ta[i] = eend[i] - sstart[i]; 
        wa[i] = sstart[i] - arraival[i]; 
        //cout << "ljdlfj  " << ta[i] << ' ' << exec[i] << endl; 
        //cout << exec[i] << 'a'<< endl; 
    }

    double avgWaiting  = 0, avgTa = 0, avgRes = 0; 
    for(int i=1;i<=numProcesses; i++) 
    {
        avgWaiting += wa[i], avgTa += ta[i], avgRes+=sstart[i];
        cout << "Process: " << i << " " << "Start time: " << sstart[i] << ' ' << "End time: " << eend[i] << ' ' << "Response time: " << sstart[i] << ' ' << "Waiting time: " << wa[i] << ' ' << "Turnaround time: " << ta[i] << endl; 
    }

    cout << "Average Waiting time: " << avgWaiting/numProcesses << endl; 
    cout << "Average Turnaround time: " << avgTa/numProcesses << endl; 
    cout << "Average Response time: " << avgRes/numProcesses << endl; 


 

    return 0;
}
