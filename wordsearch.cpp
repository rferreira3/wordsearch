// Name: Rebecca Ferreira
// Assignment: Word Search
// Date last modified: September 2 2018 
//Creating a word search puzzle 

#include "uniformrandom.h"
#include "wordsearch.h"
#include "string"
#include<iostream>
#include <random>
using namespace std;

LetterMatrix going_up_(int x, int y, LetterMatrix board, string word, bool& fit);
LetterMatrix going_right__up_(int x, int y, LetterMatrix board, string word, bool& fit);
LetterMatrix going_right_(int x, int y, LetterMatrix board, string word, bool& fit);
LetterMatrix going_right__down(int x, int y, LetterMatrix board, string word, bool& fit);
LetterMatrix going_down_(int x, int y, LetterMatrix board, string word, bool& fit);
LetterMatrix going_left__down_(int x, int y, LetterMatrix board, string word, bool& fit);
LetterMatrix going_left_(int x, int y, LetterMatrix board, string word, bool& fit);
LetterMatrix going_left__up(int x, int y, LetterMatrix board, string word, bool& fit);


LetterMatrix make_key(const std::vector<std::string>& word_list,
                      int rows, int columns) {

    LetterMatrix board(rows,vector<char>(columns));
    for (auto i = 0; i < board.size(); i++) {
        for(auto j = 0; j < board[i].size(); j++)
        {
            board[i][j] = ' ';
        }
    }
    
    auto range =  UniformRandomGenerator(0, 19); //random number generator between 0 and 19
    auto random_direction_range = UniformRandomGenerator(0, 7);
    string word ;
    
    for (int r = 0; r <  word_list.size(); r++){ //goes until list runs out
        word = word_list[r]; //each word
        cout << word_list.size() << endl;
        enum direction {
            up, right_up,right,right_down,down,left_down,left,left_up //0-7
        };
        
    
        int random_row;
        int random_column;
        LetterMatrix backup = board; //backup board
        bool fit = false;
        while(fit == false){
            
             int random_direction = random_direction_range();
            auto directionEnum = static_cast<direction>(random_direction);
            random_row = range();
            random_column = range();
            
           // cout << random_row << ' ' << random_column << ' ' << random_direction << endl;
            switch(directionEnum) {
                case up:
                    board = going_up_(random_row, random_column, board, word, fit);
                    break;
                    
                case right_up:
                    board = going_right__up_(random_row, random_column, board, word, fit);
                    break;
                
                case right:
                    board = going_right_(random_row, random_column, board, word, fit);
                    break;
                
                case right_down:
                    board = going_right__down(random_row, random_column, board, word, fit);
                    break;
                
                case down:
                    board = going_down_(random_row, random_column, board, word, fit);
                    break;
                
                case left_down:
                    board = going_left__down_(random_row, random_column, board, word, fit);
                    break;
                    
                case left:
                   board = going_left_(random_row, random_column, board, word, fit);
                    break;
                    
                case left_up:
                   board = going_left__up(random_row, random_column, board, word, fit);
    
                    break;
            }
            if (fit) {
                backup = board;
            }
            else
            {
                board = backup;
            }
           
        }
            
        }


    return board;
    }
    
 LetterMatrix going_up_(int x, int y, LetterMatrix board, string word, bool& fit)
{
    
    for(int letter = 0; letter < word.length(); letter++){
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y]))
        {
            
            board[x][y] = word[letter];
            fit = true;
        }
        else {
            fit = false;
            break;
        }
        y++;
        
    }
        
    return board;
}
    
LetterMatrix going_right__up_(int x, int y, LetterMatrix board, string word, bool& fit)
{
    
    for(int letter = 0; letter < word.length(); letter++){
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y]))
        {
            board[x][y] = word[letter];
            fit = true;
        }
        else {
            fit = false;
            break;
        }
        
        x++;
        y++;
    }
    
    return board;
}

LetterMatrix going_right_(int x, int y, LetterMatrix board, string word, bool& fit)
{
    for(int letter = 0; letter < word.length(); letter++){
        
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y]))
        {
            board[x][y] = word[letter];
            fit = true;
        }
        else {
            fit = false;
            break;
        }
        
        x++;
        
    }
    
    return board;
}
LetterMatrix going_right__down(int x, int y, LetterMatrix board, string word, bool& fit)
{
    for(int letter = 0; letter < word.length(); letter++){
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y]))
        {
            board[x][y] = word[letter];
            fit = true;
        }
        else {
            fit = false;
            break;
        }
        
        x++;
        y--;
       
    }
    
    return board;
}

LetterMatrix going_down_(int x, int y, LetterMatrix board, string word, bool& fit)
{
    for(int letter = 0; letter < word.length(); letter++){
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y]))
        {
            board[x][y] = word[letter];
            fit = true;

        }
        else {
            fit = false;
            break;
        }
            y--;
        
    }
    return board;
}

LetterMatrix going_left__down_(int x, int y, LetterMatrix board, string word, bool& fit)
{
    for(int letter = 0; letter < word.length(); letter++){
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y]))
        {
            board[x][y] = word[letter];
            fit = true;

        }
        else {
            fit = false;
            break;
        }
        
            y--;
            x--;
        
    }
    
    return board;
}

LetterMatrix going_left_(int x, int y, LetterMatrix board, string word, bool& fit)
{
    for(int letter = 0; letter < word.length(); letter++){
        
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y])) //CHECK IF // NEVER GONNA BE SPACE
        {
            board[x][y] = word[letter];
            fit = true;

        }
        else {
           fit = false;
            break;
        }
            x--;
        
    }
    return board;
}

LetterMatrix going_left__up(int x, int y, LetterMatrix board, string word, bool& fit)
{
    for(int letter = 0; letter < word.length(); letter++){
        if((( x < board.size()) && (x >= 0 && y >= 0 )) && (board[x][y] == ' ' || word[letter] == board[x][y]))
        {
            board[x][y] = word[letter];
            fit = true;

        }
        else {
            fit = false;
            break;
        }
        x--;
        y++;
        
    }
    
    return board;
}



//  Constructs a puzzle from a given key.
//  key: the key from which the puzzle is to be created.
//  Returns the newly created corresponding word search puzzle.
LetterMatrix make_puzzle(const LetterMatrix& key) {
    auto board = key;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++)
        {
            if(key[i][j] == ' ')
            {
                board[i][j] = 'A' + rand()%26;
            }
        }
    }
    return board;
}
