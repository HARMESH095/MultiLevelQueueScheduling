#include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int priority;
    int burstTime;
};

int main() {
    struct process highPriorityQueue[100];
    struct process mediumPriorityQueue[100];
    struct process lowPriorityQueue[100];
    int highPrioritySize = 0;
    int mediumPrioritySize = 0;
    int lowPrioritySize = 0;
    int NoOfProcess = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &NoOfProcess);

    for (int i = 0; i < NoOfProcess; i++) {
        struct process newProcess;

        printf("Enter Process Id: ");
        scanf("%d", &newProcess.id);

        printf("Enter Priority for the Process: ");
        scanf("%d", &newProcess.priority);

        printf("Enter Burst Time for the process: ");
        scanf("%d", &newProcess.burstTime);

        if (newProcess.priority >= 1 && newProcess.priority <= 3) {
            highPriorityQueue[highPrioritySize] = newProcess;
            highPrioritySize++;
        } else if (newProcess.priority >= 4 && newProcess.priority <= 7) {
            mediumPriorityQueue[mediumPrioritySize] = newProcess;
            mediumPrioritySize++;
        } else if (newProcess.priority >= 8 && newProcess.priority <= 10) {
            lowPriorityQueue[lowPrioritySize] = newProcess;
            lowPrioritySize++;
        }
    }

    int quantumRR = 4;
    int quantumPS = 10;
    int quantumFCFS = 10;

    // High Priority Queue (Round Robin)
    printf("High Priority Queue (Round Robin):\n");
    int highPriorityCompleted = 0;
    while (highPriorityCompleted < highPrioritySize) {
        for (int i = 0; i < highPrioritySize; i++) {
            struct process *p = &highPriorityQueue[i];

            if (p->burstTime > 0) {
                printf("Process ID: %d, Burst Time (before): %d\n", p->id, p->burstTime);

                if (p->burstTime > quantumRR) {
                    p->burstTime -= quantumRR;
                    printf("Subtracting %d from Process ID: %d, Burst Time (after): %d\n", quantumRR, p->id, p->burstTime);
                } else {
                    p->burstTime = 0;
                    printf("Process ID: %d, Burst Time (after): %d\n", p->id, p->burstTime);
                }

                if (p->burstTime == 0) {
                    highPriorityCompleted++;
                }
            }
        }
    }

    // Medium Priority Queue (Priority Scheduling)
    printf("Medium Priority Queue (Priority Scheduling):\n");
    int mediumPriorityCompleted = 0;
    while (mediumPriorityCompleted < mediumPrioritySize) {
        for (int i = 0; i < mediumPrioritySize; i++) {
            struct process *p = &mediumPriorityQueue[i];

            if (p->burstTime > 0) {
                printf("Process ID: %d, Burst Time (before): %d\n", p->id, p->burstTime);

                if (p->burstTime > quantumPS) {
                    p->burstTime -= quantumPS;
                    printf("Subtracting %d from Process ID: %d, Burst Time (after): %d\n", quantumPS, p->id, p->burstTime);
                } else {
                    p->burstTime = 0;
                    printf("Process ID: %d, Burst Time (after): %d\n", p->id, p->burstTime);
                }

                if (p->burstTime == 0) {
                    mediumPriorityCompleted++;
                }
            }
        }
    }

    // Low Priority Queue (First Come First Serve)
    printf("Low Priority Queue (First Come First Serve):\n");
    int lowPriorityCompleted = 0;
    while (lowPriorityCompleted < lowPrioritySize) {
        for (int i = 0; i < lowPrioritySize; i++) {
            struct process *p = &lowPriorityQueue[i];

            if (p->burstTime > 0) {
                printf("Process ID: %d, Burst Time (before): %d\n", p->id, p->burstTime);

                if (p->burstTime > quantumFCFS) {
                    p->burstTime -= quantumFCFS;
                    printf("Subtracting %d from Process ID: %d, Burst Time (after): %d\n", quantumFCFS, p->id, p->burstTime);
                } else {
                    p->burstTime = 0;
                    printf("Process ID: %d, Burst Time (after): %d\n", p->id, p->burstTime);
                }

                if (p->burstTime == 0) {
                    lowPriorityCompleted++;
                }
            }
        }
    }

    return 0;
}
