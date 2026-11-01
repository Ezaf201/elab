/* Experiment 14: sequential and indexed file allocation. */
#include <stdio.h>
int main(void){int disk[50]={0},start[]={5,8,20,2},len[]={3,4,5,4};puts("Sequential File Allocation");
 for(int i=0;i<4;i++){int ok=1;for(int k=start[i];k<start[i]+len[i];k++)if(k>=50||disk[k])ok=0;printf("File %d: start=%d length=%d\n",i+1,start[i],len[i]);
 if(ok){for(int k=start[i];k<start[i]+len[i];k++){disk[k]=1;printf("%d -> 1\n",k);}puts("Allocated");}else puts("Not allocated (blocks already in use)");}
 int d[50]={0},idx[]={9,20,9},data[3][4]={{1,2,3,4},{10,11,12,13},{30,31,32,33}};puts("\nIndexed File Allocation");
 for(int i=0;i<3;i++){printf("File %d: index block=%d\n",i+1,idx[i]);int ok=!d[idx[i]];for(int j=0;j<4;j++)if(d[data[i][j]])ok=0;
 if(!ok){puts("Not allocated (block already in use)");continue;}d[idx[i]]=1;for(int j=0;j<4;j++){d[data[i][j]]=1;printf("%d -> %d\n",idx[i],data[i][j]);}}return 0;}
