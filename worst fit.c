#include <stdio.h>

#define MAX_BLOCKS 10

int memory_blocks[MAX_BLOCKS];
int block_sizes[MAX_BLOCKS];
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


void worstFit(int process_id, int process_size) {
    int worst_fit_index = -1;
    int max_size = -1; // Initialize to minimum possible value

    for (int i = 0; i < num_blocks; i++) {
        if ( block_sizes[i] >= process_size) {
            if (block_sizes[i] > max_size) {
                max_size = block_sizes[i];
                worst_fit_index = i;
            }
        }
    }

    if (worst_fit_index != -1) {
        memory_blocks[worst_fit_index] = process_id;
         block_sizes[worst_fit_index]=block_sizes[worst_fit_index]-process_size;
        printf("\nProcess %d allocated to Block %d\n", process_id, worst_fit_index + 1);
        printf("Space left in Block %d: %d\n", worst_fit_index + 1, block_sizes[worst_fit_index]);
    } else {
        printf("\nProcess %d cannot be allocated due to insufficient memory\n", process_id);
    }
}

int main() {
    int process_id[MAX_BLOCKS], process_size[MAX_BLOCKS];

    printf("Enter number of memory blocks: ");
    scanf("%d", &num_blocks);

    initializeMemory();

    for (int i = 0; i < num_blocks; i++) {
        printf("\nEnter size of block %d: ", i + 1);
        scanf("%d", &block_sizes[i]);
    }

    printf("\nEnter number of processes: ");
    int num_processes;
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("\nEnter size of process %d: ", i + 1);
        scanf("%d", &process_size[i]);
        process_id[i] = i + 1;
        worstFit(process_id[i], process_size[i]);
    }

    displayMemory();

    return 0;
}
