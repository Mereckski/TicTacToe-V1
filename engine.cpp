#include "engine.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <stdexcept>
using namespace std;

#define bug cout<<"bug ";

engine::engine()
{
    srand(time(NULL));
}

void engine::setup()
{
    Board * game = new Board;

    game->total_turns = 0;
    //game->turn = new int;
    game->player = new int[2];
    //memory for board and grid
    game->grid = new char*[3];
    for(int x = 0; x < 3; x++){
        //for(int y = 0; y < 3; y++){
            game->grid[x] = new char[3];
        //}
    }
    //filling grid with empty space
    for(int x = 0; x < 3; x++){
       for(int y = 0; y < 3; y++){
            game->grid[x][y] = {' '};
        }
    }
    game->turn = rand()%2 + 1;
    cout << "Randomly selecting player...\n\n" << endl;
    checkTurn(game);
}

void engine::printGrid(Board * game)
{
    //horizontal line
    cout << "  ";
    for(int z = 0; z < 11; z++){cout<<"-";};
    cout<<endl;
    //Columns
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            cout << " | " << game->grid[y][x] ;
        }
        cout << " |" << endl;
        //in between lines and bottom
        cout << "  ";
        for(int z = 0; z < 11; z++){cout<<"-";};
        cout<<endl;
    }
}

void engine::checkTurn(Board * game)
{
    printGrid(game);
    if(game->total_turns > 8){
        cout << "Game is a tie" << endl;
        return;
    }
    if(winCheck(game) == true){closeGame(game);return;}
    if(game->turn % 2 == 0){
        cout << "Player 2 Turn!" << endl;
        turn(game);
    }else{
        cout << "Player 1 Turn!" << endl;
        turn(game);
    }
}

void engine::turn(Board * game)
{
    int x = 0;
    int y = 0;
    while(x < 1 || x > 4){
        cout << "Enter your x coordinate on the grid: ";
        cin >> x;
        if (cin.fail()){
         cout << "ERROR -- You did not enter an integer" << endl;;
         // get rid of failure state
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
    while(y < 1 || y > 4){
        cout << "Enter your y coordinate on the grid: ";
        cin >> y;
        if (cin.fail()){
         cout << "ERROR -- You did not enter an integer" << endl;;
         // get rid of failure state
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
    if(checkSpace(game, y, x) == true){
        game->total_turns++;
        updateGrid(game, y, x);
    }else{
        checkTurn(game);
    }
}

bool engine::checkSpace(Board * game, int x, int y)
{
    if(game->grid[x-1][y-1] == ' '){
        cout << "Space is empty\nUpdating Grid...\n" << endl;
        return true;
    }else{
        cout << "Space is full\nPlease enter empty coordinate" << endl;
        return false;
    }
}

void engine::updateGrid(Board * game, int x, int y)
{
    if(game->turn % 2 == 0){
        game->grid[x-1][y-1] = 'O';
        game->turn++;
        checkTurn(game);
    }else{
        game->grid[x-1][y-1] = 'X';
        game->turn++;
        checkTurn(game);
    }
}

bool engine::winCheck(Board * game)
{
    //X is 88 in ASCII so 88*3 = 264
    //O is 79 in ASCII so 79*3 = 237

    //check each column
    int igrid = 0;
    for(int x = 0; x < 3; x++){
        igrid = 0;
       for(int y = 0; y < 3; y++){
            igrid = igrid + game->grid[x][y];
        }
       if(igrid == 264){
            cout << "Player 1 Wins!" << endl;
            return true;
       }else if(igrid == 237){
            cout << "Player 2 Wins!" << endl;
            return true;
       }
    }
    //check each row
    for(int x = 0; x < 3; x++){
        igrid = 0;
       for(int y = 0; y < 3; y++){
            igrid = igrid + game->grid[y][x];
        }
       if(igrid == 264){
            cout << "Player 1 Wins!" << endl;
            return true;
       }else if(igrid == 237){
            cout << "Player 2 Wins!" << endl;
            return true;
       }
    }
    igrid = 0;
    int x1 = 0;
    int y1 = 0;
    //check diagonal from left to right
    for(int y = 0; y < 3; y++){
        igrid = igrid + game->grid[x1][y];
        x1++;
        if(igrid == 264){
            cout << "Player 1 Wins!" << endl;
            return true;
        }else if(igrid == 237){
            cout << "Player 2 Wins!" << endl;
            return true;
        }
    }
    //check diagonal from right to left
    igrid = 0;
    for(int x = 2; x >= 0; x--){
        igrid = igrid + game->grid[x][y1];
        y1++;
        if(igrid == 264){
            cout << "Player 1 Wins!" << endl;
            return true;
        }else if(igrid == 237){
            cout << "Player 2 Wins!" << endl;
            return true;
        }
    }
    return false;
}

void engine::closeGame(Board * game)
{
    delete game;
}

engine::~engine()
{

}
