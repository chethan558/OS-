#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    int at[10], bt[10], rt[10];
    int wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d AT BT: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    int flag = 0;

    for(time = 0, i = 0; remain != 0;) {

        if(at[i] <= time) {
            if(rt[i] > 0 && rt[i] <= tq) {
                time += rt[i];
                rt[i] = 0;
                flag = 1;
            }
            else if(rt[i] > 0) {
                rt[i] -= tq;
                time += tq;
            }

            if(rt[i] == 0 && flag == 1) {
                remain--;
                tat[i] = time - at[i];
                wt[i] = tat[i] - bt[i];
                flag = 0;
            }
        }


        i = (i + 1) % n;


        int all_not_arrived = 1;
        for(int j = 0; j < n; j++) {
            if(at[j] <= time && rt[j] > 0) {
                all_not_arrived = 0;
                break;
            }
        }

        if(all_not_arrived) {
            time++;
        }
    }

    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], tat[i], wt[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
