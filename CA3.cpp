#include <stdio.h>

struct Process {
    int id;
    int ARRtime;
    int Bustt;
    int watetime;
    int turnaroundtime;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].Bustt < processes[j + 1].Bustt) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].watetime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].watetime = processes[i - 1].watetime + processes[i - 1].Bustt;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundtime = processes[i].watetime + processes[i].Bustt;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].ARRtime);
        processes[i].Bustt = 2 * processes[i].ARRtime;
    }

    sortProcesses(processes, n);
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].ARRtime, processes[i].Bustt, processes[i].watetime, processes[i].turnaroundtime);
    }

    float average_waiting_time = 0;
    float average_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        average_waiting_time += processes[i].watetime;
        average_turnaround_time += processes[i].turnaroundtime;
    }
    average_waiting_time /= n;
    average_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
  return 0;
}

