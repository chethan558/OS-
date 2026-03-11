#include <stdio.h>
int main(){
    
    int n;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    
    int at[n], bt[n],ct[n],tat[n],wt[n],rt[n],pid[n];
    int i,temp;

    for(i=0;i<n;i++){
        pid[i] = i + 1;

        printf("Enter the arrival time for process P%d:",i+1);
        scanf("%d",&at[i]);
        printf("Enter the burst time for process P%d:",i+1);
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp=at[i]; at[i]=at[j]; at[j]=temp;
                temp=bt[i]; bt[i]=bt[j]; bt[j]=temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    int current_time=0;
    float average_tat=0, average_wt=0;
    for(i=0;i<n;i++){
        if(current_time<at[i]){
            current_time=at[i];
        }

        ct[i]=current_time+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        rt[i]=wt[i];

        average_wt+=wt[i];average_tat+=tat[i];

        current_time=ct[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", average_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", average_tat/n);

    return 0;


}