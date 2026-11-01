/* Experiment 9: non-preemptive priority and Round Robin, quantum 2. Lower number = higher priority. */
#include <stdio.h>
int main(void){int burst[4]={5,3,8,6},time=0,complete=0,q=2;puts("Priority order (highest first): P2 -> P1 -> P4 -> P3");
 puts("Round Robin completion times:");while(complete<4)for(int i=0;i<4;i++)if(burst[i]>0){int run=burst[i]<q?burst[i]:q;time+=run;burst[i]-=run;
 if(!burst[i]){printf("P%d completes at %d\n",i+1,time);complete++;}}return 0;}
