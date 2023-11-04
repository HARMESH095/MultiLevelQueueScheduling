#include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int priority;
    int burstTime;
};

void swap(struct process *a, struct process *b) {
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the priority queue in ascending order based on priority
void sortQueue(struct process queue[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (queue[j].priority > queue[j + 1].priority) {
                swap(&queue[j], &queue[j + 1]);
            }
        }
    }
}

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
    sortQueue(mediumPriorityQueue, mediumPrioritySize);

    // High Priority Queue (Round Robin) with quantum time
    printf("High Priority Queue (Round Robin):\n");
    int highPriorityCompleted = 0;
    int quantumRR = 4;
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
                    highPriorityCompleted++;
                }
            }
        }
    }

    // Medium Priority Queue (Priority Scheduling) without quantum time
    printf("Medium Priority Queue (Priority Scheduling):\n");
    for (int i = 0; i < mediumPrioritySize; i++) {
        struct process *p = &mediumPriorityQueue[i];

        printf("Process ID: %d, Burst Time: %d\n", p->id, p->burstTime);
    }

    // Low Priority Queue (First Come First Serve) without quantum time
    printf("Low Priority Queue (First Come First Serve):\n");
    for (int i = 0; i < lowPrioritySize; i++) {
        struct process *p = &lowPriorityQueue[i];

        printf("Process ID: %d, Burst Time: %d\n", p->id, p->burstTime);
    }

    return 0;
}
