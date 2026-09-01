//13. Memory Allocation Strategies
//Program:
#include <stdio.h>
int main() {
    int bs[10], ps[10], nb, np, alloc[10];
    printf("Blocks: "); scanf("%d", &nb);
    for (int i=0;i<nb;i++) scanf("%d", &bs[i]);
    printf("Processes: "); scanf("%d", &np);
    for (int i=0;i<np;i++) scanf("%d", &ps[i]);
    for (int i=0;i<np;i++){
        alloc[i]=-1;
        for (int j=0;j<nb;j++) if (bs[j]>=ps[i]){ alloc[i]=j; bs[j]-=ps[i]; break; }
    }
    printf("Process\tSize\tBlock\n");
    for (int i=0;i<np;i++)
        if (alloc[i]!=-1) printf("P%d\t%d\t%d\n", i+1, ps[i], alloc[i]+1);
        else printf("P%d\t%d\tNot Allocated\n", i+1, ps[i]);
    return 0;
}