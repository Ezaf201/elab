/* Experiment 11: LRU and LFU, manual sample sequence. */
#include <stdio.h>
static void run(int lfu){int p[]={1,2,3,2,1,5,2,1,6,2,5,6,3,1,3},f[3]={-1,-1,-1},last[3]={0},freq[3]={0},fault=0;
 printf("%s Page Replacement\n",lfu?"LFU":"LRU");for(int i=0;i<15;i++){int k=-1;for(int j=0;j<3;j++)if(f[j]==p[i])k=j;
 if(k>=0){last[k]=i;freq[k]++;}else{fault++;int v=-1;for(int j=0;j<3;j++)if(f[j]<0){v=j;break;}
 if(v<0){v=0;for(int j=1;j<3;j++)if(lfu?(freq[j]<freq[v]||(freq[j]==freq[v]&&last[j]<last[v])):last[j]<last[v])v=j;}
 f[v]=p[i];last[v]=i;freq[v]=1;}printf("%d\t",p[i]);for(int j=0;j<3;j++)if(f[j]<0)printf("-\t");else printf("%d\t",f[j]);puts(k>=0?"Hit":"Fault");}
 printf("Total page faults = %d\n\n",fault);}
int main(void){run(0);run(1);return 0;}
