#include<stdio.h>

int main(){
    int np,nr,i,j,k;

    printf("Enter number of processes: ");
    scanf("%d",&np);
    printf("Enter number of resources: ");
    scanf("%d",&nr);

    int alloc[np][nr],max[np][nr],need[np][nr],avail[nr];

    printf("Enter allocation matrix:\n");
    for(i=0;i<np;i++){
           printf("For Process %d :",i+1);
        for(j=0;j<nr;j++){
              scanf("%d",&alloc[i][j]);
        }
      printf("\n");
    }
    printf("Enter max matrix:\n");
    for(i=0;i<np;i++){
           printf("For Process %d:",i+1);
        for(j=0;j<nr;j++){
              scanf("%d",&max[i][j]);
        }
        printf("\n");
    }
    printf("The need matrix:\n");
    for(i=0;i<np;i++){
           printf("For Process %d :",i+1);
        for(j=0;j<nr;j++){
             need[i][j]=max[i][j]-alloc[i][j];
             printf("%d ",need[i][j]);
        }
      printf("\n");
    }
    printf("\navailable resources:");
    for(j=0;j<nr;j++){
    scanf("%d",&avail[j]);}

    int f[np],ans[np],ind=0,y=0,flag=0;

    for(k=0;k<np;k++){
        f[k]=0;
    }

    for(k=0;k<np;k++){
      for(i=0;i<np;i++){
            if(f[i]==0){
                flag=1;
                for(j=0;j<np;j++){
                 if(need[i][j]>avail[i]){
                 flag=0;break;}
              }
            if(flag==1){
                ans[ind]=i;
                ind++;
                for(y=0;y<nr;y++){
                    avail[y]=avail[y]+alloc[i][y];
                    }
                    f[i]=1;

            }
            }

        }
    }
    for(i=0;i<np;i++){
        if(f[i]==0){
            flag=0;
            printf("The following system is not safe\n");
            break;
        }
    }

    if(flag==1){
        printf("The safe sequence:\n");
             for(i=0;i<np-1;i++){
                printf("P%d - >",ans[i]) ;
               }
               printf("P%d .",ans[np-1]) ;

    }
return 0;
}
