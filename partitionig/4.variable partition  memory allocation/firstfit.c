// 3 300 25 70 3 150 300 35
// 4 300 25 125 50 2 150 350
//4 357 210 468 491 6 200 400 600 500 300 250
#include <stdio.h>
int n, m;
int main()
{
    printf("Enter the no. of processes\n");
    scanf("%d", &n);

    int process_memory[n];
    int process[n];

    for (int i = 0; i < n; i++)
    {
        printf("memory requirementof process-%d : ", i);
        scanf("%d", &process_memory[i]);
        process[i] = -1;
    }

    printf("Enter the no. of empty partitons in the MM\n");
    scanf("%d", &m);
    int prt_size[m];

    for (int i = 0; i < m; i++)
    {
        printf("Size of block%d  ", i);
        scanf("%d", &prt_size[i]);
    }

    int out_frag = 0;
    int empty_blocks_memory = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (process_memory[i] <= prt_size[j])
            {
                prt_size[j] = prt_size[j] - process_memory[i];
                process[i] = j + 1;
                // printf("in i = %d,j = %d,process[i]=%d,prt_size[j]=%d\n",i,j,process[i],prt_size[j]);
                break;
            }
            // printf("out i = %d,j = %d,process[i]=%d,prt_size[j]=%d\n",i,j,process[i],prt_size[j]);
        }
    }

    printf("\n\n");

    for (int i = 0; i < m; i++)
    {
            empty_blocks_memory += prt_size[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        if (process[i] == -1)
        {
            printf("process %d is unallocated\n", i + 1);
            if (empty_blocks_memory >= process_memory[i])
            {
                out_frag += process_memory[i];
            }
        }
        else
        {
            printf("process %d is allocated to  partition %d \n", i + 1, process[i]);
        }
    }

    printf("\nExternal Fragmentation = %d\n", out_frag);
    printf("\nTotal memory of empty unallocated blocks = %d\n", empty_blocks_memory);
}