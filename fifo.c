#include<stdio.h>
int main()
{
    int l, s[50], frame[10], n, avail, count = 0, i, j, pos=0;
    printf("Enter the length of the string: ");
    scanf("%d",&l);
    printf("Enter the string: ");
    for(i=0; i<l; i++)
        scanf("%d",&s[i]);
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
        frame[i]= -1;           

    printf("\nString\t\t Page Frames\n");
    for(i=0; i<l; i++)
    {
        printf("%d\t\t",s[i]);
        avail = 0;          
        for(j=0; j<n; j++)
        {
            if(frame[j] == s[i])        
            {
                avail = 1;              
                break;
            }
        }
        if(avail == 0)             
        {
            frame[pos] = s[i];     
            pos = (pos+1) % n;          
            count++;               
            for(j=0; j<n; j++)
            {
                if(frame[j] != -1)
                    printf("%d\t",frame[j]);
            }
        }
        printf("\n");
    }
    printf("\nPage Fault is = %d\n", count);
    return 0;
}

