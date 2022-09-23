/*
P AT BT
4 0 3 
2 2 6
3 4 4 
0 6 5 
1 8 2



*/

// Round Robin Preemptive CPU Scheduling algorithm
#include <stdio.h>
// structure to store each process information
struct process_info
{
    int at;
    int bt;
    int start;
    int end;
    int turnaround;
    int waiting;
};
// end of structure
void main()
{
    int i, n, sum = 0, count = 0, y, quant, waiting_time = 0, tat = 0, temp[10];
    float avg_wt, avg_tat;
    printf("\nEnter total number of process : ");
    scanf("%d", &n); // total n number of processes
    y = n;
    struct process_info list[10];
    // taking input for n processes
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf(" Arrival time : ");
        scanf("%d", &list[i].at);
        printf(" burst time : ");
        scanf("%d", &list[i].bt);
        temp[i] = list[i].bt;
    }
    // taking input for time quantum
    printf("Enter the Time Quantum for the process : \t");
    scanf("%d", &quant);

    printf("\n Process No \t\t Arrival Time \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t %d\t\t\t %d", i + 1, list[i].at, list[i].bt, sum - list[i].at,
                   sum - list[i].at - list[i].bt);
            waiting_time = waiting_time + sum - list[i].at - list[i].bt;
            tat = tat + sum - list[i].at;
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (list[i + 1].at <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    avg_wt = waiting_time * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    printf("\n Average Turn Around Time : \t%f", avg_tat);
    printf("\n Average Waiting Time : \t%f", avg_wt);
 
}
