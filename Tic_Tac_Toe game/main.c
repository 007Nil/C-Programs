/**********************************************************
   This is TIC-TAC-TOE game designed by Sagnik Sarkar (nil)
   Date = 31.8.2018
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define Numbers 10


/**************************
Global Variable
**************************/
char blocks[Numbers] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void board_design ();
int  check_for_winer ();


int main()
{
    int player = 1;
    int game_status;
    int choice;


    char mark;
    do
    {
        board_design ();


        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && blocks[1] == '1')
            blocks[1] = mark;

        else if (choice == 2 && blocks[2] == '2')
            blocks[2] = mark;

        else if (choice == 3 && blocks[3] == '3')
            blocks[3] = mark;

        else if (choice == 4 && blocks[4] == '4')
            blocks[4] = mark;

        else if (choice == 5 && blocks[5] == '5')
            blocks[5] = mark;

        else if (choice == 6 && blocks[6] == '6')
            blocks[6] = mark;

        else if (choice == 7 && blocks[7] == '7')
            blocks[7] = mark;

        else if (choice == 8 && blocks[8] == '8')
            blocks[8] = mark;

        else if (choice == 9 && blocks[9] == '9')
            blocks[9] = mark;

        else
        {
            printf("Invalid move ");

            player--;
        }
        game_status =  check_for_winer ();

        player++;
    }while (game_status ==  -1);

    board_design ();

    if (game_status == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");


    return 0;
}  /****End of main Function*/

void board_design ()
{
  system("clear");
  printf("\n\n\tTic Tac Toe Game\n\n");
  printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", blocks[1], blocks[2], blocks[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", blocks[4], blocks[5], blocks[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", blocks[7], blocks[8], blocks[9]);

    printf("     |     |     \n\n");
}
/*********************************************

FUNCTION TO retuen_value GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int check_for_winer()
{
    int retuen_value;
    if (blocks[1] == blocks[2] && blocks[2] == blocks[3])
        retuen_value = 1;

    else if (blocks[4] == blocks[5] && blocks[5] == blocks[6])
        retuen_value = 1;

    else if (blocks[7] == blocks[8] && blocks[8] == blocks[9])
        retuen_value = 1;

    else if (blocks[1] == blocks[4] && blocks[4] == blocks[7])
        retuen_value = 1;

    else if (blocks[2] == blocks[5] && blocks[5] == blocks[8])
        retuen_value = 1;

    else if (blocks[3] == blocks[6] && blocks[6] == blocks[9])
        retuen_value = 1;

    else if (blocks[1] == blocks[5] && blocks[5] == blocks[9])
        retuen_value = 1;

    else if (blocks[3] == blocks[5] && blocks[5] == blocks[7])
        retuen_value = 1;

    else if (blocks[1] != '1' && blocks[2] != '2' && blocks[3] != '3' &&
        blocks[4] != '4' && blocks[5] != '5' && blocks[6] != '6' && blocks[7]
        != '7' && blocks[8] != '8' && blocks[9] != '9')

        retuen_value = 0;
    else
        retuen_value  = - 1;

        return retuen_value;
}

/**********************************
End Of The TIC_TAC_TOE Game Project
***********************************/
