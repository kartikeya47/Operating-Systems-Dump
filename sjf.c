#include <stdio.h>

void main()
{
      int len = 10000;
      int i, j;                         //loop variables
      int n, sort_t, var_turn = 0;      //variables for array sorting
      int arrival[len], burst[len];     //arrays for storing arrival and burst times
      int turn_arr[len], wait_arr[len]; //arrays for storing turnaround and waiting times

      printf("Enter the No. of process: \n"); //taking number of processes as input
      scanf("%d", &n);

      for (i = 0; i < n; i++)
      {
            printf("Enter the Arrival Time of Process %d: \n", i + 1);
            scanf("%d", &arrival[i]); //Taking arrival times as input
            printf("Enter the Corresponding Burst Time of Process %d: \n", i + 1);
            scanf("%d", &burst[i]); //Taking burst times as input
      }
      for (i = 0; i < n; i++)
      {
            for (j = i + 1; j < n; j++)
            {
                  if (burst[i] > burst[j]) //As per SJF Condition, checking which burst time is the smallest(shortest)
                  {
                        sort_t = arrival[i];
                        arrival[i] = arrival[j];
                        arrival[j] = sort_t;
                        sort_t = burst[i];
                        burst[i] = burst[j];
                        burst[j] = sort_t;
                  }
            }
      }
      int min;
      min = arrival[0];
      int alpha;
      for (i = 0; i < n; i++)
      {
            if (arrival[i] < min)
            {
                  min = arrival[i]; //storing the minimum arrival time
                  alpha = i;        //index of the minimum arrival time from its array
            }
      }
      var_turn = min;
      int temporary[len];
      temporary[alpha] = var_turn + burst[alpha]; //Storing the total execution time
      var_turn = temporary[alpha];
      for (i = 0; i < n; i++)
      {
            if (arrival[i] != min) //Checking whether arrival time is within the specified arrival time that was stored above
            {
                  temporary[i] = burst[i] + var_turn; //Storing all the execution times
                  var_turn = temporary[i];
            }
      }

      double average_turn = 0, average_wait = 0;

      for (i = 0; i < n; i++)
      {
            turn_arr[i] = temporary[i] - arrival[i]; //Calculating turnaround time with its formula
            average_turn = average_turn + turn_arr[i];
            wait_arr[i] = turn_arr[i] - burst[i]; //Calculating waiting time with its formula
            average_wait = average_wait + wait_arr[i];
      }

      double turnaround = 0, waiting = 0;

      for (i = 0; i < n; i++)
      {
            printf("Waiting Time of Process %d is: %d \n", (i + 1), wait_arr[i]); //printing WT of each process
      }

      for (i = 0; i < n; i++)
      {
            printf("Turnaround Time of Process %d is: %d \n", (i + 1), turn_arr[i]); //printing TT of each process
      }

      waiting = (double)average_wait / n; //Gevar_turning the average Waiting Time
      printf("Average Waiting Time is: %f\n", waiting);
      turnaround = (double)average_turn / n; //Gevar_turning the average Turnaround Time
      printf("Average Turnaround Time is: %f\n", turnaround);

      return 0;
}