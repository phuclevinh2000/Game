//
//  main.c
//  tic tac toe
//
//  Created by Le Vinh Phuc on 30/08/2020.
//  Copyright © 2020 Le Vinh Phuc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int choice, player;

int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int GameStatus;
    
    char mark;
    
    player = 1;
    
    do
    {
        displayBoard();
        
        //change turn
        player = (player % 2) ? 1 : 2;
        
        //get input
        printf("Player %d, enter a number ", player);
        scanf("%d ", &choice);
        
        //set the correct character based on player turn
        mark=(player == 1) ? 'X': 'O';
        
        markBoard(mark);
        
        GameStatus = checkForWin();
        
        player++;
        
    }while( GameStatus == -1);
    
    if(GameStatus == 1)
        printf("player %d win\n", --player);
    else printf("draw");
    
    return 0;
}

/*
 FUNCTION TO RETURN GAME STATUS
 1 FOR GAME IS OVER WITH RESULT
 -1 FOR GAME IS IN PROGESS
 0 FOR GAME IS OVER AND NO RESULT
 */
int checkForWin()
{
    int ReturnValue = 0;
    
    if(square[1] == square[2] && square[2] == square[3])
    {
        ReturnValue = 1;
    }
    else if(square[4] == square[5] && square[5] == square[6])
    {
        ReturnValue = 1;
    }
    else if(square[7] == square[8] && square[8] == square[9])
    {
        ReturnValue = 1;
    }
    else if(square[1] == square[4] && square[4] == square[7])
    {
        ReturnValue = 1;
    }
    else if(square[2] == square[5] && square[5] == square[8])
    {
        ReturnValue = 1;
    }
    else if(square[3] == square[6] && square[6] == square[9])
    {
        ReturnValue = 1;
    }
    else if(square[1] == square[5] && square[5] == square[9])
    {
        ReturnValue = 1;
    }
    else if(square[3] == square[5] && square[5] == square[7])
    {
        ReturnValue = 1;
    }
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != 8 && square[9] != '9')
    {
        ReturnValue = 0; //the game is done when every number is done
    }
    else ReturnValue = -1;
    
    return ReturnValue;
}

/*
 DISPLAY THE CONTENT IN THE BOARD
 */
void displayBoard()
{
    system("cls");  //clear the screen
    
    printf("\nTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");
    printf("     l     l     \n");
    printf("  %c  l  %c  l  %c  \n", square[1], square[2], square[3]);
    printf("_____l_____l_____\n");
    printf("     l     l     \n");
    printf("  %c  l  %c  l  %c  \n", square[4], square[5], square[6]);
    printf("_____l_____l_____\n");
    printf("     l     l     \n");
    printf("  %c  l  %c  l  %c  \n", square[7], square[8], square[9]);
    printf("     l     l     \n\n");
}

/*
 SET THE BOARD WITH CORRECT CHARACTER, X AND O
 */

void markBoard(char mark)
{
    if(choice == 1 && square[1]=='1')
        square[1] = mark;
    else if(choice == 2 && square[2]=='2')
        square[2] = mark;
    else if(choice == 3 && square[3]=='3')
        square[3] = mark;
    else if(choice == 4 && square[4]=='4')
        square[4] = mark;
    else if(choice == 5 && square[5]=='5')
        square[5] = mark;
    else if(choice == 6 && square[6]=='6')
        square[6] = mark;
    else if(choice == 7 && square[7]=='7')
        square[7] = mark;
    else if(choice == 8 && square[8]=='8')
        square[8] = mark;
    else if(choice == 9 && square[9]=='9')
        square[9] = mark;
    else
    {
        printf("Invalid move");
        
        player--;
        getchar();
    }
}


