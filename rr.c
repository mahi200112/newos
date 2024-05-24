#include<stdio.h>

int main()
{
    int i,j,n,time,remain,flag=0,tq;

    scanf("%d",&n);
    int at[n],bt[n],rt[n],wt=0,tat=0;
    remain=n;
    for(i=0;i<n;i++){
        printf(" arrival and burst time for P%d:", i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }
  printf("Enter Time Quantum:\t");
  scanf("%d",&tq);
  printf("\n\nProcess\t AT\t BT \t CT\t TAT \t WT\n");
  for(i=0,time=0;remain!=0;){
        if(rt[i]<=tq && rt[i]>0){
            time+=rt[i];
            rt[i]=0;
            flag=1;

        }
        else if(rt[i]>tq){
             time+=tq;
            rt[i]=rt[i]-tq;

        }
        if(rt[i]==0 && flag==1){
      remain--;
      printf("jqwj");
      printf("P[%d]\t%d\t%d\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],time,time-at[i],time-at[i]-bt[i]);

      tat+=time-at[i];
      wt+=time-at[i]-bt[i];
      flag=0;
    }
    if(i==n-1){i=0;}

    else if(at[i+1]<=time)
      {i++;}
    else{
      i=0;}
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Avg Turnaround Time = %f",tat*1.0/n);





return 0;
}
