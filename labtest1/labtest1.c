/*
Program to show The Fibonacci Series up to the number of terms entered by the user
Author: Stephen Meath
08/11/2021
*/

#include <stdio.h>

int main()
{
    int terms = 0;
    int i = 0;
    int prenum1 = 1;
    int prenum2 = 0;
    int curnum = 0;
    int select = 1;

    //menu
    printf("Welcome to The Fibonacci Series program\n");
    printf("Please enter your selection: \n1. Enter the number of terms to display in the sequence and display the sequence.\n2. End Program\n");
    
    scanf("%d", &select); 

    if(select == 1)
    {
        printf("Enter the number of terms");
        scanf("%d", &terms);
 
        for(i = 0; i < terms;  i++)
        {
            printf("%d, ", curnum);
            curnum = prenum1 + prenum2; 
            prenum1 = prenum2;
            prenum2 = curnum;
        }

    }
    if(select == 2);
    {
        printf("Program has been ended");
    }
    
    return 0;

}