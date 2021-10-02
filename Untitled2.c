#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 150
struct go {
    char b[10];
    char c[15];
    int num;
} a[N], * pa;
int main() {
    FILE*fp1,*fp2;
    pa = a;
    if ((fp1 = fopen("yq_in.txt", "r")) == NULL) {
        exit(0);
    }
    if ((fp2 = fopen("yq_out.txt", "w")) == NULL) {
        exit(0);
    }
    for (int i = 0; i < N; i++, pa++) {
        fscanf(fp1, "%s	%s	%d\n", pa->b, pa->c, &pa->num);
    }
    pa = a;
    for (int j = 0; j < N; j++, pa++) {
        if (a[j].num == 0)
            continue;
        if(j==0)
            fprintf(fp2,"%s\n%s	%d\n", pa->b, pa->c, pa->num);
        else {
            if (strcmp(a[j].b,a[j-1].b)==0)
                fprintf(fp2,"%s\t%d\n", a[j].c, a[j].num);
            else{
                fprintf(fp2,"\n%s\n%s\t%d\n", a[j].b, a[j].c, a[j].num);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
