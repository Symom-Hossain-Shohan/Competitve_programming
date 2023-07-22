#include <bits/stdc++.h>
using namespace std;

struct Process {
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

bool sortByArrivalTime(const Process& p1, const Process& p2) {
}

int main() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<Process> processes(numProcesses);
    for (int i = 0; i < numProcesses; ++i) {
        processes[i].processNumber = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].remainingBurstTime = processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), sortByArrivalTime);

    queue<Process> processQueue;
    int currentTime = 0;
    int completedProcesses = 0;

    

    while (completedProcesses < numProcesses) {
        // Enqueue processes that have arrived
        for (int i = 0; i < numProcesses; ++i) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingBurstTime > 0) {
                processQueue.push(processes[i]);
                processes[i].arrivalTime = INT_MAX; // Mark as processed
            }
        }

        if (!processQueue.empty()) {
            // Calculate the mean and median of the remaining burst times
            int numRemainingProcesses = processQueue.size();
            int totalRemainingBurstTimes = 0;
            vector<int> remainingBurstTimes;

            queue<Process> tempQueue = processQueue;
            while (!tempQueue.empty()) {
                int remainingBurstTime = tempQueue.front().remainingBurstTime;
                if (remainingBurstTime > 0) {
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

            Process currentProcess = processQueue.front();
            processQueue.pop();

            if (currentProcess.startTime == 0) {
                currentProcess.responseTime = currentTime - currentProcess.arrivalTime;
                currentProcess.startTime = currentTime;
            }

            int executedTime = min(timeQuantum, currentProcess.remainingBurstTime);
            currentProcess.remainingBurstTime -= executedTime;
            currentTime += executedTime;

            if (currentProcess.remainingBurstTime <= 0) {
                currentProcess.endTime = currentTime;
                currentProcess.turnaroundTime = currentProcess.endTime - currentProcess.arrivalTime;
                currentProcess.waitingTime = currentProcess.turnaroundTime - currentProcess.burstTime;
                completedProcesses++;
            } else {
                processQueue.push(currentProcess);
            }

            cout << "Process " << currentProcess.processNumber << " executed for " << executedTime << " units of time." << endl;
        } else {
            currentTime++;
        }
    }

    cout << "\nGantt Chart:" << endl;
    for (const Process& p : processes) {
        cout << "P" << p.processNumber << " ";
    }
    cout << endl;

    float avgWaitingTime = 0.0;
    float avgTurnaroundTime = 0.0;
    float avgResponseTime = 0.0;

    for (const Process& p : processes) {
        cout << "Process: P" << p.processNumber
             << " Start time: " << p.startTime
             << " End time: " << p.endTime
             << " Response Time: " << p.responseTime
             << " Waiting time: " << p.waitingTime
             << " Turnaround time: " << p.turnaroundTime
             << endl;

        avgWaitingTime += p.waitingTime;
        avgTurnaroundTime += p.turnaroundTime;
        avgResponseTime += p.responseTime;
    }

    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;
    avgResponseTime /= numProcesses;

    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Response Time: " << avgResponseTime << endl;

    return 0;
}
