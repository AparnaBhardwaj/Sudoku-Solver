#include <iostream>
#include <vector>
using namespace std;
const int N = 9;
void printBoard(const vector<vector<int>>& board) {
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cout << board[i][j]<<'.';
    }
    cout << endl;
  }
}
bool isSafe(int row,int col,vector<vector<int>>& board,int val) {
  for(int i=0;i<board.size();i++) {
    if(board[row][i] == val) {
      return false;
    }
  }
  for(int i=0;i<board.size();i++) {
    if(board[i][col] == val) {
      return false;
    }
  }
  int startRow = row - row%3;
  int startCol= col - col%3;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(board[i+ startRow][j+startCol] == val) {
        return false;
      }
    }
  }
  return true;
}

bool solveSudoku(vector<vector<int>>& board) {
  int row,col;
  bool emptycell = false;
  for(row=0;row<N;row++) {
    for(col=0;col<N;col++) {
      if(board[row][col] == 0) {
        emptycell = true;      
        break;
      }
    }
    if(emptycell) break;
  }
  if(!emptycell) return true;
  for(int val=1;val <= N;val++) {
    if(isSafe(row,col,board,val)) {
      board[row][col] = val;
      if(solveSudoku(board)) {
        return true;     
      }
      board[row][col]=0;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> board = {
  {6,8,0,4,0,3,0,5,0},
  {4,0,2,0,5,0,3,6,8},
  {5,9,3,6,7,8,0,0,4},
  {0,1,7,2,8,6,9,4,5},
  {8,0,9,5,0,4,2,0,7},
  {2,5,4,3,9,7,8,1,0},
  {7,0,0,8,3,1,5,9,2},
  {9,3,5,0,6,0,4,0,1},
  {0,2,0,9,0,5,0,7,3},
  };

  cout << "Original Sudoku Board:\n";
  printBoard(board);

  if(solveSudoku(board)) {
    cout << "\nSolved Sudoku Board:\n";
    printBoard(board);
  } else {
    cout << "\nNo solution exists\n";
  }
  return 0;
}



























