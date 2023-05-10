#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves)
{
  //sets the position in the array at 0 and the number of possible moves to 0
  int pos = 0;
  num_moves = 0;

  //checks 2 right and 1 up
  if(col + 2 < 5 && row - 1 >= 0)
  {
    if(board[row-1][col+2] == 0)
    {
      row_moves[pos] = row - 1;
      col_moves[pos] = col + 2;
      num_moves++;
      pos++;
    }
  }

  //checks 2 right and 1 down
  if(col + 2 < 5 && row + 1 < 5)
  {
    if(board[row+1][col+2] == 0)
    {
      row_moves[pos] = row + 1;
      col_moves[pos] = col + 2;
      num_moves++;
      pos++;
    }
  }

  //checks 2 down and 1 right
  if(col + 1 < 5 && row + 2 < 5)
  {
    if(board[row+2][col+1] == 0)
    {
      row_moves[pos] = row + 2;
      col_moves[pos] = col + 1;
      num_moves++;
      pos++;
    }
  }

  //checks 2 down and 1 left
  if(col - 1 >= 0 && row + 2 < 5)
  {
    if(board[row+2][col-1] == 0)
    {
      row_moves[pos] = row + 2;
      col_moves[pos] = col - 1;
      num_moves++;
      pos++;
    }
  }

  //checks 2 left and 1 down
  if(col - 2 >= 0 && row + 1 < 5)
  {
    if(board[row+1][col-2] == 0)
    {
      row_moves[pos] = row + 1;
      col_moves[pos] = col - 2;
      num_moves++;
      pos++;
    }
  }
  
  //checks 2 left and 1 up
  if(col - 2 >= 0 && row - 1 >= 0)
  {
    if(board[row-1][col-2] == 0)
    {
      row_moves[pos] = row - 1;
      col_moves[pos] = col - 2;
      num_moves++;
      pos++;
    }
  }

  //checks 2 up and 1 left
  if(col - 1 >= 0 && row -2 >= 0)
  {
    if(board[row-2][col-1] == 0)
    {
      row_moves[pos] = row - 2;
      col_moves[pos] = col - 1;
      num_moves++;
      pos++;
    }
  }

  //checks 2 up and 1 right
  if(col +1 < 5 && row - 2 >= 0)
  {
    if(board[row-2][col+1] == 0)
    {
      row_moves[pos] = row - 2;
      col_moves[pos] = col + 1;
      num_moves++;
      pos++;
    }
  }
}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours)
{
  //sets up all the stuff to check the possible moves and increases m by 1
  m++;
  board[row][col] = m;
  int row_moves[8];
  int col_moves[8];
  int numberOfMoves = 0;

  //checks to see all possible moves at the current position
  get_moves(row, col, row_moves, col_moves, numberOfMoves);

  //checks to see if the board is completely full
  if(m == 25)
  {
    //if the board is full, it will increment the number of tours and print the board
    num_tours++;
    print();
  }
  else if(numberOfMoves > 0)
  {
    //if the board is not full and there are possible moves, it goes through all possible moves in a recursive call of moves
    //and then sets the positions visited, to 0, or a open space on the boar
    for(int pos = 0; pos < numberOfMoves; pos++)
    {
      move(row_moves[pos], col_moves[pos], m, num_tours);
      board[row_moves[pos]][col_moves[pos]] = 0;
    }
  }

  //after each call, sets the current position to a open space on the board and decreases m by 1 
  board[row][col] = 0;
  m--;
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}
