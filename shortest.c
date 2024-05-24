#include <stdio.h>

void swap(int *a,int *b){
int t ;
t= *a ;
*a = *b;
*b = t;
}

int main(){
   int n;

   scanf("%d",&n);

   int pid[n],arrival[n],burst[n],originalBurst[n],completion[n],turnaround[n],waiting[n];

   for(int i=0;i<n;i++){
        pid[i]=i+1;
   printf("\n Arrival time and burst time for P%d",pid[i]);
   scanf("%d%d",&arrival[i],&burst[i]);
   originalBurst[i]=burst[i];
   }


     for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arrival[i]>arrival[j] || (arrival[i]==arrival[j] && burst[i]>burst[j] )){
                swap(&arrival[i],&arrival[j]);
                swap(&burst[i],&burst[j]);
                swap(&originalBurst[i],&originalBurst[j]);
                swap(&pid[i],&pid[j]);

            }
    }}

    int currentTime=0;

    for(int completed=0;completed<n;completed++){
        int minBurst=__INT_MAX__;
        int next_proc=-1;

        for(int i=0;i<n;i++){
            if(arrival[i]<=currentTime && burst[i]>0 && burst[i]<= minBurst){
                minBurst=burst[i];
                next_proc=i;
            }}

        if(next_proc==-1){ currentTime++; continue;}

        currentTime=currentTime+burst[next_proc];
        completion[next_proc]=currentTime;
        turnaround[next_proc]=completion[next_proc]-arrival[next_proc];
        waiting[next_proc]=turnaround[next_proc]-originalBurst[next_proc];
        burst[next_proc]=0;
    }


    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival[i], originalBurst[i], completion[i], turnaround[i], waiting[i]);
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
