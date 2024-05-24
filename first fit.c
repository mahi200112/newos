#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX 10
int memory_blocks[MAX_BLOCKS];
int block_sizes[MAX_BLOCKS];
int num_blocks,num;

void initializeMemory() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        memory_blocks[i] = -1; // -1 indicates that block is free
        block_sizes[i] = 0;    // Initialize block sizes to 0
    }
}

/*void displayMemory(int num_blocks,int block_sizes[],int process_id, int process_size) {
    int i;

    for (i = 0; i < num_blocks; i++) {
        if (memory_blocks[i] == -1) {
            printf("\nBlock %d: Free\tSize: %d", i, block_sizes[i]);
        } else {
            printf("\nBlock %d: Allocated to Process %d\tSize: %d", i, memory_blocks[i],block_sizes[i]-process_size);
        }
    }
    printf("\n");
}
*/

void displayMemory() {
    int i;

    for (i = 0; i < num_blocks; i++) {

        if (memory_blocks[i] == -1) {
            printf("\n\nBlock %d: Free\tSize.", i+1);
        } else {
            printf("\n\nBlock %d: Allocated \n",i+1);
           }
        }

    printf("\n");

}
void firstFit(int num_blocks,int block_sizes[],int process_id, int process_size) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if ((memory_blocks[i] == -1 || memory_blocks[i] != -1 ) && block_sizes[i] >= process_size) {
            memory_blocks[i] = process_id;
            block_sizes[i]=block_sizes[i]-process_size;
            printf("\nProcess %d allocated to Block %d\n", process_id, i+1);
            printf("Space left in  that block %d\n\n",block_sizes[i]);
            return;
        }


    }
    printf("\nProcess %d cannot be allocated due to insufficient memory", process_id);
}

int main() {
    int process_id[MAX], block_size,num,p_size[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &num_blocks);

    initializeMemory();



    for (int i = 0; i < num_blocks; i++) {
        printf("\nEnter size of block %d: ", i+1);
        scanf("%d", &block_size);
        block_sizes[i] = block_size;
    }


    printf("\nEnter number of process: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("\nEnter size of process %d: ", i+1);
        scanf("%d", &p_size[i]);
        process_id[i]=i+1;
       // firstFit(num_blocks,block_sizes,process_id[i], p_size[i]);

    }
     for (int i = 0; i < num; i++) {

        firstFit(num_blocks,block_sizes,process_id[i], p_size[i]);

    }

     displayMemory();

     /* for (int i = 0; i < num; i++) {
       printf("\nMemory Block Status:");
    displayMemory(num_blocks,block_sizes,process_id[i], p_size[i]);
      }*/
    return 0;
}
