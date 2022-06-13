#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full; //empty represents number of filled blocks in the buffer, full represents number of vacant blocks
sem_t sema; //semaphore shared variable
int item; //data item
int buffer[50]; //buffer storage

void *producerFunc() //Producer function to produce an item
{
    int i;
    int j = 0;
    for(i = 0; i < 5; i++) //produce 5 items with for loop
    {
        sem_wait(&empty); //decrements empty count by 1
        sem_wait(&sema); //locks the critical section, so that other process cannot enter it
        // Critical Section Begins
        buffer[j] = i; //item produced and stored in the buffer
 		printf("Producer item is: %d\n", buffer[j]);
 		// Critical Section Ends
		sem_post(&full); //increments the count by 1
        sem_post(&sema); //unlocks the critical section again, as now the other process is allowed to enter it
        j = j + 1;
		if(j == 5)
		{
			j=0;
		}
    }
}

void *consumerFunc()
{
    int j;
    int t = 0;
    for(j = 0; j < 5; j++) //consumes 5 items with for loop
    {
        sem_wait(&full); //decrements empty count by 1
        sem_wait(&sema); //locks the critical section, so that other process cannot enter it
        // Critical Section Begins
		printf("Consumed Item is: %d\n", buffer[t]);
		// Critical Section Ends
		sem_post(&empty); //increments the count by 1
        sem_post(&sema); //unlocks the critical section again, as now the other process is allowed to enter it
        t = t + 1;
		if(t == 5)
		{
			t = 0;
		}
    }
}

int main()
{
    pthread_t prodt, cont; //producer thread and consumer thread
    sem_init(&empty, 1, 5); //initialize empty as 5
    sem_init(&full, 1, 0); //initialize full as 5
    sem_init(&sema, 1, 1); //initialize semaphore as 5
    pthread_create(&prodt, NULL, producerFunc, NULL); //creating producer thread
    pthread_create(&cont, NULL, consumerFunc, NULL); //creating consumer thread
    pthread_join(prodt, NULL); //join so that threads do not terminate and wait
    pthread_join(cont, NULL); //join so that threads do not terminate and wait
}