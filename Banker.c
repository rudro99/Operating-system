#include<stdio.h>

int main()
{
    int n,m,i,j,k,p[20],alloc[20][20],max[20][20],need[20][20],avail[20],safe[20],ans[20], cnt, ok;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter allocation: \n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &alloc[i][j]);
    printf("Enter max: \n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d", &max[i][j]);
    printf("Need matrix: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("Enter available: ");
    for(i=0; i<m; i++)
        scanf("%d", &avail[i]);
    for(i=0; i<n; i++)
    {
        p[i] = i+1;
        safe[i] = 0;
    }
    cnt = 0;
    for(k=0; k<n; k++)
    {
        for(i=0; i<n; i++)
        {
            if(safe[i] == 0)
            {
                ok = 1;
                for(j=0; j<m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        ok = 0;
                        break;
                    }
                }
                if(ok == 1)
                {
                    ans[cnt] = p[i];
                    safe[i] = 1;
                    cnt++;
                    for(j=0; j<m; j++)
                        avail[j] += alloc[i][j];
                }
            }
        }
    }
    if(cnt == n)
    {
        printf("Safe sequence: ");
        for(i=0; i<n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    else
        printf("Not safe....!!!\n");
}
