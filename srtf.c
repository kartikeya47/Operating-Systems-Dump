#include <stdio.h>

int main()
{
      int len = 10000;
      int n;
      int arrival[len], burst[len]; //arrays for storing arrival times and burst times
      int burst_b[len];             //dummy array for storing the orignal burst times
      int i;                        //loop variable
      int short_burst;              //for storing the shortest burst time
      int c = 0;                    //counter variable
      int t;

      printf("Enter the number of Processes \n"); //taking number of processes as input
      scanf("%d", &n);

      for (i = 0; i < n; i++)
      {
            printf("Enter Arrival Time for process %d \n", i + 1);
            scanf("%d", &arrival[i]); //Taking arrival times as input
      }

      for(i = 0; i < n; i++)
      {
            printf("Enter Burst Time for Process %d \n", i + 1);
            scanf("%d", &burst[i]); //Taking burst times as input
            burst_b[i] = burst[i];
      }

      burst[9] = 9999; //marking 9th index of the array as a reserved index for checking the shortest burst

      double average_wait = 0, average_turn = 0, end;

      int wait_arr[len];
      int turn_arr[len];
      int c1=0, c2=0;

      for (t = 0; c != n; t++)
      {
            short_burst = 9; //this is the same number that we kept as a reserved index
            for (i = 0; i < n; i++)
            {
                  if (arrival[i] <= t && burst[i] < burst[short_burst] && burst[i] > 0) //checking the shortest burst time per second one - by - one
                  {
                        short_burst = i;
                  }
            }
            burst[short_burst]--;
            if (burst[short_burst] == 0) //if the burst time of a process exhausts, it means its full execution has completed
            {
                  c++;
                  end = t + 1;
                  average_wait = average_wait + end - arrival[short_burst] - burst_b[short_burst]; //Calculating the Waiting Time with its formula
                  wait_arr[c1] = end - arrival[short_burst] - burst_b[short_burst];
                  c1++;
                  average_turn = average_turn + end - arrival[short_burst];                        //Calculating the Turnaround Time with its formula
                  turn_arr[c2] = end - arrival[short_burst];
                  c2++;
            }
      }

      double waiting, turnaround;

      for (i = 0; i < n; i++)
      {
            printf("WT of P%d %d \n", (i + 1), wait_arr[i]); //printing WT of each process
      }

      for (i = 0; i < n; i++)
      {
            printf("TAT of P%d %d \n", (i + 1), turn_arr[i]); //printing TT of each process
      }

      printf("Execution order of processes from Gantt chart.\n");

      waiting = (double)average_wait / n; //Calculating the average Waiting Time
      printf("Average Waiting Time: %f\n", waiting);
      turnaround = (double)average_turn / n; //Calculating the average Turnaround Time
      printf("Average Turnaround Time: %f\n", turnaround);
      
      return 0;
}