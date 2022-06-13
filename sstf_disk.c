#include <stdio.h>
#include <stdlib.h>
#define MAX 50 //maximum size of the request array

int main()
{

    int cylinders;
    printf("Total Number of Cylinders:\n");
    scanf("%d", &cylinders); //taking number of cylinders as the input

    int start; //head value
    printf("Current Head Position:\n");
    scanf("%d", &start); //taking head as the input

    int len;
    printf("Number of request\n");
    scanf("%d", &len); //taking no. of requests as the input

    int requests_arr[MAX]; //requests array
    int status_arr[MAX];   //status array to keep the status of the requests that have been serviced already

    printf("Queue of pending request\n");
    int i;

    for (i = 0; i < len; i++)
    {
        scanf("%d", &requests_arr[i]); //taking all the requests one by one as the input
        status_arr[i] = 0;             //filling the status array with all 0s initially
    }

    int buff; //variable to store temporary variables

    int counter = 0, total = 0; //counter and total seek time variables

    buff = start;

    int j;

    while (counter != len)
    {
        int buffer = 10000; //dummy variable
        int k = -1;

        for (j = 0; j < len; j++)
        {
            if (buff != requests_arr[j] && status_arr[j] == 0)
            {
                if (buffer > abs(buff - requests_arr[j])) //checking which distance is the shortest distance between the elements
                {
                    buffer = abs(buff - requests_arr[j]); //storing the smallest possible value found till yet
                    k = j;                                //also storing the positon of the smallest distance element
                }
            }
        }

        total = total + buffer; //totalling the seek time
        counter++;
        buff = requests_arr[k];
        status_arr[k] = 1; //updating the status array atotalording to the already serviced requests
    }

    printf("Total Seek time (distance):\n%d", total); //printing the total seek time

    return 0;
}