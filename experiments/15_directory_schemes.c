/* Experiment 15: single-level and two-level directory schemes. */
#include <stdio.h>
#include <string.h>
static int find(char f[][20],int n,const char *s){for(int i=0;i<n;i++)if(!strcmp(f[i],s))return i;return -1;}
int main(void){char dir[10][20];int n=0;const char *names[]={"notes.txt","prog.c","data.dat","prog.c","memo.doc"};puts("Single Level Directory");
 for(int i=0;i<5;i++)if(find(dir,n,names[i])>=0)printf("Create %s: failed, name exists\n",names[i]);else{strcpy(dir[n++],names[i]);printf("Create %s: done\n",names[i]);}
 printf("Search memo.doc: %s\n",find(dir,n,"memo.doc")>=0?"found":"not found");printf("Search temp.txt: %s\n",find(dir,n,"temp.txt")>=0?"found":"not found");
 int p=find(dir,n,"prog.c");if(p>=0){for(int i=p;i<n-1;i++)strcpy(dir[i],dir[i+1]);n--;}puts("Directory contents:");for(int i=0;i<n;i++)puts(dir[i]);
 char users[3][10][20];int count[3]={0},owner[]={0,0,1,1,0,2};const char *fn[]={"a.txt","b.c","a.txt","c.dat","a.txt","b.c"};
 for(int i=0;i<6;i++){int u=owner[i];if(find(users[u],count[u],fn[i])>=0)printf("user%d: create %s failed\n",u+1,fn[i]);else strcpy(users[u][count[u]++],fn[i]);}
 puts("Two Level Directory");for(int u=0;u<3;u++){printf("user%d:",u+1);for(int j=0;j<count[u];j++)printf(" %s",users[u][j]);putchar('\n');}return 0;}
