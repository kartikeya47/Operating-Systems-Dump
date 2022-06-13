#include <stdio.h>

//Global Variables

int need_arr[30][30]; //array to store the needs
int arr1[30][30];     //array to store allocations
int arr2[30][30];     //array to store maximum needs
int arr3[30];         //array to store available resources

int executed[30]; //array to store status of each process

int processes[30]; //array to store safe sequence of processes if any

int safety_algo(int num, int m) //this is the safety algorithm function that checks whether system is in safe state or unsafe state
{
    int i, j;
    int need[30]; //array to store current needs
    int d = 0;
    for (i = 0; i < m; i++)
    {
        need[i] = arr3[i]; //copying content of available resources array in current needs array
    }
    for (i = 0; i < 30; i++)
    {
        executed[i] = 0; //setting all the data in the status array as 0
    }
    while (d < num) //while loop runs for each process
    {
        int status = 0;
        for (i = 0; i < num; i++)
        {
            if (executed[i] == 0) //if the process has not executed
            {

                for (j = 0; j < m; j++)
                {
                    if (need[j] < need_arr[i][j]) //checking if required resources are more than the available resources or not
                    {
                        break;
                    }
                }
                if (j == m) //if all the required resources gets allocated to the process
                {
                    for (j = 0; j < m; j++)
                    {
                        need[j] = need[j] + arr1[i][j]; //adding the allocation and available resources
                    }

                    processes[d++] = i;
                    executed[i] = 1;
                    status = 1; //setting status of fully executed process as 1
                }
            }
        }
        if (status == 0) //if status is 0, that means the process could not be executed and system is in unsafe state
        {
            printf("System is in the Unsafe State\n");
            return 0;
        }
    }

    printf("System is in the Safe State\n");

    printf("Safe Sequence: \n"); //if all the processes executed, then system is in safe state
    for (i = 0; i < num; i++)
    {
        printf("Process: %d\n", processes[i]);
    }
}

int main()
{
    int i, j; //loop variables
    int num;
    int m;

    printf("Enter the number of processes: \n");
    scanf("%d", &num); //taking number of processes as input
    printf("Enter the number of resource types: \n");
    scanf("%d", &m); //taking number of resources as input

    int ri;

    int r_instances[100]; //array to store instances of each resource
    for (i = 0; i < m; i++)
    {
        printf("Enter the number of instances for resource type %d: \n", i + 1);
        scanf("%d", &ri); //taking instances of each resource as an input
        r_instances[i] = ri;
    }

    int alloc;

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter number of resource instances for allocation of process %d: ", i);
            scanf("%d", &alloc); //taking allocation instances of each resource as an input
            arr1[i][j] = alloc;
        }
    }
    int max_n;

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Enter number of maximum resources required for completion of process %d: ", i);
            scanf("%d", &max_n); //taking maximum required instances of each resource as an input
            arr2[i][j] = max_n;
        }
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter the available number of resources for resource type %d: ", i + 1);
        scanf("%d", &arr3[i]); //taking available instances of each resoruce as an input
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < m; j++)
        {
            need_arr[i][j] = arr2[i][j] - arr1[i][j]; //(Max Need - Allocation Instances) gives us Needs of a Process
        }
    } 

    if (safety_algo(num, m) != 0) //calling the safety algorithm
    {

        int p_number, arr[30];
        printf("Enter the Process Number of the process that wants resources: "); //Taking process number as input
        scanf("%d", &p_number);

        for (i = 0; i < m; i++)
        {
            printf("Enter how many resources does the process want for each resource type %d: ", i + 1);
            scanf("%d", &arr[i]); //taking number of instances of each resource type that the process wants as an input
        }

        for (i = 0; i < m; i++)
        {
            if (need_arr[p_number][i] < arr[i] || arr[i] > arr3[i]) //if the process wants more resources than are available, it cannot get them
            {
                printf("Process could not be given the Resources\n");
                break;
            }
        }

        if (i == m) //if the process gets the required resources then it can execute
        {
            for (i = 0; i < m; i++)
            {
                arr1[p_number][i] = arr1[p_number][i] + arr[i];
                arr3[i] = arr3[i] - arr[i];
                need_arr[p_number][i] = need_arr[p_number][i] - arr[i];
            }

            safety_algo(num, m); //again calling the safety algorithm to check the state of the system after the new request of a process
        }
    }
    return 0;
}