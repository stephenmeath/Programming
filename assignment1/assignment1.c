/*
Program for a menu driven mathematics quiz game.
Author: Stephen Meath
16/11/2021
*/

#include <stdio.h>

int main()
{
    char opt = '0';
    int questioncount = 0;
    char questions[5][22] = {
        {"1. What's 9 + 10?"},
        {"2. What's 4 x 4?"},
        {"3. What's 10 x 42?"},
        {"4. What's 16 / 2?"},
        {"5. What's 300 - 257?"}
    };
    int answers[5] = {19,16,420,8,43};
    int answer = 0;
    int quizstatus = 0;
    int correct = 0;
    int incorrect = 0;

    do //do while loop to continuously display the menu until option 4 is selected
    {
        printf("\n1. Enter the number of questions to be asked for this round of the quiz\n");
        printf("2. Play\n");
        printf("3. Display the number of questions that were answered correctly and incorrectly for this round\n");
        printf("4. Exit program\n\n");

        scanf("%c", &opt);
        while (getchar() != '\n'); //ignores enter as the char and takes characters as inputs and prevents the program from looping

        switch(opt) //checks which option is selected
        {
            case '1': //Ask user to input number of questions and limit to that

            printf("\nEnter the number of questions to be asked for this round of the quiz (maximum of 5 questions allowed)\n\n");

            do //do while loop to prevent invalid inputs
            {
                scanf("%d", &questioncount); 
                while (getchar() != '\n');

                if ((questioncount < 1) || (questioncount > 5))
                {
                    printf("\nInvalid amount entered \nPlease enter a number between 1 and 5\n\n");
                }
            }
            while ((questioncount < 1) || (questioncount > 5));

            quizstatus = 0; //reset results and quiz status
            correct = 0;
            incorrect = 0;
            
            break; //breaks out of the switch
            
            case '2': //start the game
            
            if (quizstatus == 1) //prevents retaking the same quiz
            {
                printf("\nYou have already completed this round \nCheck your results with option 3 \nTo start a new round set the number of questions with option 1\n");

                break;
            }

            if (questioncount == 0) //prevents doing a quiz with no questions
            {
                printf("\nYou need to enter the number of questions to be asked for this round of the quiz\n");

                break;
            }

            for(int i = 0; i < questioncount; i++) //for loop automates question display and answer checking
            {
                printf("\n%s\n\n", questions[i]);

                scanf("%d", &answer);
                while (getchar() != '\n');

                if (answer == answers[i]) //tells the user if they got the answer right or not
                {
                    printf("\nCorrect\n");
                    correct++; //results are tallied up as questions are answered for efficiency
                }
                else
                {
                    printf("\nIncorrect, the answer is %d\n", answers[i]);
                    incorrect++;
                }
            }

            printf("\nQuiz completed! \nCheck your results with option 3\n");

            quizstatus = 1; //allows results to be checked

            break;
            
            case '3': //Show the number of questions that were answered correctly and incorrectly for this round
            
            switch(quizstatus) //switch checks if quiz has been completed
            {
                case 1: //tallied results are displayed

                printf("\nYou answered %d questions correctly and %d questions incorrectly\n", correct, incorrect);
                
                break;

                default: 

                printf("\nPlay the quiz first then check your results\n");
            }
            
            break;
            
            case '4': //ends the program "gracefully" :)

            printf("\nProgram ended\n\n");

            break;

            default: //stops messers from entering invalid inputs

            printf("\nInvalid input\n");
        }
    }
    while (opt != '4');

    return 0;

}