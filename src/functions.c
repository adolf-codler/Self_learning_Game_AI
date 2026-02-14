#include<stdio.h>
#include"../includes/functions.h"

int win_conditions[8][3]={{0,1,2},{0,4,8},{0,3,6},{1,4,7},{2,5,8},{2,4,6},{3,4,5},{6,7,8}};	


int encode(int board[9]) {
    int state = 0;
    int p = 1;
    for(int i = 0; i < 9; i++) {
        state += board[i] * p;
        p *= 3;
    }
    return state;
}

int isWin(int board[9], int win[8][3]){     // checking if the current cell is in win condition
  for(int k = 0; k<8;k++){
    int check = board[win[k][0]];
    if(check == board[win[k][1]] && check == board[win[k][2]]) return check;
  }
  return 0;
}

void tri(int k, int current_board[9]){
  for(int i = 8; i>=0; i--){
    current_board[i] = (k%3);
    k/=3;
  }
  return;
}

void pboard(char board[9]){	// printing board	
  for(int i = 0; i<9;i++){
      if(i%3==0 && i>0){
	printf("|\n");
      }
      printf("| %c ",board[i]);
  }
  printf("|\n");
}

int best_move(int state, double q[][9], int board[9]){
  double max = -1e9;
  int bm = -1;
  for(int i = 0; i<9; i++){
    if(board[i]!=0) continue;
    if(q[state][i]>max){
      max=q[state][i];
      bm=i; 
    }
  }
  if (bm == -1) {
    for (int i = 0; i < 9; i++) {
      if (board[i] == 0) return i;
    }
  }
  return bm;
}
