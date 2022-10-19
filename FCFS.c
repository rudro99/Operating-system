#include<stdio.h>

int main()
{
    int bt[20],wt[20],tat[20],at[20],ct[20],p[20],i,j,n,temp;
    float wtavg,tatavg;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    printf("Enter the arrival time of process: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter the burst of process: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(at[j] > at[j+1])
            {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = wt[0] + bt[0];
    ct[0] = at[0] + bt[0];
    tatavg = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = ct[i-1] - at[i];
        tat[i] = wt[i] + bt[i];
        ct[i] = ct[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\nProcess \t Arrival Time \t Burst Time\t Waiting Time \t Turnaround Time");
    for(i=0; i<n; i++)
    {
        printf("\n%d \t\t %d \t \t %d\t\t %d \t\t %d",p[i],at[i],bt[i],wt[i],tat[i]);
    }
    printf("\n\nAverage waiting time = %f",wtavg/n);
    printf("\nAverage turnaround  time = %f\n",tatavg/n);
}

