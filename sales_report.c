#include <stdio.h>

// Totals Function
/*****************************************************************
 * get_totals
 * create Total_sales.txt that contains a list of each item
 * and the total number of sales for the item.
 *         Input: month_data[][] array, int rows and int columns 
 *                The array use the data from the input files 
 *                Jan_data.txt
 *                Feb_data.txt
 *                March_data.txt
 *                April_data.txt
 *                May_data.txt
 *                June_data.txt
 *          Output: Puts the data in the output file
 *                  'Total_sales.txt'
 *          Returns: nothing (void)
 *
 *******************************************************************/

void get_totals(int md[][7], int row, int col) // takes parameters month_data array, int row (51), and int col (7)
{
    FILE *ft;                           // create a pointer file
    ft = fopen("Total_sales.txt", "w"); // opens the output file "Total_sales.txt" and writes in it

    // nested for-loop

    for (int i = 1; i < row; i++) // for loop for going through all the row till 51
    {
        int total_sales = 0;          // sets the variable as 0 so it can be used later
        for (int j = 1; j < col; j++) // for loop for going through the columns which are the 6 months plus the itemCode
        {
            total_sales = total_sales + md[i][j]; // setting total_sales are total number of sales for each item
        }
        fprintf(ft, "%5d %5d\n", md[i][0], total_sales); // prints the row and the total_sales in the file
    }
    fclose(ft); // closes the file
}

// Profits Function
/*****************************************************************
 * get_profits
 * creates Profits.txt that contains the total sales, total cost,
 * amount earned and profit for each item (cost – sales price)*items sold
 *         Input: month_data[][] array, int rows and int columns and money[][] array 
 *                The array use the data from the input files 
 *                Jan_data.txt
 *                Feb_data.txt
 *                March_data.txt
 *                April_data.txt
 *                May_data.txt
 *                June_data.txt
 *                Costs.txt 
 *          Output: Puts the data in the output file
 *                  'Total_sales.txt'
 *          Returns: nothing (void)
 *
 *******************************************************************/

void get_profits(int md1[][7], int row, int col, float money[][2]) // takes parameters month_data array, int row (51), and int col (7), and money array which has cost and sales price
{
    FILE *fp;                                               // create a pointer file
    fp = fopen("Profits.txt", "w");                         // opens the output file "Profit.txt" and writes in it
    int total_sales;                                        // variable to store the total number of sales
    float revenue;                                          // declares the revenue variable
    fprintf(fp, "Item       #   Sales    Cost Revenue \n"); // prints the titles for the txt file

    // Nested for-loop
    for (int i = 1; i < row; i++) // loops over the 51 rows and through each item
    {
        total_sales = 0;              // intializes the total number of sales as 0 so it can be used later
        for (int j = 1; j < col; j++) // loops over the col starting from 1 and not 0 because 1 is the first month Jan, and 0 is the ItemCode
        {
            total_sales = total_sales + md1[i][j]; // this will the total number of sales for each item

            revenue = (money[i][0] - money[i][1]) * total_sales; // this will calculate for the profit by mutiplying total_sales to the cost deducted by the purchase
        }
        fprintf(fp, "%4d %7d %7.2f %7.2f %7.2f\n", i, total_sales, money[i][0] * total_sales, money[i][1] * total_sales, revenue); // prints the item (i), total number of sales, cost, sales price, and revenue
    }
    fclose(fp); // closes the output file
}

// Top Earner Function
/*****************************************************************
 * top_earner
 * creates create Top_earners.txt which should list the 10 items
 * with the highest revenue.
 *         Input: month_data[][] array, int rows and int columns and money[][] array 
 *                The array use the data from the input files 
 *                Jan_data.txt
 *                Feb_data.txt
 *                March_data.txt
 *                April_data.txt
 *                May_data.txt
 *                June_data.txt
 *                Costs.txt 
 *          Output: Puts the data in the output file
 *                  'Total_sales.txt'
 *          Returns: nothing (void)
 *
 *******************************************************************/
void top_earner(int md2[][7], int row, int col, float money[][2]) // takes parameters month_data array, int row (51), and int col (7), and money array which has cost and sales price
{

    FILE *fe;                           // create a pointer file
    fe = fopen("Top_earners.txt", "w"); // opens the output file "Top_Earners" and writes in it
    int total_sales;                    // initialize the total number of sales variable
    float revenue;                      // initialize the revenue variable
    int top_item = 0;                   // initialize top_item as variable for storing the itemCode
    float max_rev = 0;                  // initialize max_rev as variable for holding the current highest revenue value
    int max_sale = 0;                   // initialize variable for holding the current sale
    fprintf(fe, "Item   #  Revenue\n"); // print the label for the list in the output file

    for (int i = 0; i < 10; i++) // loops through the 10 highest revenues out of all the items in the rows (51)
    {
        for (int i = 1; i < row; i++) // loops over the 51 rows and through each item
        {
            total_sales = 0;              // intializes the total number of sales as 0 so it can be used later
            for (int j = 1; j < col; j++) // loops over the col starting from 1 and not 0 because 1 is the first month Jan, and 0 is the ItemCode
            {
                total_sales = total_sales + md2[i][j]; // this will the total number of sales for each item

                revenue = (money[i][0] - money[i][1]) * total_sales; // this will calculate for the profit by mutiplying total_sales to the cost deducted by the purchase
            }
            if (max_rev < revenue) // check for the highest revenue value out of all the items in the rows
            {
                top_item = i;           // set the variable as that item
                max_rev = revenue;      // set the variable as current highest revenue
                max_sale = total_sales; // set the variable as current sales
            }
        }
        fprintf(fe, "%4d %4d %6.2f\n", top_item, max_sale, max_rev); // prints the item, sales, and top 10 highest revenues
        money[top_item][0] = 0;                                      // make the cost zero so max revenue is not always the same and changes once it is done with the iteration
        max_rev = 0;                                                 // set max revenue back to 0 so it can find the next highest revenue
    }
    fclose(fe); // close the outpile file
}

float *readCosts(int numItems)
{
    FILE *fc = fopen("Costs.txt", "r");
    int *costs = malloc(numItems * sizeof(float));
    int itemCode;
    float cost;
    float purchase;

    for (int i = 0; i < numItems; i++)
    {
        while (fscanf(fc, "%d", "%f", "%f", &itemCode, &cost, &purchase) > 0)
        {
            costs[i] = cost; 
        }
    }
    return (float*)costs;
}

float *readPurch(int numItems)
{
    FILE *fc = fopen("Costs.txt", "r");
    int *purch = malloc(numItems * sizeof(float));
    int itemCode;
    float cost;
    float purchase;

    for (int i = 0; i < numItems; i++)
    {
        while (fscanf(fc, "%d", "%f", "%f", &itemCode, &cost, &purchase) > 0)
        {
            purch[i] = purchase;
        }
    }
    return (float*)purch;
}