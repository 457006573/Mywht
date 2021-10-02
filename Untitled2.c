#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 129
struct map {
    char shen[10];
    char shi[15];
    int num;

} a[N], * pa;
int main() {
    FILE* fp, * fp2;

    int i;
    pa = a;

    //打开从文件
    if ((fp = fopen("yq_in.txt", "r")) == NULL) {
        printf("Failure to open yq_in.txt!\n");
        exit(0);
    }
    if ((fp2 = fopen("yq_out.txt", "w")) == NULL) {
        printf("Failure to open yq_out.txt!\n");
        exit(0);
    }

    //从文件yq_in.txt中读取数据，保存到a
    for (i = 0; i < N; i++, pa++) {
        fscanf(fp, "%s	%s	%d\n", pa->shen, pa->shi, &pa->num);
    }
    pa = a;
    //将a的数据输出到yq_out.txt
    for (i = 0; i < N; i++, pa++) {
        if (a[i].num == 0)
            continue;
        if(i==0)
            fprintf(fp2,"%s\n%s	%d\n", pa->shen, pa->shi, pa->num);
        else {

            if (strcmp(a[i].shen,a[i-1].shen)==0)
                fprintf(fp2,"%s\t%d\n", a[i].shi, a[i].num);
            else{
                fprintf(fp2,"\n%s\n%s\t%d\n", a[i].shen, a[i].shi, a[i].num);

            }

        }

    }
    fclose(fp);
    fclose(fp2);
    return 0;
}、
