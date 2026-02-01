// including libraries
#include<stdio.h>
#include"../includes/functions.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>


// main function
int main(){
  srand(time(NULL));	//seeding randon function with current time
  //variables
  double Q[19683][9]={};	

  //main training loop 
  for(long long int i = 0; i<10000000; i++){	//epochs
  int board[9] = {0,0,0,0,0,0,0,0,0};	//board where the game is happening
  int move_set[9] = {0,1,2,3,4,5,6,7,8}; //possible moves for the current game
  int won = 0;		// who won 1 for O, 2 for X
  int states[9] = {};	//the states from where the game has been through
  int moves[9] = {};	//move which have played throghout the game
  int turns = 0;	//how many turns has been played
    for(int j = 0; j<9; j++){	//turnwise play
      if(won) break;

      int move, random_move; //which move have to play from move_set; choosing a random index from the available moves
      random_move = rand() % (9-j);
      move = move_set[random_move];
      int temp = move_set[8-j];
      move_set[8-j]= move_set[random_move];
      move_set[random_move]= temp;

      states[j]=encode(board);	//storing current positon of the board
      moves[j]=move;	//the move played in the current position
      if(j%2==0) board[move] = 2;	//playing X
      else board[move] = 1;	//playing O

      //checking for win
      if(j>4){ 			
	int w = isWin(board, win_conditions);
	if(w>0){
	  won = w;
	  break;
	}
      }
      turns++;
    }
  
    //Updating Q values (fast win more q value, slow win less q value, fast loss less q value, slow loss more q value
    if(won == 2){ 	// if X won
      for(int c = 0; c<turns; c++){
	if(c%2==0) Q[states[c]][moves[c]] += 0.1*(1-(0.1*(1-c)));
	else Q[states[c]][moves[c]] -= 0.1*(1-(0.1*c));
      }
    }
    else{	// if O won
      for(int c = 0; c<turns; c++){
	if(c%2==0) Q[states[c]][moves[c]] -= 0.1*(1-(0.1*(1-c)));
	else Q[states[c]][moves[c]] += 0.1*(1-(0.1*c));
      }
    }
  }

  //saving the Q values in a binary file
  FILE *fb;
  fb = fopen("Q_table", "wb");

  fwrite(Q, sizeof(double), 19683 * 9, fb);

  fclose(fb);


  return 0;
}















