// Round Robin Scheduling
#include <stdio.h>
int main() {
    int i,n, bt[20], rem[20], wt[20], tat[20], q; float awt=0, atat=0;
    printf("Enter number of processes: "); scanf("%d", &n);
    for ( i=0;i<n;i++){ printf("BT of P%d: ", i+1); scanf("%d", &bt[i]); rem[i]=bt[i]; }
    printf("Time quantum: "); scanf("%d", &q);
    int t=0, done=0;
    while (done<n){
        for (i=0;i<n;i++){
            if (rem[i]>0){
                int slice = rem[i]<q ? rem[i] : q;
                t+=slice; rem[i]-=slice;
                if (rem[i]==0){ tat[i]=t; wt[i]=tat[i]-bt[i]; done++; awt+=wt[i]; atat+=tat[i]; }
            }
        }
    }
    for (i=0;i<n;i++) printf("P%d\tWT=%d\tTAT=%d\n", i+1, wt[i], tat[i]);
    printf("Average WT = %.2f, Average TAT = %.2f\n", awt/n, atat/n);
    return 0;
}
