#include <stdio.h>
#include <stdlib.h>
#define MAX 50 //maximum elements that can be stored inside the array

void bubbS(int arr[], int len) //bubble sort for sorting the request array
{
    int i, j;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j]; //swapping working
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
    }
}

int main()
{
    int cylinders, n, start; //variables to store the number of cylinders, number of requests and the head pointer value
    int req[MAX];            //array to store the disk requests
    scanf("%d", &cylinders); //taking number of cylinders as the input from the user
    scanf("%d", &start);     //taking the head pointer value as the input from the user
    scanf("%d", &n);         //taking number of requests as the input from the user
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]); //taking the disk requests one by one from the user as input
    }
    req[n] = start; //also including the head pointer value in the requests array

    int len = n + 1;

    bubbS(req, len); //sorting the array in ascending order

    int rightarr[MAX]; //array to store the elements in right to the head value
    int leftarr[MAX];  //array to store the elements in left to the head value

    int c1 = 0, c2 = 0; //counters for both the above arrays

    for (i = 0; i < len; i++)
    {
        if (req[i] > start)
        {
            rightarr[c1] = req[i]; //filling elements in the right sub array
            c1++;
        }

        if (req[i] < start)
        {
            leftarr[c2] = req[i]; //filling elements in the left sub array
            c2++;
        }
    }

    rightarr[c1] = cylinders - 1; //also inclduing the last value in the right sub array
    int right_len = c1 + 1;

    int first_diff = abs(start - rightarr[0]); //taking out the absolute difference between the head value and the first element of the right sub array

    int rightdiffarr[MAX]; //array to store differences of right sub array

    rightdiffarr[0] = first_diff; //storing the first difference in the array

    int d1 = 1;

    for (i = 0; i < right_len; i++)
    {
        if (i < right_len - 1)
        {
            rightdiffarr[d1] = abs(rightarr[i] - rightarr[i + 1]); //taking out all the differences from the right sub array and storing them into separate array
            d1++;
        }
    }

    int last_diff = abs((cylinders - 1) - leftarr[c2 - 1]); //taking out the absolute difference between the last value and the last element of the left sub array

    int leftdiffarr[MAX]; //array to store differences of left sub array

    leftdiffarr[0] = last_diff; //storing the last difference in the array

    int d2 = 1;

    for (i = c2 - 1; i >= 0; i--)
    {
        if (i >= 1)
        {
            leftdiffarr[d2] = abs(leftarr[i] - leftarr[i - 1]); //taking out all the differences from the left sub array and storing them into separate array
            d2++;
        }
    }
    int t1 = 0, t2 = 0;

    for (i = 0; i < d2; i++)
    {
        t1 = t1 + leftdiffarr[i]; //taking out the sum of all the elements in the array containing differences of the left sub array
    }

    for (i = 0; i < d1; i++)
    {
        t2 = t2 + rightdiffarr[i]; //taking out the sum of all the elements in the array containing differences of the right sub array
    }

    int tsd = t1 + t2; //totalling the total seek distance

    printf("%d\n", tsd); //printing the total seek distance

    return 0;
}