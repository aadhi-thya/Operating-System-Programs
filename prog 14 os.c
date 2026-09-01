//14. Single Level Directory
#include <stdio.h>
#include <string.h>
struct { char name[20]; } dir[10];
int n=0;
int main() {
    int ch;
    char fname[20];
    do {
        printf("1.Create 2.Delete 3.Display 4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch==1){ printf("Enter file name: "); scanf("%s", fname); strcpy(dir[n++].name, fname); }
        else if (ch==2){ printf("Enter file name: "); scanf("%s", fname);
            for(int i=0;i<n;i++) if(!strcmp(dir[i].name,fname)){ dir[i]=dir[--n]; break; } }
        else if (ch==3){ printf("Files:\n"); for(int i=0;i<n;i++) printf("%s\n", dir[i].name); }
    } while (ch!=4);
    return 0;
}