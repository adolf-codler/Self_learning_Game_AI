#ifndef play_h
#define play_h


extern int win_conditions[8][3];

int encode(int board[9]);
void tri(int k, int current_board[9]);
int isWin(int board[9], int win[8][3]);
int best_move(int state, double q[][9], int board[9]);
void pboard(char board[9]);

#endif

