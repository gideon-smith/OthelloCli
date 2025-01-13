#include <stdio.h>
#include <string.h>
int i = 0;
int ii = 0;
int board[8][8] = {
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,1,2,0,0,0},
{0,0,0,2,1,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};
int dir_test(int x_mod, int y_mod,int x,int y,int turn){

  int temp_board[8][8];
  
  memcpy(temp_board,board,sizeof(board));
  for(i = 0;i < 8;i++) {
    if(board[x][y] == turn && i == 1); {
    return(1);
    }
    if(board[x][y] == turn) {
      memcpy(board,temp_board,sizeof(temp_board));
      return(0);
    }
    board[x][y] = turn;
    if(x == 7 || x == 0 || y == 7 || y == 0) {
    return(1);
    break;
    }
    x = x + x_mod;
    y = y + y_mod;
  }
}
int move(int x,int y,int turn) {
  if(board[x][y] == 0) {
    dir_test(-1,-1,x,y,turn);
    dir_test(0,-1,x,y,turn);
    dir_test(1,-1,x,y,turn);
    dir_test(-1,0,x,y,turn);
    dir_test(0,0,x,y,turn);
    dir_test(1,0,x,y,turn);
    dir_test(-1,1,x,y,turn);
    dir_test(0,1,x,y,turn);
    dir_test(1,1,x,y,turn);
    return(dir_test(-1,-1,x,y,turn) * dir_test(0,-1,x,y,turn) * dir_test(1,-1,x,y,turn) * dir_test(-1,0,x,y,turn) * dir_test(0,0,x,y,turn) * dir_test(1,0,x,y,turn) * dir_test(-1,1,x,y,turn) * dir_test(0,1,x,y,turn) * dir_test(1,1,x,y,turn));
 }
else {
  return(1);
}


}

int render() {
  for (i = 0; i < 8;i++) {
  printf("%d  ", i + 1 );
   for (ii = 0; ii < 8;ii++) {
    printf("%d ",board[i][ii]);
   } 
  printf("\n");
  }
 printf("\n");
 printf("   1 2 3 4 5 6 7 8\n");
 i = 0;
 ii = 0;
 return(0);

}
int main() {
render();
move(3,5,1);

render();
return(0);
}
