// including libraries
#include<stdlib.h>
#include<stdio.h>
#include"../includes/functions.h"

int main(){
  //Getting Q table
  FILE *fb;
  fb = fopen("Q_table", "rb+");
  double Q[19683][9] ={};
  fread(Q, sizeof(double), 19683 * 9, fb);

  //variables
  int board[9] = {0,0,0,0,0,0,0,0,0};
  char vboard[9]= {'0','1','2','3','4','5','6','7','8'};
  int state;
  int place;
  int won;
  int states_played[9] = {};
  int moves_played[9] ={};
  int turns = 0;

  //main game loop
  for(int i = 0; i<9;i++){
    states_played[i] = encode(board);
    if(i % 2 == 0){
      pboard(vboard);
      scanf(" %d",&place);
      if(place >8 || place < 0 || vboard[place] == 'X' || vboard[place] == 'O'){
	printf("Give a valid input\n");
	i--;
	continue;
      }
      board[place] = 2;
      vboard[place] = 'X';
    }
    else{
      state = encode(board);
      place = best_move(state, Q, board);
      board[place] = 1;
      vboard[place] = 'O';
      printf("\n");
    }
    moves_played[i] = place;
    if(i>4){
      int w = isWin(board, win_conditions);
      if(w>0){
	won = w;
	break;
      }
    }
    turns++;
    system("clear");
  }
  pboard(vboard);
  if(won==2)printf("you won");
  else if(won ==1) printf("AI won");
  else printf("It's a draw");
    

  return 0;
}
