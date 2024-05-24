#include <stdio.h>

void swap(int *a,int *b){
int t ;
t= *a ;
*a = *b;
*b = t;
}

int main(){
   int n,i,j;

   scanf("%d",&n);

   int pid[n],arrival[n],burst[n],originalBurst[n],priority[n],completion[n],turnaround[n],waiting[n];

   for(int i=0;i<n;i++){
        pid[i]=i+1;
   printf("\n Arrival time , burst time priority for P%d: ",pid[i]);
   scanf("%d%d%d",&arrival[i],&burst[i],&priority[i]);

   }
    for(i=0;i<n-1;i++){
       for(j=i+1;j<n;j++){
        if(arrival[i]>arrival[j]||(arrival[i]==arrival[j] && priority[i]>priority[j])||
           (arrival[i]==arrival[j] && priority[i]==priority[j] && pid[i]>pid[j])){
            swap(&arrival[i],&arrival[j]);
                swap(&burst[i],&burst[j]);
                swap(&priority[i],&priority[j]);
                swap(&pid[i],&pid[j]);

           }
    }
    }

    int currentTime=0;
    int completed_proc[n];
       for( i=0;i<n ;i++){completed_proc[i]=0;}

     for(int completed=0;completed<n;completed++){


        int minPriority=__INT_MAX__;
        int nextproc=-1;


        for(i=0 ;i<n ;i++){
         if(arrival[i]<=currentTime && completed_proc[i] ==0 && (priority[i]< minPriority ||( priority[i]== minPriority && arrival[i]<arrival[nextproc]))){
            minPriority=priority[i];
            nextproc=i;
         }
        }

        if(nextproc==-1){currentTime++; continue;}
         else{
        currentTime=currentTime+burst[nextproc];
        completion[nextproc]=currentTime;
        turnaround[nextproc]=completion[nextproc]-arrival[nextproc];
        waiting[nextproc]=turnaround[nextproc]-burst[nextproc];
        completed_proc[nextproc]=1;
     }}
     printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival[i], burst[i],priority[i], completion[i], turnaround[i], waiting[i]);
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





   return 0;
}
