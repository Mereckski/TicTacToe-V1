#include <iostream>
#include <stdio.h>
#include "engine.h"

using namespace std;

int main()
{
    bool exit = false;
    char enter;
    //engine::Board * newgame = new engine::Board;
    while(exit == false){
        engine * newmatch = new engine;
        newmatch->setup();
        cout << "exit? (y/n)";
        cin >> enter;
        if(enter == 'y'){
            exit = true;
        }else if( enter == 'n'){
        }else{
            cout << "assuming exit" << endl;
            exit = true;
        }
    }

    return 0;
}
