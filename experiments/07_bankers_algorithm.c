/* Experiment 7: Banker's deadlock avoidance algorithm. */
#include <stdio.h>
int main(void){
 int a[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}},m[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
 int v[3]={3,3,2},need[5][3],done[5]={0},seq[5],n=0;
 for(int i=0;i<5;i++)for(int j=0;j<3;j++)need[i][j]=m[i][j]-a[i][j];
 while(n<5){int progress=0;for(int i=0;i<5;i++)if(!done[i]){int ok=1;for(int j=0;j<3;j++)if(need[i][j]>v[j])ok=0;
 if(ok){for(int j=0;j<3;j++)v[j]+=a[i][j];done[i]=1;seq[n++]=i;progress=1;}}if(!progress)break;}
 if(n==5){printf("Safe sequence: ");for(int i=0;i<5;i++)printf("P%d%s",seq[i],i==4?"\n":" -> ");}else puts("Unsafe state");return 0;}
