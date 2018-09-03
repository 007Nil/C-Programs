/*
 Author : Sagnik Sarkar

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
    printf("\nThis is a guessing game.\n");
    printf("\nI have chosen a number between 0 and 20 which you must guess\n");
    printf("\nThen Lets Start The GAME!!!!!!\n");

    //Starting loop
    for (int tries = 5 ;tries >= 1; tries--)
    {
    printf("\nYou have %i tries left\n",tries);
    printf("\nEnter a  guess :");
    scanf("%d", & User_Number);
    //Nasted if_else loop
    if (User_Number <= 20)
     {
     //Nested loop inside a nested loop
      if (User_Number  == random_Number)
      {
      printf("\nCongratulations You guessed it\n");
      break;
      }
      //Nested loop inside a nested loop
      if(User_Number > random_Number)
      printf("\nSorry %d is worng. My number is less then that\n",User_Number);
      //Nested loop inside a nested loop
      if(User_Number < random_Number)
      printf("\nSorry %d is worng. My number is Greater then that\n",User_Number);

      }
      else
      {
      printf("\nThe Number is between 0 and 20\n");
      printf("\nPlease Try again\n");
      }
    //Ending nested if_else loop
    }
    printf("\nMy selected Number was = %d\n",random_Number);
    printf("\nHope You Enjoy The Game\n");
    return 0;
}
