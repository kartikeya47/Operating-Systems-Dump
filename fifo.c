#include <stdio.h>
#define MAX 50

int len;         //length of the reference string
int pages[MAX];  //array for storing pages
int frame_size;  //frame size
int fault_count; //counter for counting the number of page faults

int main()
{
    int i;

    printf("Size of frame\n"); //size of the frame, eg. - 3, 5, etc
    scanf("%d", &frame_size);

    printf("Length of the reference string\n"); //total number of pages to be referenced
    scanf("%d", &len);

    printf("Reference string\n"); //content of the input reference string
    for (i = 0; i < len; i++)
    {
        scanf("%d", &pages[i]);
    }

    int page_dummy[MAX]; //dummy array to store the pages that have been referenced

    int x, xy;

    xy = 0, x = 0;

    page_dummy[fault_count] = -1; //initializing all the values to -1

    int count; //counter variable for fault count
    int c;     // for storing the shifted value of the content of the string

    while (xy < len) //loop goes on till the reference string has finished
    {

        if (page_dummy[xy] = -1 && xy < frame_size) //condition for the frame being vacant
        {
            page_dummy[xy] = pages[xy]; //if page fault is there
            fault_count++;              // page fault counter
        }
        else
        {
            count = 0;
            for (x = 0; x < frame_size; x++)
            {

                if (page_dummy[x] != pages[xy]) //condition for checking whether the page is already present or not
                {
                    count++;
                }
            }
            if (count == frame_size) //condition if the value was not in the frame
            {
                fault_count++;
                for (x = 0; x < frame_size - 1; x++)
                {
                    c = page_dummy[x]; //now, after shifting the pages next pages are to be checked
                    page_dummy[x] = page_dummy[x + 1];
                    page_dummy[x + 1] = c;
                }
                // new pages to be inserted after the above process is completed
                page_dummy[frame_size - 1] = pages[xy];
            }
        }
        xy++; //increment the index variable for the dummy array
    }

    printf("Page Faults\n%d", fault_count); //displaying the total number of page faults

    return 0;
}