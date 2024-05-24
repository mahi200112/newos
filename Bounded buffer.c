#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty, x = 0;

int wait(int s) {
    s--;
    return s;
}

int signal(int s) {
    s++;
    return s;
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d\n", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}

int main() {
    int n, bufferSize;

    printf("Enter the size of the buffer: ");
    scanf("%d", &bufferSize);
    empty = bufferSize;

    printf("\n\n1. Producer\n2. Consumer\n3. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full!!\n\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty!!\n\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.");
        }
    }

    return 0;
}
