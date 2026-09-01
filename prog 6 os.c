// Preemptive Priority Scheduling
#include <stdio.h>
#define MAX 9999
int main() {
    int i,n, bt[20], pr[20], rem[20], wt[20], tat[20], ct[20];
    printf("Enter number of processes: "); scanf("%d", &n);
    for (i=0;i<n;i++){ printf("BT and Priority of P%d: ", i+1); scanf("%d %d", &bt[i], &pr[i]); rem[i]=bt[i]; }
    int completed=0, t=0;
    while (completed<n){
        int idx=-1;
        for (i=0;i<n;i++) if(rem[i]>0 && (idx==-1 || pr[i]<pr[idx])) idx=i;
        rem[idx]--; t++;
        if (rem[idx]==0){ ct[idx]=t; tat[idx]=ct[idx]-0; wt[idx]=tat[idx]-bt[idx]; completed++; }
    }
    printf("P\tBT\tPR\tWT\tTAT\n");
    for ( i=0;i<n;i++) printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
    return 0;
}
