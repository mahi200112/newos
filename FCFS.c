#include<stdio.h>

void swap(int *p,int *q)
{
    int tmp;
    tmp = *p; // tmp store the value of n1
    *p=*q;    // *p store the value of *q that is value of n2
    *q=tmp;   // *q store the value of tmp that is the value of n1
}


int main(){

	int bt[100]={0},at[100]={0},tat[100]={0},wt[100]={0},ct[100]={0},prc[100]={0};
	int n,sum=0,totalTAT=0,totalWT=0;
	printf("Enter number of processes:");
	scanf("%d",&n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
	    prc[i]=i;
		printf("Arrival time and burst time of process[%d]:",i+1);
		scanf("%d%d",&at[i],&bt[i]);


		printf("\n");
	}

	for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&prc[j],&prc[j+1]);

            }
        }
	}



	for(int j=0;j<n;j++){
	    if(sum<at[j]){
            sum=at[j];
		}
		sum+=bt[j];

		ct[j]+=sum;
	}
	for(int k=0;k<n;k++)
	{
		tat[k]=ct[k]-at[k];
		totalTAT+=tat[k];
	}
	for(int k=0;k<n;k++)
	{
		wt[k]=tat[k]-bt[k];
		totalWT+=wt[k];
	}

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(prc[j]>prc[j+1]){
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&prc[j],&prc[j+1]);
                swap(&tat[j],&tat[j+1]);
                 swap(&ct[j],&ct[j+1]);
                swap(&wt[j],&wt[j+1]);
            }
        }
	}
	printf("Solution: \n\n");
	printf("P_id\t AT\t BT\t CT\t TAT\t WT\t\n\n");

	for(int i=0;i<n;i++)
	{
		printf("P%d\t %d\t %d\t %d\t %d\t %d\n",prc[i]+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n\nAverage Turnaround Time = %d\n",totalTAT/n);
	printf("Average WT = %d\n\n",totalWT/n);
	return 0;
}
