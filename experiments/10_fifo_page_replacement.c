/* Experiment 10: FIFO page replacement; manual sample, three frames. */
#include <stdio.h>
int main(void){int p[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1},f[3]={-1,-1,-1},next=0,faults=0;
 puts("Page\tFrame1\tFrame2\tFrame3\tResult");for(int i=0;i<14;i++){int hit=0;for(int j=0;j<3;j++)if(f[j]==p[i])hit=1;
 if(!hit){f[next]=p[i];next=(next+1)%3;faults++;}printf("%d\t",p[i]);for(int j=0;j<3;j++)if(f[j]<0)printf("-\t");else printf("%d\t",f[j]);puts(hit?"Hit":"Fault");}
 printf("\nTotal page faults = %d\nTotal page hits = %d\n",faults,14-faults);return 0;}
