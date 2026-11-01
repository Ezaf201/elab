/* Experiment 12: Best Fit and Worst Fit, manual sample sizes. */
#include <stdio.h>
static void allocate(const char *name,int worst){int b[]={100,50,30,120,35},p[]={40,10,30,60},used[5]={0},a[4];
 for(int i=0;i<4;i++){a[i]=-1;for(int j=0;j<5;j++)if(!used[j]&&b[j]>=p[i]&&(a[i]<0||(worst?b[j]>b[a[i]]:b[j]<b[a[i]])))a[i]=j;if(a[i]>=0)used[a[i]]=1;}
 printf("%s Memory Allocation\nProcess\tSize\tBlock\n",name);for(int i=0;i<4;i++){printf("P%d\t%d\t",i+1,p[i]);if(a[i]>=0)printf("%d (size %d)\n",a[i]+1,b[a[i]]);else puts("Not Allocated");}}
int main(void){allocate("Best Fit",0);putchar('\n');allocate("Worst Fit",1);return 0;}
