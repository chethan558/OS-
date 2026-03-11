#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, highest;
    int burst[20], remaining[20], priority[20], arrival[20];
    int waiting[20], turnaround[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);

        printf("Priority: ");
        scanf("%d", &priority[i]);

        remaining[i] = burst[i];
    }

    while(completed != n) {
        highest = -1;

        for(i = 0; i < n; i++) {
            if(arrival[i] <= time && remaining[i] > 0) {
                if(highest == -1 || priority[i] < priority[highest])
                    highest = i;
            }
        }

        if(highest != -1) {
            remaining[highest]--;
            time++;

            if(remaining[highest] == 0) {
                completed++;

                turnaround[highest] = time - arrival[highest];
                waiting[highest] = turnaround[highest] - burst[highest];

                avg_wt += waiting[highest];
                avg_tat += turnaround[highest];
            }
        }
        else {
            time++;
        }
    }

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               i+1, burst[i], priority[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);

    return 0;
}