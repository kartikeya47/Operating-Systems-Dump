#include <stdio.h>

int main()
{
      int len = 10000;
      int i, n;                     //loop variable 'i'
      int sum = 0, tempvar, c = 0;  //sum variable, counter variable
      int tq;                       //variable for storing time quantum value
      int arrival[len], burst[len]; //arrays for storing arrival times and burst times
      int sort_t[len];              //dummy array for storing orignal burst times

      printf("Enter the No. of process: \n"); //taking number of processes as input
      scanf("%d", &n);

      tempvar = n; //tempvar stores orignal total number of processes

      int wait_arr[len];
      int turn_arr[len];
      int c1 = 0, c2 = 0;

      for (i = 0; i < n; i++)
      {
            printf("Enter the Arrival Time of Process %d: \n", i + 1);
            scanf("%d", &arrival[i]); //Taking arrival time as input
            printf("Enter the Corresponding Burst Time of Process %d: \n", i + 1);
            scanf("%d", &burst[i]); //Taking burst ts time input
            sort_t[i] = burst[i];
      }

      printf("Enter the Time Quantum: \n");
      scanf("%d", &tq); //taking time quantum as input

      int waiting = 0, turnaround = 0;

      for (sum = 0, i = 0; tempvar != 0;)
      {
            if (sort_t[i] <= tq && sort_t[i] > 0) //checking whether BT of a Process is less than or equal to TQ or not
            {
                  sum = sum + sort_t[i];
                  sort_t[i] = 0;
                  c = 1;
            }
            else if (sort_t[i] > 0) //if BT is greater than TQ
            {
                  sort_t[i] = sort_t[i] - tq; //process executing for only the given TQ inspite of greater BT
                  sum = sum + tq;
            }
            if (sort_t[i] == 0 && c == 1) //if BT of a process is equal to 0
            {
                  tempvar--;
                  waiting = waiting + sum - arrival[i] - burst[i]; //Calculating the WT with formula
                  wait_arr[c1] = sum - arrival[i] - burst[i];
                  c1++;
                  turnaround = turnaround + sum - arrival[i];      //Calculating the TT with formula
                  turn_arr[c2] = sum - arrival[i];
                  c2++;
                  c = 0;
            }
            if (i == n - 1)
            {
                  i = 0;
            }
            else if (arrival[i + 1] <= sum) //if arrival time is less than or equal to the total executed time quantums of time
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
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