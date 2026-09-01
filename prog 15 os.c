//15. Two Level Directory
#include <stdio.h>
#include <string.h>
struct { char user[20], file[20]; } dir[20];
int n=0;
int main() {
    int ch; char u[20], f[20];
    do {
        printf("1.Create 2.Display 3.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch==1){ printf("User & file: "); scanf("%s %s", u, f); strcpy(dir[n].user,u); strcpy(dir[n].file,f); n++; }
        else if (ch==2){ for(int i=0;i<n;i++) printf("%s -> %s\n", dir[i].user, dir[i].file); }
    } while (ch!=3);
    return 0;
}