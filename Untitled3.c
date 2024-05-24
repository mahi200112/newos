#include <stdio.h>
#include <stdlib.h>

// Function to find the optimal page to replace
int findOptimalPage(int pages[], int frames[], int n, int frame_count, int current_index) {
    int farthest = current_index, res = -1;

    for (int i = 0; i < frame_count; i++) {
        int j;
        for (j = current_index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res;
}

// Function to perform optimal page replacement
void optimalPageReplacement(int pages[], int n, int frame_count) {
    int frames[frame_count];
    for (int i = 0; i < frame_count; i++) {
        frames[i] = -1; // Initialize frames to be empty
    }
    int hit = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the current page is already in any of the frames
        for (int j = 0; j < frame_count; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                hit++;
                break;
            }
        }

        // If the page is not found in any frame, we need to load it into a frame
        if (!found) {
            int empty_slot = -1;

            // Check for an empty slot in the frames
            for (int j = 0; j < frame_count; j++) {
                if (frames[j] == -1) {
                    empty_slot = j;
                    break;
                }
            }

            // If there is an empty slot, use it
            if (empty_slot != -1) {
                frames[empty_slot] = pages[i];
            } else {
                // Otherwise, find the optimal frame to replace
                int j = findOptimalPage(pages, frames, n, frame_count, i + 1);
                frames[j] = pages[i];
            }
        }
    }

    // Print the number of hits and misses
    printf("Hits = %d\n", hit);
    printf("Misses = %d\n", n - hit);
}

int main() {
    int n;
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    int frame_count;
    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    // Execute the optimal page replacement algorithm
    optimalPageReplacement(pages, n, frame_count);

    return 0;
}
