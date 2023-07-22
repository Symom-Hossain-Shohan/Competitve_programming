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
    return p1.arrivalTime < p2.arrivalTime;
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
            }
        }

        if (!processQueue.empty()) {
            Process currentProcess = processQueue.front();
            processQueue.pop();

            if (currentProcess.startTime == 0) {
                currentProcess.responseTime = currentTime - currentProcess.arrivalTime;
                currentProcess.startTime = currentTime;
            }

            int executedTime = min(1, currentProcess.remainingBurstTime);
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

            cout << "| Process " << currentProcess.processNumber << " ";
        } else {
            currentTime++;
            cout << "| Idle ";
        }
    }

    cout << "|" << endl;

    float avgWaitingTime = 0.0;
    float avgTurnaroundTime = 0.0;
    float avgResponseTime = 0.0;

    for (const Process& p : processes) {
        avgWaitingTime += p.waitingTime;
        avgTurnaroundTime += p.turnaroundTime;
        avgResponseTime += p.responseTime;
    }

    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;
    avgResponseTime /= numProcesses;

    cout << "Process\tResponse Time\tWaiting Time\tTurnaround Time" << endl;
    for (const Process& p : processes) {
        cout << p.processNumber << "\t" << p.responseTime << "\t\t" << p.waitingTime << "\t\t" << p.turnaroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Response Time: " << avgResponseTime << endl;

    return 0;
}
