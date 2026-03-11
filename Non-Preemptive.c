#include <stdio.h>

int main() {
    int n, i, j;
    int burst[20], priority[20], waiting[20], tat[20], process[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        process[i] = i + 1;

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &burst[i]);

        printf("Enter Priority for P%d: ", i+1);
        scanf("%d", &priority[i]);
    }

    // Sort by priority
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(priority[i] > priority[j]) {
                int temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    waiting[0] = 0;

    for(i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = burst[i] + waiting[i];
        avg_wt += waiting[i];
        avg_tat += tat[i];
    }

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               process[i], burst[i], priority[i], waiting[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);

    return 0;
}