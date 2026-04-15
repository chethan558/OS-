#include <stdio.h>
#include <math.h>

#define MAX_TASKS 10


typedef struct {
    int id;
    float Ci;
    float Ti;
} Task;


void sortTasks(Task tasks[], int n) {
    Task temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].Ti > tasks[j].Ti) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    Task tasks[MAX_TASKS];
    float U = 0.0, bound;

    printf("Enter number of tasks: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("Enter execution time (C%d): ", i + 1);
        scanf("%f", &tasks[i].Ci);
        printf("Enter period (T%d): ", i + 1);
        scanf("%f", &tasks[i].Ti);
    }


    for (int i = 0; i < n; i++) {
        U += (tasks[i].Ci / tasks[i].Ti);
    }


    bound = n * (pow(2, 1.0 / n) - 1);


    printf("\nCPU Utilization (U) = %.4f\n", U);
    printf("RMS Bound = %.4f\n", bound);


    if (U <= bound) {
        printf("Schedulable using RMS\n");
    } else {
        printf("Not guaranteed schedulable (need further analysis)\n");
    }


    sortTasks(tasks, n);

    printf("\nTask Priorities (Higher priority = smaller period):\n");
    for (int i = 0; i < n; i++) {
        printf("Priority %d -> Task %d (T = %.2f)\n",
               i + 1, tasks[i].id, tasks[i].Ti);
    }



    return 0;
}
