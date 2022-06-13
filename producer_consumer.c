#include <stdio.h>
int sem = 1, ff = 0, vac = 5, item = 0; //global variables that are shared among all the processes
int waitFunc(int sema) //wait function to decrement semaphore
{
    return (--sema);
}
int signalFunc(int sema) //signal function to increment semaphore
{
    return (++sema);
}
void producerFunc() //function that produces an item to be put inside the buffer
{
    sem = waitFunc(sem); //locks, so that other process cannot enter the critical section
    ff = signalFunc(ff);
    vac = waitFunc(vac);
    item++; //item count
    printf("Item Produced is: %d\n", item);
    sem = signalFunc(sem); //unlocks, so that other process can enter the critical section
}
void consumerFunc() //function that consumes an item from the buffer
{
    sem = waitFunc(sem); //locks, so that other process cannot enter the critical section
    ff = waitFunc(ff);
    vac = signalFunc(vac);
    printf("Item consumed is: %d\n", item);
    item--;                //item countss
    sem = signalFunc(sem); //unlocks, so that other process can enter the critical section
}
int main()
{
    int ch; //variable to store user's choice
    //Menu Options -
    printf("Enter Your Choice: \n");
    printf("1. Produce an Item\n");
    printf("2. Consume an Item\n");
    do //infinite loop
    {
        printf("Enter your choice:\n"); //taking user's choice as input
        scanf("%d", &ch);

        switch (ch) //switch case
        {
        case 1:
            if ((sem == 1) && (vac != 0)) //checking for overflow
                producerFunc();           //produces an item
            else
                printf("Buffer Storage is Full\n"); //diplays if buffer is full
            break;
        case 2:
            if ((sem == 1) && (ff != 0)) //checking for undeflow
                consumerFunc();          //consumes an item
            else
                printf("Buffer Storage is already Empty\n"); //diplays if buffer is empty
            break;
        default:
            printf("Wrong Choice\n");
        }
    } while (1);
    return 0;
}