/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    //Creating a time variable
    time_t t;
    //Initilization
    srand((unsigned)time(&t));
    //Declearation Random_Number
    int random_Number = rand()%21;

    //Declearation Other Variabls
    int User_Number ;

    //Outputting Title of The Game With declamer
    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess\n");
    printf("Then Lets Start The GAME!!!!!!\n");

    //Starting loop
    for (int tries = 5 ;tries >= 1; tries--)
    {
    printf("You have %i tries left\n",tries);
    printf("Enter a  guess :");
    scanf("%d", & User_Number);
    //Nasted if_else loop
    if (User_Number <= 20)
    {
      if (User_Number  == random_Number)
      {
      printf("Congratulations You guessed it\n");
      break;
      }
      if(User_Number > random_Number)
      printf("Sorry %d is worng. My number is less then that\n",User_Number);
      if(User_Number < random_Number)
      printf("Sorry %d is worng. My number is Greater then that\n",User_Number);

    }
    else
    {
    printf("The Number is between 0 and 20\n");
    printf("Please Try again\n");
    }
    //Ending nested if_else loop
    }
    printf("Hope You Enjoy The Game");
    return 0;
}
