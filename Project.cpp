//SHORTEST REMAINING TIME FIRST 
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

int main()
{
int a[10],b[10],r[10],endtime,i,Smallest;
int remained=0,n1,t,sumwait=0,sumturnaround=0;
printf("---------------SCHEDULAR DESIGN PROJECT BY VIDYA REDDY-----------\n");
printf("Please Read the following Details and Enter The Details Carefully \n\n");
printf("Enter No Of Processes  : ");
scanf("%d",&n1);
for(i=0;i<n1;i++)
{	
printf("Enter Arrival time for Process P%d : ",i+1);
scanf("%d",&a[i]);
printf("Enter Burst time for Process P%d : ",i+1);
scanf("%d",&b[i]);
r[i]=b[i];
}
printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");
r[9]=9999;
for(t=0;remained!=n1;t++)
{
Smallest=9;
for(i=0;i<n1;i++)
{
if(a[i]<=t && r[i]<r[Smallest] && r[i]>0)
{
Smallest=i;
}}
        
r[Smallest]--;
if(r[Smallest]==0)
{
remained++;
endtime=t+1;
printf("\nP[%d]\t|\t%d\t|\t%d",Smallest+1,endtime-a[Smallest],endtime-b[Smallest]-a[Smallest]);
sumwait+=endtime-b[Smallest]-a[Smallest];
sumturnaround+=endtime-a[Smallest];
}
}
printf("\n\nAverage waiting time = %f\n",sumwait*1.0/n1);
printf("Average Turnaround time = %f",sumturnaround*1.0/5);
return 0;
}

