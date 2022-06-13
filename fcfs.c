#include <stdio.h>

int main()
{
  int len = 10000;
  int arrival[len], execute[len]; //Creating a dummy array for arrival time
  int a[len], b[len];             //Arrays for storing arrival times and burst times
  int n;
  int i, j; //loop variables

  printf("Enter the No. of process: \n"); //taking number of processes as input
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("Enter the Arrival Time of Process %d: \n", i + 1);
    scanf("%d", &a[i]); //Taking arrival times as input
    arrival[i] = a[i];
    printf("Enter the Corresponding Burst Time of Process %d: \n", i + 1);
    scanf("%d", &b[i]); //Taking burst times as input
  }

  int max = 0;
  int min;
  int lone = 0;

  int initiate = a[0]; //initiate takes in the first arrival time from the array

  for (i = 1; i < n; i++) //loops starts from '1' as 0th arrival timne has already been taken in initiate
  {
    if (a[i] < initiate) //takes out the minimum arrival time
    {
      initiate = a[i]; //Now, initiate would have the smallest arrival time value
    }
  }
  for (i = 0; i < n; i++)
  {
    if (max < a[i])
    {
      max = a[i]; //Storing the greatest arrival time
    }
  }
  int queue_arr[len], response[len];
  int k = 0;
  max = max + 1;
  int location;
  for (i = 0; i < n; i++)
  {
    min = max;
    for (j = 0; j < n; j++)
    {
      if (a[j] != -1)
      {
        if (a[j] < min)
        {
          min = a[j];   //Minimum arrival time less than 'min' is stored
          location = j; //location of that time from the array is stored
        }
      }
    }
    queue_arr[k] = location;    //inserting the locations into an array
    if (initiate < a[location]) //Checking how many processes are available for execution in a specific time
    {
      response[location] = initiate;
      lone = lone + a[location] - initiate;
      initiate = a[location];
      initiate = initiate + b[location];
      a[location] = -1;
      execute[location] = initiate;
    }
    else //When there were no processes piled up in a specific amount of time
    {
      response[location] = initiate;
      initiate = initiate + b[location];
      a[location] = -1;
      execute[location] = initiate;
    }
    k++; //Incrementing the array variable
  }

  int wait_arr[len], turn_arr[len]; //arrays for storing waiting times and turnaround times

  for (i = 0; i < n; i++)
  {
    turn_arr[i] = execute[i] - arrival[i]; //Calculating TAT with formula
    wait_arr[i] = turn_arr[i] - b[i];      //Calculating WT with formula
  }

  double average_turn = 0, average_wait = 0;
  double waiting = 0, turnaround = 0;

  for (i = 0; i < n; i++)
  {
    printf("Waiting Time of Process %d is: %d \n", (i + 1), wait_arr[i]); //printing WT of each process
  }

  for (i = 0; i < n; i++)
  {
    printf("Turnaround Time of Process %d is: %d \n", (i + 1), turn_arr[i]); //printing TT of each process
  }

  for (i = 0; i < n; i++)
  {
    average_wait = average_wait + wait_arr[i]; //Summing up all WTs
    average_turn = average_turn + turn_arr[i]; // Summing up all TATs
  }
  printf("\n");
  waiting = (double)average_wait / n; //Getting the average Waiting Time
  printf("Average Waiting Time is: %f\n", waiting);
  turnaround = (double)average_turn / n; //Getting the average Turnaround Time
  printf("Average Turnaround Time is: %f\n", turnaround);

  return 0;
}