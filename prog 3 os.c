// FCFS Scheduling
#include <stdio.h>
int main() {
    int i,n, bt[20], wt[20], tat[20]; float awt=0, atat=0;
    printf("Enter number of processes: "); 
	scanf("%d", &n);
    for (i=0;i<n;i++){
	 printf("Enter burst time of P%d: ", i+1); 
	scanf("%d", &bt[i]); 
	}
    wt[0]=0;
    for (i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];
    printf("P\tBT\tWT\tTAT\n");
    for (i=0;i<n;i++){
        tat[i]=bt[i]+wt[i]; awt+=wt[i]; atat+=tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average WT = %.2f, Average TAT = %.2f\n", awt/n, atat/n);
    return 0;
}


