#include <stdio.h>

int main()
{
  int len = 10000;
  int arrival[len], burst[len], priority[len]; //arrays for storing AT, BT and Priorities of all Processes
  int wait_arr[len], turn_arr[len];            //arrays for storing WT and TT of all Processes
  int i, j;                                    //Loop Variables
  int low, c = 0;                              //Counter Variable
  int t, n;

  printf("Enter the No. of process: \n"); //taking number of processes as input
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    printf("Enter the Arrival Time of Process %d: \n", i + 1);
    scanf("%d", &arrival[i]); //Taking arrival time as input
    printf("Enter the Corresponding Burst Time of Process %d: \n", i + 1);
    scanf("%d", &burst[i]); //Taking burst ts time input
    printf("Enter the Corresponding Priority of Process %d: \n", i + 1);
    scanf("%d", &priority[i]);
  }

  int execute[len]; //Dummy Array for storing orignal burst times
  int conclude_t = 0;

  for (i = 0; i < n; i++)
  {
    execute[i] = burst[i]; //Storing Burst Times in  Dummy Array
  }

  priority[9] = -1; //Marking index 9th of the array to keep a track for checking the highest priority

  for (t = 0; c != n; t++)
  {
    low = 9;
    for (i = 0; i < n; i++)
    {
      if (arrival[i] <= t && priority[i] > priority[low] && burst[i] > 0) //Checking priority of each process
      {
        low = i;
      }
    }
    burst[low]--;

    if (burst[low] == 0) //Checking whether a process has completed its full Burst Time or not
    {
      c++;
      conclude_t = t + 1;
      wait_arr[low] = conclude_t - arrival[low] - execute[low];
      turn_arr[low] = conclude_t - arrival[low];
    }
  }

  double waiting = 0, turnaround = 0;

  for (i = 0; i < n; i++)
  {
    waiting = waiting + wait_arr[i];       //Calculating Waiting Time
    turnaround = turnaround + turn_arr[i]; //Calculating Turnaround Time
  }

  double a_wait = 0, a_turn = 0;

  for (i = 0; i < n; i++)
  {
    printf("Waiting Time of Process %d is: %d \n", (i + 1), wait_arr[i]); //printing WT of each process
  }

  for (i = 0; i < n; i++)
  {
    printf("Turnaround Time of Process %d is: %d \n", (i + 1), turn_arr[i]); //printing TT of each process
  }

  a_wait = (double)waiting / n; //Calculating the average Waiting Time
  printf("Average Waiting t is: %f\n", a_wait);
  a_turn = (double)turnaround / n; //Calculating the average Turnaround Time
  printf("Average Turnaround t is: %f\n", a_turn);

  return 0;
}