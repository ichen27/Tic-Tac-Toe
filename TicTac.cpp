#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int check_win(char [], string, string); // board and player, true if they win, false otherwise
int check_cat(char [], int); // the board and the number of turns taken
void check_move(char [], int, int); //the board and the attempted move location
int display(char [], int, string, string, int&); // displays the board as shown below with moves 
void reset_board(char []); // reload the board to empty
void player_move(char[], int, int);

int main() {
  string player1, player2;
  int turn;
  int win = 0;
  char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
  cout<<"Enter name for player 1: ";
  getline(cin, player1);
  cout<<"Enter name for player 2: ";
  getline(cin, player2);

  while(win == 0){
  srand(time(0));
  turn = rand() % 2 + 1;
  if (turn == 1){
    cout<<player1 << " 1 goes first, you are X"<<endl;
  }else if(turn == 2){
    cout<<player2 << " goes first, you are O"<<endl;
  }
  cout<<endl;
  display(board, turn, player1, player2, win);
    }
}

int display(char board[], int turn, string player1, string player2, int& win){
  int move = -1;
  int choice;
  while(win == 0){
  for(int i = 0; i < 9; i ++){
    cout<<board[i];
    if(i != 2 && i != 5 && i != 8){
      cout<<" | ";
    }
    if(i == 2 || i == 5){
      cout<<endl;
      cout<<"----------"<<endl;
}
    
  }
  cout<<endl<<endl;

  
    if(turn == 1){
    while(board[move]  == 'O'|| board[move] == 'X' || move < 0 || move > 9){
      cout<<player1<<"'s move(1-9): ";
      cin>>move;
      move--;
      }
    
      
    }else if (turn == 2){
      while(board[move]  == 'O'|| board[move] == 'X' || move < 0 || move > 9){
      cout<<player2<<"'s move(1-9): ";
      cin>>move;
      move--;
  
   }
    int win = check_win(board, player1, player2);
    if(win == 1){
      cout<<"Do you want to play again?: "<<endl;
      cout<<"1: Play Again"<<endl;
      cout<<"2: Quit"<<endl;
      cout<<"Choice: ";
      cin>>choice;
      if (choice == 1){
        win = 0;
        return win;
      }else if(choice == 2){
        win = 1;
        return win;
      }
    }
    int cat = check_cat(board, win);
      if(cat == 1){
      cout<<"Do you want to play again?: "<<endl;
      cout<<"1: Play Again"<<endl;
      cout<<"2: Quit"<<endl;
      cout<<"Choice: ";
      cin>>choice;
      if (choice == 1){
        win = 0;
        return win;
      }else if(choice == 2){
        win = 1;
        return win;
      }
      }
 }
    check_move(board, move, turn);
    if (turn == 1){
    turn = 2;
  }else if(turn == 2){
    turn = 1;
  }

    }
  }


void check_move(char board[], int move, int turn){
  if (turn == 1){
    board[move] = 'X';
  }else if(turn == 2){
    board[move] = 'O';
  }
}

int check_win(char board[], string player1, string player2){
  int win = 0;
  if(board[0] == 'X' && board[1] =='X' && board[2] =='X'){
    cout<<player1<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[0] =='O' && board[1] =='O' && board[2] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
   return win;
  }else if(board[0] =='X' && board[3] =='X' && board[6] =='X'){
    cout<<player1<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[0] =='O' && board[3] =='O' && board[6] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[2] =='X' && board[5] =='X' && board[8] =='X'){
    cout<<player1<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[2] =='O' && board[5] =='O' && board[8] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return true;
  }else if(board[6] =='X' && board[7] =='X' && board[8] =='X'){
    cout<<player1<<" has won"<<endl;
      win = 1;
    return win;
  }else if(board[6] =='O' && board[7] =='O' && board[8] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[3] =='X' && board[5] =='X' && board[6] =='X'){
    cout<<player1<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[3] =='O' && board[5] =='O' && board[6] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[0] =='X' && board[4] =='X' && board[8] =='X'){
    cout<<player1<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[0] =='O' && board[4] =='O' && board[8] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[6] =='X' && board[4] =='X' && board[2] =='X'){
    cout<<player1<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[6] =='O' && board[4] =='O' && board[2] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[1] =='O' && board[4] =='O' && board[7] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
  }else if(board[1] =='X' && board[4] =='X' && board[7] =='X'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
    }
  else if(board[5] =='X' && board[6] =='X' && board[7] =='X'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
    }
  else if(board[5] =='O' && board[6] =='O' && board[7] =='O'){
    cout<<player2<<" has won"<<endl;
    win = 1;
    return win;
    }
  else{
    win = 0;
    return win;
  }
}

int check_cat(char board[], int win){
  int num_turns = 0;
  int cat = 0;
  for(int i = 0; i < 9; i++){
    if(board[i] == 'O' ||board[i] == 'X' ){
      num_turns++;
    }
  }
  if (num_turns == 9 && win != 1){
    cat = 1;
    return cat;
  }else{
    cat = 0;
    return cat;
  }
}

void reset_board(char board[]){
  board[0] = '1';
  board[1] = '2';
  board[2] = '3';
  board[3] = '4';
  board[4] = '5';
  board[5] = '6';
  board[6] = '7';
  board[7] = '8';
  board[8] = '9';
}