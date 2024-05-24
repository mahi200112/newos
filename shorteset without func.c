#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], arrival[n], burst[n], originalBurst[n], waiting[n], turnaround[n], completion[n];

    // Input arrival time and burst time for each process
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time and burst time for process P%d: ", pid[i]);
        scanf("%d %d", &arrival[i], &burst[i]);
        originalBurst[i] = burst[i];
        // Store the original burst times
    }

    // Sort processes based on arrival time and burst time
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arrival[i] > arrival[j] || (arrival[i] == arrival[j] && burst[i] > burst[j])) {
                swap(&arrival[i], &arrival[j]);
                swap(&burst[i], &burst[j]);
                swap(&pid[i], &pid[j]);
                 swap(&originalBurst[i], &originalBurst[j]);

            }
        }
    }

    int currentTime = 0;
    int completed = 0;

    // Calculate waiting, turnaround, and completion times
    while(completed < n) {
        int minBurst = __INT_MAX__;
        int nextProcess = -1;

        // Find the next process to execute
        for(int i = 0; i < n; i++) {
            if(arrival[i] <= currentTime && burst[i] > 0) {
                if(burst[i] < minBurst) {
                    minBurst = burst[i];
                    nextProcess = i;
                }
            }
        }

        // If no process is found, increment current time
        if(nextProcess == -1) {
            currentTime++;
            continue;
        }

        currentTime += burst[nextProcess];
        completion[nextProcess] = currentTime;
        turnaround[nextProcess] = completion[nextProcess] - arrival[nextProcess];
        waiting[nextProcess] = turnaround[nextProcess] - originalBurst[nextProcess];
        burst[nextProcess] = 0;
        completed++;
    }

    for(int i = 0; i < n; i++) {
        burst[i] = originalBurst[i];
    }


    // Print process details and Gantt chart
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    // Calculate and print average waiting and turnaround times
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for(int i = 0; i < n; i++) {
        totalWaitingTime += waiting[i];
        totalTurnaroundTime += turnaround[i];
    }

    float averageWaitingTime = (float)totalWaitingTime / n;
    float averageTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);

    return 0;
}
