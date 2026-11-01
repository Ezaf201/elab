/* Experiment 8: non-preemptive FCFS and SJF CPU scheduling. */
#include <stdio.h>
static void report(const char *name,int order[],int n,int burst[]){int time=0,wait=0;printf("%s order: ",name);
 for(int i=0;i<n;i++){int p=order[i];printf("P%d%s",p+1,i==n-1?"\n":" -> ");wait+=time;time+=burst[p];}
 printf("Average waiting time: %.2f\n",(double)wait/n);}
int main(void){int b[4]={6,8,7,3},f[4]={0,1,2,3},s[4]={3,0,2,1};report("FCFS",f,4,b);report("SJF",s,4,b);return 0;}
