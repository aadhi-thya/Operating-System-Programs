#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *in, *out; char f1[100], f2[100], c;
    printf("Enter source filename: "); scanf("%s", f1);
    printf("Enter destination filename: "); scanf("%s", f2);
    if (!(in = fopen(f1, "r"))) { printf("Cannot open %s\n", f1); exit(0); }
    out = fopen(f2, "w");
    while ((c = fgetc(in)) != EOF) fputc(c, out);
    printf("Contents copied to %s\n", f2);
    fclose(in); fclose(out);
    return 0;
}
