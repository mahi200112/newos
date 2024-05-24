#include <stdio.h>

#define MAX_BLOCKS 20
#define MAX 20
int memory_blocks[MAX_BLOCKS],block_sizes[MAX_BLOCKS];

int num_blocks;

void initializeMemory() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        memory_blocks[i] = -1; // -1 indicates that block is free
        block_sizes[i] = 0;    // Initialize block sizes to 0
    }
}

void displayMemory() {
    printf("\nMemory Block Status:");
    for (int i = 0; i < num_blocks; i++) {
        if (memory_blocks[i] == -1) {
            printf("\nBlock %d: is fully Free", i + 1);
        } else {
            printf("\nBlock %d: Allocated ", i + 1);
        }
    }
    printf("\n");
}

void bestFit(int process_id, int process_size) {
    int best_fit_index = -1,i;
    int min_size = __INT_MAX__; // Initialize to maximum possible integer value

    for ( i = 0; i < num_blocks; i++) {
        if ((memory_blocks[i] == -1 ||memory_blocks[i] != -1 ) && block_sizes[i] >= process_size) {
            if (block_sizes[i] < min_size) {
                min_size = block_sizes[i];
                best_fit_index = i;
            }
        }
    }

    if (best_fit_index != -1) {
        memory_blocks[best_fit_index] = process_id;
         block_sizes[best_fit_index]=block_sizes[best_fit_index]-process_size;
        printf("\nProcess %d allocated to Block %d\n", process_id, best_fit_index + 1);
        printf("Space left in Block %d: %d\n", best_fit_index + 1, block_sizes[best_fit_index]);
    } else {
        printf("\nProcess %d cannot be allocated due to insufficient memory\n", process_id);
    }
}

int main() {
    int choice, process_id[MAX], process_size[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &num_blocks);

    initializeMemory();

    for (int i = 0; i < num_blocks; i++) {
        printf("\nEnter size of block %d: ", i + 1);
        scanf("%d", &block_sizes[i]);
        //block_sizes[i] = block_size;
    }

    printf("\nEnter number of processes: ");
    int num_processes;
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("\nEnter size of process %d: ", i + 1);
        scanf("%d", &process_size[i]);
        process_id[i] = i + 1;
        //bestFit(process_id[i], process_size[i]);
    }

    for (int i = 0; i < num_processes; i++) {
        bestFit(process_id[i], process_size[i]);
    }


    displayMemory();

    return 0;
}
