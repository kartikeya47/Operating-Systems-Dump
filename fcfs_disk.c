#include <stdio.h>
#include <stdlib.h>
#define MAX 50 //maximum size of the request array

int main()
{

    int i;
    int n;
    int requests_arr[MAX]; //requests array
    int start;             //head value
    int diff = 0;          //variable to store the difference
    int cylinders;
    printf("Total Number of Cylinders:\n");
    scanf("%d", &cylinders); //taking number of cylinders as the input
    printf("Current Head Position:\n");
    scanf("%d", &start); //taking head as the input
    printf("Number of request\n");
    scanf("%d", &n); //taking no. of requests as the input
    printf("Queue of pending request\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &requests_arr[i]); //taking all the requests one by one as the input
    }

    int t; //variable to store the sum (total seek time)

    t = abs(requests_arr[0] - start); //absolute difference of the head with the fist element in the array

    for (i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            diff = abs(requests_arr[i] - requests_arr[i + 1]); //abs diff. of all the elements one by one through for loop
            t = t + diff;
        }
    }

    printf("Total Seek time (distance):\n%d", t); //printing the total seek time

    return 0;
}