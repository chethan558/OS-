#include <stdio.h>

#define MAX 100

typedef struct {
    int pid;
    int at;
    int bt;
    int type; 
    int ct, tat, wt, start;
} Process;


void sortByArrival(Process p[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    Process p[MAX], sys[MAX], user[MAX];
    int sysCount = 0, userCount = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Type (0=System, 1=User): ");
        scanf("%d", &p[i].type);

        
        if (p[i].type == 0)
            sys[sysCount++] = p[i];
        else
            user[userCount++] = p[i];
    }

    
    sortByArrival(sys, sysCount);
    sortByArrival(user, userCount);

    int time = 0;

    
    for (int i = 0; i < sysCount; i++) {
        if (time < sys[i].at)
            time = sys[i].at;

        sys[i].start = time;
        time += sys[i].bt;
        sys[i].ct = time;

        sys[i].tat = sys[i].ct - sys[i].at;
        sys[i].wt = sys[i].tat - sys[i].bt;
    }

    
    for (int i = 0; i < userCount; i++) {
        if (time < user[i].at)
            time = user[i].at;

        user[i].start = time;
        time += user[i].bt;
        user[i].ct = time;

        user[i].tat = user[i].ct - user[i].at;
        user[i].wt = user[i].tat - user[i].bt;
    }

    
    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");

 
    for (int i = 0; i < sysCount; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               sys[i].pid, sys[i].at, sys[i].bt, sys[i].type,
               sys[i].ct, sys[i].tat, sys[i].wt);
    }

   
    for (int i = 0; i < userCount; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               user[i].pid, user[i].at, user[i].bt, user[i].type,
               user[i].ct, user[i].tat, user[i].wt);
    }

    return 0;
}