#include<stdio.h>
int main(){
  FILE *f;
  f = fopen("Q_table", "rb");
  double Q[19638][9] ={};

  fread(Q, sizeof(Q), 1, f);

  for(int i = 0; i <19683; i++){
    for( int j =0; j<9; j++){
      printf("%f, ",Q[i][j]);
    }
    printf("\n");
  }
  return 0;
}

