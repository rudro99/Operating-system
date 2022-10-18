#include <stdio.h>

void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    int occupied[blocks];

    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }

    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }

    for (int i=0; i < processes; i++)
    {
	int indexPlaced = -1;
	for(int j = 0; j < blocks; j++)
	{
	    if(blockSize[j] >= processSize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;

                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }

        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;

            occupied[indexPlaced] = 1;

            blockSize[indexPlaced] -= processSize[i];
            printf("%d",allocation[i]);
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{

    int i,blocks, processes ;

      printf("Enter number of block:");
      scanf("%d/n",&blocks);
      printf("Enter number of process:");
      scanf("%d/n",&processes);

   int blockSize[blocks], processSize[processes] ;
      printf("Enter size of blocks:");
      for(i=0;i<blocks;i++){
        scanf("%d/n",&blockSize[i]);
      }
      printf("Enter size of processes:");
       for(i=0;i<processes;i++){
        scanf("%d/n",&processSize[i]);
      }

    implimentWorstFit(blockSize, blocks, processSize, processes);

    return 0;
}
