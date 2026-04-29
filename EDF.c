


#include <stdio.h>

#define MAX 10

int main() {
    int n, i, t = 0, completed = 0;

    int Ci[MAX], Di[MAX], Ai[MAX];
    int remaining[MAX], done[MAX];

    float U = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &Ai[i]);

        printf("Execution Time: ");
        scanf("%d", &Ci[i]);

        printf("Deadline: ");
        scanf("%d", &Di[i]);

        remaining[i] = Ci[i];
        done[i] = 0;

        U += (float)Ci[i] / Di[i];
    }

    // Utilization check
    printf("\nCPU Utilization = %.2f\n", U);

    if (U > 1)
        printf("Scheduling NOT feasible\n");
    else
        printf("Scheduling feasible\n");

    printf("\nExecution Order:\n");

    // EDF Scheduling
    while (completed < n) {
        int min_deadline = 9999;
        int selected = -1;

        // Find process with earliest deadline
        for (i = 0; i < n; i++) {
            if (Ai[i] <= t && done[i] == 0) {
                if (Di[i] < min_deadline) {
                    min_deadline = Di[i];
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("Time %d: Idle\n", t);
            t++;
            continue;
        }

        printf("Time %d: P%d\n", t, selected + 1);

        remaining[selected]--;

        if (remaining[selected] == 0) {
            done[selected] = 1;
            completed++;
        }

        t++;
    }

    return 0;
}
