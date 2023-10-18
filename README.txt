Name: Vivek Reddy Kasireddy 
Date: 02/06/23 
Homework 3 - Sales Report 

Summary: 
The purpose of the program keeping track of all the sales and analyze the sales reports for the last 6 month. 
The main file was provided by the professor as a starter code which includes a 50 X 7 array which stores the 
data of ints where the first column is the item code and the next 6 columns are the data for each month. It
also includes a second 50 X 2 array of floats to store the cost and the price of each item. The program will use 
input files to get the data from and use it store the output into the output files. The first function
produces a list of each item and the total number of sales for the item in an output file 'Total_sales.txt'. The 
second function contains the total sales, total cost, amount earned and profit for each item and prints it into
the output file 'Profits.txt'. The third function produces the top 10 items with the highest revenue which was 
calculated in the get_profits function. To save the files to the right folder, I used C:\Users\Vivek\Desktop\
Term C\CS_2303_Projects\Homework\Homework 3. The biggest diificulty I had with writing my functions for the program 
is for the third function I could not figure out how to find the max(highest) revenue and compare that to a variable 
to check for the next highest revenue. 

To compile: 
gcc analysis.c sales_report.c

To execute: 
ming32-make 
.\analysis.exe 

Sources: 
I have discussed the assignment details with Jahnavi Prudhivi and for the overall brainstorming for the assigment. 
I have went to office hours along with Jahnavi to get help on developing our functions for the program. The SA has 
helped me figure out how the logic will be and gave me a better understanding of how the function works. I have figured 
out function 1 completely on my own but re-clarified any doubts regarding them with the SA. For function 2, I got help 
from Professor Mortensen and I realized that I could reuse the logic from the previous function in a new function to avoid 
any sort of complications. For the third function I have discussed with Jahnavi Prudhivi about the logic and the SA during 
the office hours helped figure out where my problem was regarding the logic. 