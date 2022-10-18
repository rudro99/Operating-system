#include<stdio.h>
void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];

    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;

                blockSize[j] -= processSize[i];

                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}
int main()
{
    int m,n,i;
      printf("Enter number of block:");
      scanf("%d/n",&m);
      printf("Enter number of process:");
      scanf("%d/n",&n);
    int blockSize[m],processSize[n];
      printf("Enter size of blocks:");
      for(i=0;i<m;i++){
        scanf("%d/n",&blockSize[i]);
      }
      printf("Enter size of processes:");
       for(i=0;i<n;i++){
        scanf("%d/n",&processSize[i]);
      }

    firstFit(blockSize, m, processSize, n);

    return 0 ;
}
