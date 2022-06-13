#include <stdio.h>

int main()
{
    int page[50]; //array to store pages
    int dummy[20]; //dummy array to store the pages that have been referenced
    int counter = 0; //counter to store the actual number of page faults
    int f_size, i, j; //length of referencing string and also the size of the frame
    int counter1; //2nd counter
    int ind = 0, len;

    printf("Size of frame\n");
    scanf("%d", &f_size); //size of the frame, eg. - 3, 5, etc

    printf("Length of the reference string\n");
    scanf("%d", &len); //total number of pages to be referenced

    printf("Reference string\n");
    for (i = 0; i < len; i++)
        scanf("%d", &page[i]); //content of the input reference string

    dummy[ind] = page[ind];

    counter++;
    ind++;

     int rem, swapper; //variables for swapping while sorting
     int dum1[20], iter[20]; //dummy array

    for (i = 1; i < len; i++)
    {
        counter1 = 0;
        for (j = 0; j < f_size; j++)
        {
            if (page[i] != dummy[j]) //condition for checking whether the page is already present or not
                counter1++;
        }
        if (counter1 == f_size) //condition if the value was not in the frame
        {
            counter++;
            if (ind < f_size) //condition if the value was not in the frame
            {
                dummy[ind] = page[i]; //add page to the dummy frame array
                ind++; //increment the array's index
            }
            else
            {
                for (rem = 0; rem < f_size; rem++)
                {
                    iter[rem] = 0;
                    for (j = i - 1; j < len; j--)
                    {
                        if (dummy[rem] != page[j]) //checking for the least recently used
                            iter[rem]++;
                        else
                            break;
                    }
                }
                for (rem = 0; rem < f_size; rem++)
                    dum1[rem] = iter[rem];
                for (rem = 0; rem < f_size; rem++)
                {
                    for (j = rem; j < f_size; j++)
                    {
                        if (dum1[rem] < dum1[j]) //sorting the dummy array with the help of swapping technique
                        {
                            swapper = dum1[rem];
                            dum1[rem] = dum1[j];
                            dum1[j] = swapper;
                        }
                    }
                }
                for (rem = 0; rem < f_size; rem++)
                {
                    if (iter[rem] == dum1[0])
                        dummy[rem] = page[i];
                }
            }
        }
    }

    printf("Page Faults\n%d", counter); //displaying the total number of page faults

    return 0;
}