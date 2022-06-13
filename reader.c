#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t lock; //for locking the critical section and also unlocking it
sem_t wrt; //write semaphore shared variable
int reader_no = 0; //number of readers already reading the data in the critical section

void *writeFunc() //Writer Function
{
	int i;
    	printf("Writer is Trying to enter the critical section\n");
    	sem_wait(&wrt); //writer enters critical section and becomes 0, so no reader can enter the critical section now
    	// Critical Section Begins
    	printf("Writer writing the data\n");
    	// Critical Section Ends
    	sem_post(&wrt); //writer leaves the critical section and now the reader can enter it
    	printf("Writer leaves the critical section\n");
}

void *readFunc() //Reader Function
{
	int j;
    	printf("Reader Trying to enter the critical section\n");
    	sem_wait(&lock); //reader enters the critical section and locks it so that other reader cannot enter it
    	reader_no = reader_no + 1; //count of the readers increases
    	if(reader_no == 1)
    	{
    		sem_wait(&wrt); //if the readers are atleast one, then lock the critical section for the writer
    	}
    	sem_post(&lock);
    	printf("Reader reading the data\n");
    	sem_wait(&lock);
    	reader_no = reader_no - 1; //since, reader has read the data, it will leave the critical section hence the count decreases
    	if(reader_no == 0)
    	{
    		sem_post(&wrt); //current reader leaves the critical section and unlocks it so that the writer can enter it now as there are 0 readers left
    	}
    	sem_post(&lock); //unlocks the critical section now,as reader leaves it
    	printf("Reader leaves the critical section\n");
}

int main()
{
    pthread_t read, write; //threads for reader and writer
	sem_init(&lock,0,1); //initialize lock as 1
	sem_init(&wrt,0,1); //initialize writer as 1
	pthread_create(&read, NULL, readFunc, NULL); //reader thread created
	pthread_create(&write, NULL, writeFunc, NULL); //writer thread created
	pthread_join(read, NULL); //join so that threads do not terminate and wait
	pthread_join(write, NULL); //join so that threads do not terminate and wait
}