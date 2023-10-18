#include <stdio.h>
#include "functions.h"
// keeps the variable ITEMS as integer 51 throughout the program
#define ITEMS 51

int main(int argc, char* argv[])
{
    int month_data[ITEMS][argc];   // creates a month_data array with the items and number of values as parameters
    for (int i = 1; i < argc; i++) // loops through the number of values in the array
    {
        for (int j = 1; j < ITEMS; j++) // loops through all the items in the array
        {
            month_data[i][j] = 0; // declares month_data[][] array to 0 so it can be used in the for-loop
            if (i = 0)
            {                         // checks if then the value is equal to 0
                month_data[i][j] = j; // sets month_data[][] to j which is the item
            }
        }
    }

    int new_item;
    float cost;

    // loop over all months
     int numMonths = argc - 1;
    for (int i = 1; i < numMonths; i++)
    {
        FILE *f1 = fopen("argv[i + 1]", "r");

        // load month data
        while (fscanf(f1, "%d %f", &new_item, &cost) > 0)
        {
            month_data[new_item][i + 1] = month_data[new_item][i + 1] + 1;
            month_data[new_item][0] = new_item;
            if (new_item > 50)
            {
                printf("%d\n", new_item);
            }
        } // end reading file
        fclose(f1);
    }
   // end loop over months

    // load sales data
    float

    // call all 3 functions here
    get_totals(month_data, 51, 7);         // calls function for getting the total number of sales for each item
    get_profits(month_data, 51, 7, money); // calls the funnction for getting the revenue of each item
    top_earner(month_data, 51, 7, money);  // calls the functions for getting the top 10 highest revenues
}