// SJF Non-preemptive Scheduling
#include <stdio.h>
int main() {
    int i,c,n, bt[20], wt[20], tat[20], done[20]={0}; float awt=0, atat=0;
    printf("Enter number of processes: "); scanf("%d", &n);
    for (i=0;i<n;i++){ printf("Enter burst time of P%d: ", i+1); scanf("%d", &bt[i]); }
    int time=0;
    for ( c=0;c<n;c++){
        int idx=-1;
        for (i=0;i<n;i++) if(!done[i] && (idx==-1 || bt[i]<bt[idx])) idx=i;
        wt[idx]=time; time+=bt[idx]; tat[idx]=time; done[idx]=1;
        awt+=wt[idx]; atat+=tat[idx];
    }
    printf("P\tBT\tWT\tTAT\n");
    for ( i=0;i<n;i++) printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    printf("Average WT = %.2f, Average TAT = %.2f\n", awt/n, atat/n);
    return 0;
}
