// Name: Rebecca Ferreira
// Assignment: Word Search 2
// Date last modified: September 10

//Solve a word search

#include "uniformrandom.h"
#include "wordsearch.h"
#include "string"
#include<iostream>
#include <random>
using namespace std;

LetterMatrix going_up(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);
LetterMatrix going_right_up(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);
LetterMatrix going_right(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);
LetterMatrix going_right_down(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);
LetterMatrix going_down(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);
LetterMatrix going_left_down(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);
LetterMatrix going_left(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);
LetterMatrix going_left_up(int x, int y, string word, LetterMatrix puzzle, LetterMatrix key, bool& found);


LetterMatrix solve(const LetterMatrix& puzzle,
                   const std::vector<std::string> wordlist){

    LetterMatrix key(puzzle.size()  ,vector<char>(puzzle[0].size() ));
    
    for (auto i = 0; i < key.size(); i++) {
        for(auto j = 0; j < key[i].size(); j++)
        {
            key[i][j] = ' ';
        }
    }
    LetterMatrix backup = key;
    string word;
    bool found;
    found = false;
    for (int r = 0; r < wordlist.size(); r++)
    {
        found = false;
        word = wordlist[r];
        for (auto i = 0; i < puzzle.size() ; i++) //going through the board row by row
        {

            for(auto j = 0; j < puzzle[i].size() ; j++)
            {

                if (puzzle[i][j] == word[0])
                {
                    if(found == false)
                    {
                        key = going_up(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                    if(found == false)
                    {
                        key = going_right_up(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                    if(found == false)
                    {
                        key = going_right(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                    if(found == false)
                    {
                        key = going_right_down(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                    if(found == false)
                    {
                        key = going_down(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                    if(found == false)
                    {
                        key = going_left_down(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                    if(found == false)
                    {
                        key = going_left(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                    if(found == false)
                    {
                        key = going_left_up(i, j, word, puzzle, key, found);
                        if(found)
                        {
                            backup = key;
                            break;
                        }
                        else
                        {
                            key = backup;
                        }
                    }
                }//
            }
        }

    
        }
    return key;
    }



LetterMatrix going_up(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop
        
        if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size() ) || (puzzle[x][y] != word[k])) {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];

        }

        y++;
    }
    return key;
}

LetterMatrix going_right_up(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop

       if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size() ) || (puzzle[x][y] != word[k]))
       {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];
        }
        y++;
        x++;
        }

    return key;
}

LetterMatrix going_right(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop
        if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size() ) || (puzzle[x][y] != word[k])) {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];
        }
            x++;

    }
    return key;
}

LetterMatrix going_right_down(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop
        if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size() ) || (puzzle[x][y] != word[k])) {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];
        }
        x++;
        y--;
    }
    return key;
}


LetterMatrix going_down(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop
        if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size() ) || (puzzle[x][y] != word[k])) {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];
        }
        y--;


    }
    return key;
}

LetterMatrix going_left_down(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop
        if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size()) || (puzzle[x][y] != word[k])) {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];
        }
        y--;
        x--;

    }
    return key;
}

LetterMatrix going_left(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop
        if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size() ) || (puzzle[x][y] != word[k])) {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];
        }
                x--;

    }
    return key;
}

LetterMatrix going_left_up(int x, int y, string word, LetterMatrix puzzle ,LetterMatrix key, bool& found ){
    for (int k = 0; k < word.length(); k++){//letter loop

        if ((x < 0 || y < 0 ) || (( x >= puzzle.size() ) || y >= puzzle[0].size() ) || (puzzle[x][y] != word[k])) {
            found = false;
            break;
        }
        else
        {
            found = true;
            key[x][y] = puzzle[x][y];
        }
        x--;
        y++;
    }
    return key;
}


