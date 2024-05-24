#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, full, empty;
int x = 0;
int bufferSize;

void* producer(void* arg) {
    if (sem_trywait(&empty) == 0) {  // Try to wait if the buffer is full
        sem_wait(&mutex);  // Enter critical section

        x++;
        printf("\nProducer produces the item %d\n", x);

        sem_post(&mutex);  // Leave critical section
        sem_post(&full);   // Increase the count of full slots
    } else {
        printf("Buffer is full!!\n\n");
    }

    return NULL;
}

void* consumer(void* arg) {
    if (sem_trywait(&full) == 0) {   // Try to wait if the buffer is empty
        sem_wait(&mutex);  // Enter critical section

        printf("\nConsumer consumes item %d\n", x);
        x--;

        sem_post(&mutex);  // Leave critical section
        sem_post(&empty);  // Increase the count of empty slots
    } else {
        printf("Buffer is empty!!\n\n");
    }

    return NULL;
}

int main() {
    int n;
    pthread_t tid1, tid2;

    printf("Enter the size of the buffer: ");
    scanf("%d", &bufferSize);

    // Initialize semaphores
    sem_init(&mutex, 0, 1);  // Binary semaphore for critical section
    sem_init(&full, 0, 0);   // Counts the number of full slots
    sem_init(&empty, 0, bufferSize);  // Counts the number of empty slots

    printf("\n\n1. Producer\n2. Consumer\n3. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                pthread_create(&tid1, NULL, producer, NULL);
                pthread_join(tid1, NULL);
                break;
            case 2:
                pthread_create(&tid2, NULL, consumer, NULL);
                pthread_join(tid2, NULL);
                break;
            case 3:
                sem_destroy(&mutex);
                sem_destroy(&full);
                sem_destroy(&empty);
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
