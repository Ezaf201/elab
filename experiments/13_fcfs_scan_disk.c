/* Experiment 13: FCFS and SCAN disk scheduling; manual sample queue and tracks 0–199. */
#include <stdio.h>
#include <stdlib.h>
int main(void){int req[]={95,180,34,119,11,123,62,64},h=50,total=0;puts("FCFS Disk Scheduling");printf("Seek sequence: %d",h);
 for(int i=0;i<8;i++){total+=abs(req[i]-h);h=req[i];printf(" -> %d",h);}printf("\nTotal head movement = %d\n\n",total);
 int r[]={95,180,34,119,11,123,62,64};for(int i=0;i<7;i++)for(int j=0;j<7-i;j++)if(r[j]>r[j+1]){int t=r[j];r[j]=r[j+1];r[j+1]=t;}
 h=50;total=0;int k=0;while(k<8&&r[k]<=h)k++;printf("SCAN Disk Scheduling (towards higher tracks)\nSeek sequence: %d",h);
 for(int i=k;i<8;i++){total+=abs(r[i]-h);h=r[i];printf(" -> %d",h);}total+=199-h;h=199;printf(" -> 199");
 for(int i=k-1;i>=0;i--){total+=abs(r[i]-h);h=r[i];printf(" -> %d",h);}printf("\nTotal head movement = %d\n",total);return 0;}
